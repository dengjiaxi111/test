#include "nav_components/nmpc.hpp"
#include <chrono>
#include <limits>
#include "nav_components/layered_map_manager.hpp"
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <tf2/utils.h>
#include <algorithm>
#include <chrono>
#include <limits>
#include <stdexcept>
extern "C" {
#include "acados_solver_omni_nmpc.h"
}

namespace nav_components {
using omni::Vec;
using omni::State;
using nav_core::ControlResult;
namespace {
double seconds(const builtin_interfaces::msg::Time& stamp) {
    return stamp.sec + stamp.nanosec*1e-9;
}
bool validPose(const geometry_msgs::msg::Pose& p) {
    const auto& q=p.orientation;
    return std::isfinite(p.position.x) && std::isfinite(p.position.y) &&
           std::isfinite(p.position.z) && std::isfinite(q.x) && std::isfinite(q.y) &&
           std::isfinite(q.z) && std::isfinite(q.w) &&
           q.x*q.x+q.y*q.y+q.z*q.z+q.w*q.w>1e-12;
}
Vec transform(Vec p, const tf2::Transform& t) {
    const auto out=t*tf2::Vector3(p[0],p[1],0);
    return {out.x(),out.y()};
}
}
NMPC::~NMPC() {
    if(capsule_) {
        if(solver_created_) omni_nmpc_acados_free(capsule_);
        omni_nmpc_acados_free_capsule(capsule_);
    }
}
std::map<std::string,double NMPC::Config::*> NMPC::numericParameters() const {
    return {
        {"max_linear_vel",&Config::max_velocity}, {"max_linear_accel",&Config::max_acceleration},
        {"speed_profile.v_cruise",&Config::cruise},
        {"speed_profile.max_lateral_accel",&Config::lateral_acceleration},
        {"speed_profile.kappa_epsilon",&Config::curvature_epsilon},
        {"speed_profile.curvature_window_m",&Config::curvature_window},
        {"Q_position",&Config::q_position}, {"Q_velocity",&Config::q_velocity},
        {"R_linear",&Config::r_acceleration}, {"contouring_weight",&Config::q_contour},
        {"esdf_weight",&Config::q_obstacle}, {"esdf_safe_dist",&Config::safe_distance},
        {"terminal_multiplier",&Config::terminal_scale}, {"near_weight_multiplier",&Config::near_scale},
        {"capacitor_limit.v_safe",&Config::capacitor_safe}, {"capacitor_limit.v_low",&Config::capacitor_low},
        {"capacitor_limit.protect_scale",&Config::protect_scale}, {"capacitor_limit.low_scale",&Config::low_scale},
        {"capacitor_limit.filter_alpha",&Config::voltage_filter}
    };
}
bool NMPC::validConfig(const Config& c) {
    return c.max_velocity>0 && c.max_acceleration>0 && c.cruise>=0 &&
        c.lateral_acceleration>0 &&
        c.curvature_epsilon>0 && c.curvature_window>0 && c.q_position>=0 &&
        c.q_velocity>=0 && c.r_acceleration>0 && c.q_contour>=0 && c.q_obstacle>=0 &&
        c.safe_distance>=0 && c.near_scale>0 && c.terminal_scale>0 &&
        c.capacitor_low>=0 && c.capacitor_safe>=c.capacitor_low &&
        c.protect_scale>0 && c.protect_scale<=1 && c.low_scale>0 && c.low_scale<=1 &&
        c.voltage_filter>0 && c.voltage_filter<=1;
}
void NMPC::initialize(rclcpp::Node* node) {
    static_assert(OMNI_NMPC_NX==omni::NX && OMNI_NMPC_NU==omni::NU &&
                  OMNI_NMPC_NP==omni::NP && OMNI_NMPC_N==omni::N, "Regenerate omni solver");
    node_=node;
    auto number=[&](const std::string& name,double value) {
        if(!node_->has_parameter(name)) node_->declare_parameter(name,value);
        return node_->get_parameter(name).as_double();
    };
    auto string=[&](const std::string& name,const std::string& value) {
        if(!node_->has_parameter(name)) node_->declare_parameter(name,value);
        return node_->get_parameter(name).as_string();
    };
    for(auto [name,member]:numericParameters()) {
        config_.*member=number("nmpc."+name, config_.*member);
        if(!std::isfinite(config_.*member)) throw std::invalid_argument("non-finite "+name);
    }
    if(!validConfig(config_)) throw std::invalid_argument("invalid omni MPC configuration");
    alpha_=number("nmpc.odom_feedback_alpha",0.8);
    feedback_timeout_=number("nmpc.chassis_velocity_timeout_sec",0.15);
    filter_alpha_=number("nmpc.chassis_velocity_filter_alpha",1);
    pose_timeout_=number("nmpc.pose_timeout_sec",0.2);
    stop_speed_=number("nmpc.goal_stop_speed",0.05);
    if(!std::isfinite(alpha_) || alpha_<0 || alpha_>1 ||
       !std::isfinite(feedback_timeout_) || feedback_timeout_<=0 ||
       !std::isfinite(filter_alpha_) || filter_alpha_<=0 || filter_alpha_>1 ||
       !std::isfinite(pose_timeout_) || pose_timeout_<=0 ||
       !std::isfinite(stop_speed_) || stop_speed_<0) throw std::invalid_argument("invalid feedback parameters");
    odom_frame_=string("odom_frame","odom");
    map_frame_=string("map_frame","map");
    fake_frame_=string("base_frame","base_link_fake");
    const auto feedback_topic=string("nmpc.odom_topic","/Odometry/fake");
    const auto lio_topic=string("nmpc.lio_topic","/Odometry");
    observer_=std::make_unique<omni::VelocityObserver>(alpha_);
    tf_buffer_=std::make_unique<tf2_ros::Buffer>(node_->get_clock());
    tf_listener_=std::make_unique<tf2_ros::TransformListener>(*tf_buffer_);
    const auto qos=rclcpp::SensorDataQoS();
    feedback_sub_=node_->create_subscription<nav_msgs::msg::Odometry>(feedback_topic,qos,
        [this](nav_msgs::msg::Odometry::ConstSharedPtr msg) {
            std::lock_guard<std::mutex> lock(mutex_);
            const double now=node_->now().seconds(), stamp=seconds(msg->header.stamp);
            Vec value{msg->twist.twist.linear.x,msg->twist.twist.linear.y};
            if(msg->header.frame_id!=odom_frame_ || msg->child_frame_id!=fake_frame_ ||
               !omni::finite(value) || !omni::fresh(now,stamp,feedback_timeout_)) {
                RCLCPP_WARN_THROTTLE(node_->get_logger(),*node_->get_clock(),1000,
                    "Omni feedback sample rejected: frame=%s child=%s age=%.6f limit=%.3f finite=%d",
                    msg->header.frame_id.c_str(),msg->child_frame_id.c_str(),
                    now-stamp,feedback_timeout_,omni::finite(value));
                have_feedback_=false; return;
            }
            if(have_feedback_ && now>=feedback_received_ && stamp<=feedback_stamp_) return;
            if(have_feedback_ && omni::fresh(now,feedback_received_,feedback_timeout_))
                for(int j=0;j<2;++j) value[j]=filter_alpha_*value[j]+(1-filter_alpha_)*feedback_[j];
            feedback_=value; feedback_stamp_=stamp; feedback_received_=now; have_feedback_=true;
        });
    lio_sub_=node_->create_subscription<nav_msgs::msg::Odometry>(lio_topic,qos,
        [this](nav_msgs::msg::Odometry::ConstSharedPtr msg) {
            std::lock_guard<std::mutex> lock(mutex_);
            const double now=node_->now().seconds();
            if(msg->header.frame_id!=odom_frame_ || msg->child_frame_id!="base_link" ||
               !validPose(msg->pose.pose) || !omni::fresh(now,seconds(msg->header.stamp),pose_timeout_)) {
                have_lio_=false; return;
            }
            if(have_lio_ && seconds(msg->header.stamp)<=seconds(lio_.header.stamp) &&
               now>=lio_received_) return;
            lio_=*msg; lio_received_=now; have_lio_=true;
        });
    capacitor_sub_=node_->create_subscription<robots_msgs::msg::ChassisOdom>(
        "/ChassisOdom",qos,[this](robots_msgs::msg::ChassisOdom::ConstSharedPtr msg) {
            std::lock_guard<std::mutex> lock(mutex_);
            if(std::isfinite(msg->capacitor_voltage) && msg->capacitor_voltage>=0) {
                voltage_=have_voltage_ ? config_.voltage_filter*msg->capacitor_voltage+
                    (1-config_.voltage_filter)*voltage_ : msg->capacitor_voltage;
                have_voltage_=true;
            }
        });
    predicted_pub_=node_->create_publisher<nav_msgs::msg::Path>("nmpc/predicted_path",1);
    measured_pub_=node_->create_publisher<geometry_msgs::msg::TwistStamped>("nmpc/measured_velocity",10);
    fused_pub_=node_->create_publisher<geometry_msgs::msg::TwistStamped>("nmpc/fused_velocity",10);
    command_pub_=node_->create_publisher<geometry_msgs::msg::TwistStamped>("nmpc/command_velocity",10);
    parameters_callback_=node_->add_on_set_parameters_callback(
        [this](const std::vector<rclcpp::Parameter>& values) {
            std::lock_guard<std::mutex> lock(mutex_);
            rcl_interfaces::msg::SetParametersResult result; result.successful=false;
            auto next=config_;
            const auto members=numericParameters();
            for(const auto& p:values) {
                if(p.get_name().rfind("nmpc.",0)!=0) continue;
                const auto found=members.find(p.get_name().substr(5));
                if(found==members.end()) { result.reason="Feedback/model/interface parameters require restart"; return result; }
                if(p.get_type()!=rclcpp::ParameterType::PARAMETER_DOUBLE || !std::isfinite(p.as_double())) {
                    result.reason="Expected finite double"; return result;
                }
                next.*(found->second)=p.as_double();
            }
            if(!validConfig(next)) { result.reason="Invalid limits or weights"; return result; }
            config_=next; result.successful=true; return result;
        });
    capsule_=omni_nmpc_acados_create_capsule();
    if(!capsule_ || omni_nmpc_acados_create(capsule_)!=0) throw std::runtime_error("omni solver creation failed");
    solver_created_=true;
    RCLCPP_INFO(node_->get_logger(),"Omni MPC NX=4 NU=2 N=75 dt=0.02 alpha=%.3f feedback_required=%d",
                alpha_,alpha_>0);
}
void NMPC::setPath(const nav_msgs::msg::Path& path) {
    std::lock_guard<std::mutex> lock(mutex_);
    path_=path; nearest_=0; warm_=false; // Moving replans preserve observer and sent velocity.
}
void NMPC::reset() {
    std::lock_guard<std::mutex> lock(mutex_);
    observer_->reset(); warm_=false; last_time_=0; last_sent_={0,0}; nearest_=0;
    have_transform_=false;
    solve_retry_started_=-1;
    if(solver_created_) omni_nmpc_acados_reset(capsule_,1);
}
void NMPC::pauseExecution() {
    std::lock_guard<std::mutex> lock(mutex_);
    observer_->reset();warm_=false;last_time_=0;last_sent_={0,0};solve_retry_started_=-1;
}
ControlResult NMPC::stop(geometry_msgs::msg::Twist& command) {
    command=geometry_msgs::msg::Twist(); observer_->reset(); warm_=false; last_sent_={0,0}; last_time_=0;
    return ControlResult::FAILED;
}
void NMPC::setExecutionConstraints(nav_core::hole_exec::MotionConstraints value) {
    std::lock_guard<std::mutex> lock(mutex_);execution_=std::move(value);
}
double NMPC::executionMeasuredSpeed() {
    std::lock_guard<std::mutex> lock(mutex_);
    if(!have_feedback_||!omni::fresh(node_->now().seconds(),feedback_received_,feedback_timeout_))
        return std::numeric_limits<double>::quiet_NaN();
    return omni::norm(feedback_);
}
std::vector<NMPC::Reference> NMPC::reference(const std::vector<Vec>& input, Vec position) {
    std::vector<Reference> refs;
    std::vector<Vec> pts;
    for(auto p:input) if(pts.empty()||std::hypot(p[0]-pts.back()[0],p[1]-pts.back()[1])>1e-10) pts.push_back(p);
    if(pts.empty()) return refs;
    if(pts.size()==1) return std::vector<Reference>(omni::N+1,{{pts[0][0],pts[0][1],0,0},{1,0},0,0});
    std::vector<double> arc(pts.size(),0);
    for(size_t i=1;i<pts.size();++i) arc[i]=arc[i-1]+std::hypot(pts[i][0]-pts[i-1][0],pts[i][1]-pts[i-1][1]);
    double best=std::numeric_limits<double>::infinity(), progress=0;
    auto search=[&](size_t begin,size_t end) {
        for(size_t i=begin;i<end;++i) {
            const Vec delta{pts[i+1][0]-pts[i][0],pts[i+1][1]-pts[i][1]};
            const double length=arc[i+1]-arc[i];
            const double t=std::clamp(((position[0]-pts[i][0])*delta[0]+(position[1]-pts[i][1])*delta[1])/(length*length),0.0,1.0);
            const double d=std::hypot(position[0]-pts[i][0]-t*delta[0],position[1]-pts[i][1]-t*delta[1]);
            if(d<best) { best=d; progress=arc[i]+t*length; nearest_=i; }
        }
    };
    const size_t start=std::min(nearest_,pts.size()-2);
    search(start,std::min(pts.size()-1,start+30));
    if(best>2) search(0,pts.size()-1);
    if(std::hypot(position[0]-pts.back()[0],position[1]-pts.back()[1])<=tolerance_) progress=arc.back();
    size_t idx=nearest_;
    for(int k=0;k<=omni::N;++k) {
        while(idx+1<pts.size()-1 && arc[idx+1]<=progress) ++idx;
        const double remaining=std::max(0.0,arc.back()-progress);
        const double length=arc[idx+1]-arc[idx];
        Vec tangent{(pts[idx+1][0]-pts[idx][0])/length,(pts[idx+1][1]-pts[idx][1])/length};
        const double ratio=std::clamp((progress-arc[idx])/length,0.0,1.0);
        Vec point{pts[idx][0]+ratio*(pts[idx+1][0]-pts[idx][0]),pts[idx][1]+ratio*(pts[idx+1][1]-pts[idx][1])};
        double curvature=0;
        for(size_t j=idx;j+2<pts.size() && arc[j]-arc[idx]<config_.curvature_window;++j) {
            curvature=std::max(curvature,omni::pathCurvature(pts[j],pts[j+1],pts[j+2]));
        }
        double cap=config_.max_velocity;
        if(execution_.enabled)cap=std::min(cap,nav_core::hole_exec::previewLimit(progress,
            execution_.base_speed,execution_.regions,execution_.braking,execution_.latency,execution_.stop_arc));
        double speed=std::min({config_.cruise,cap,
            omni::curvatureSpeed(curvature,config_.lateral_acceleration,config_.curvature_epsilon),
            std::sqrt(2*config_.max_acceleration*remaining)});
        if(remaining<=1e-6) speed=0;
        // Integrate arc progress with this speed: position and velocity share the same time grid.
        speed=std::min(speed,remaining/omni::DT);
        refs.push_back({{point[0],point[1],speed*tangent[0],speed*tangent[1]},tangent,progress,cap});
        progress=std::min(arc.back(),progress+omni::DT*speed);
    }
    return refs;
}
bool NMPC::solve(const State& x0, const std::vector<Reference>& refs,
                 const tf2::Transform& to_map, double elapsed, double acceleration, Vec& result) {
    if(!warm_) omni_nmpc_acados_reset(capsule_,1);
    auto cfg=omni_nmpc_acados_get_nlp_config(capsule_);
    auto dims=omni_nmpc_acados_get_nlp_dims(capsule_);
    auto in=omni_nmpc_acados_get_nlp_in(capsule_);
    auto out=omni_nmpc_acados_get_nlp_out(capsule_);
    auto manager=std::dynamic_pointer_cast<LayeredMapManager>(map_);
    auto esdf=std::dynamic_pointer_cast<EsdfMap>(map_);
    if(manager) esdf=manager->getEsdf();
    if(config_.q_obstacle<=0) esdf.reset();
    const auto old=controls_;
    State seed=x0;
    const double shift=std::clamp(elapsed/omni::DT,0.0,double(omni::N-1));
    for(int i=0;i<=omni::N;++i) {
        omni::Params p{refs[i].x[0],refs[i].x[1],refs[i].x[2],refs[i].x[3],
            refs[i].tangent[0],refs[i].tangent[1],10,seed[0],seed[1],0,0,
            config_.q_position,config_.q_velocity,config_.r_acceleration,config_.q_contour,
            esdf ? config_.q_obstacle : 0,config_.safe_distance,1};
        const int near_end=omni::N/4;
        if(i<near_end) p[omni::WEIGHT_SCALE]=1+(config_.near_scale-1)*double(near_end-i)/near_end;
        if(i==omni::N) p[omni::WEIGHT_SCALE]=config_.terminal_scale;
        if(esdf) {
            const Vec anchor=warm_ ? Vec{0.7*refs[i].x[0]+0.3*seed[0],0.7*refs[i].x[1]+0.3*seed[1]}
                                   : Vec{refs[i].x[0],refs[i].x[1]};
            const Vec query=transform(anchor,to_map);
            double distance,gx,gy;
            if(!esdf->getDistanceAndGradient(query[0],query[1],distance,gx,gy) ||
               !std::isfinite(distance) || !std::isfinite(gx) || !std::isfinite(gy)) return false;
            // Scalar field gradient transforms by R^T, not by the point transform.
            const auto grad=to_map.getBasis().transpose()*tf2::Vector3(gx,gy,0);
            p[omni::DISTANCE]=distance; p[omni::ANCHOR_X]=anchor[0]; p[omni::ANCHOR_Y]=anchor[1];
            p[omni::GRAD_X]=grad.x(); p[omni::GRAD_Y]=grad.y();
        }
        omni_nmpc_acados_update_params(capsule_,i,p.data(),omni::NP);
        ocp_nlp_out_set(cfg,dims,out,in,i,"x",seed.data());
        if(i>0) {
            // Redundant component bounds retain the circle's exact feasible set,
            // but stay linear as the FSM's stopping limit tends to zero.
            const double cap=refs[i].limit;
            double lower[2]={-cap,-cap}, upper[2]={cap,cap};
            ocp_nlp_constraints_model_set(cfg,dims,in,out,i,"lbx",lower);
            ocp_nlp_constraints_model_set(cfg,dims,in,out,i,"ubx",upper);
        }
        if(i<omni::N) {
            Vec a{(refs[i+1].x[2]-seed[2])/omni::DT,
                  (refs[i+1].x[3]-seed[3])/omni::DT};
            if(warm_) {
                const double index=std::min(double(omni::N-1),i+shift);
                const int j=int(index), next=std::min(j+1,omni::N-1);
                for(int c=0;c<2;++c) a[c]=(1-(index-j))*old[j][c]+(index-j)*old[next][c];
            }
            a=omni::limit(a,acceleration);
            const Vec v=omni::limit({seed[2]+omni::DT*a[0],seed[3]+omni::DT*a[1]},config_.max_velocity);
            a={(v[0]-seed[2])/omni::DT,(v[1]-seed[3])/omni::DT};
            ocp_nlp_out_set(cfg,dims,out,in,i,"u",a.data());
            double upper[2]={refs[i].limit*refs[i].limit,acceleration*acceleration};
            ocp_nlp_constraints_model_set(cfg,dims,in,out,i,"uh",i==0 ? upper+1 : upper);
            seed=omni::step(seed,a);
        } else {
            double upper=refs[i].limit*refs[i].limit;
            ocp_nlp_constraints_model_set(cfg,dims,in,out,i,"uh",&upper);
        }
    }
    State initial=x0;
    ocp_nlp_constraints_model_set(cfg,dims,in,out,0,"lbx",initial.data());
    ocp_nlp_constraints_model_set(cfg,dims,in,out,0,"ubx",initial.data());
    // A single RTI step only enforces linearized circle constraints.
    // Special stopping limits approach zero: squared speed constraints need more
    // linearization passes there. Preserve both the 12 ms budget and norm checks.
    const auto start=std::chrono::steady_clock::now();
    bool feasible=false;
    for(int pass=0;pass<(execution_.enabled?10:5);++pass) {
        if(pass>0 && std::chrono::duration<double>(std::chrono::steady_clock::now()-start).count()>0.012) break;
        const int status=omni_nmpc_acados_solve(capsule_);
        if(status!=0) {
            RCLCPP_WARN_THROTTLE(node_->get_logger(),*node_->get_clock(),1000,
                                "Omni solver status=%d pass=%d",status,pass);
            return false;
        }
        feasible=true;
        for(int i=0;i<=omni::N;++i) {
            ocp_nlp_out_get(cfg,dims,out,i,"x",predicted_[i].data());
            for(double value:predicted_[i]) if(!std::isfinite(value)) return false;
            if(i>0 && omni::norm({predicted_[i][2],predicted_[i][3]})>refs[i].limit+1e-3) feasible=false;
            if(i<omni::N) {
                ocp_nlp_out_get(cfg,dims,out,i,"u",controls_[i].data());
                if(!omni::finite(controls_[i])) return false;
                if(omni::norm(controls_[i])>acceleration+1e-3) feasible=false;
            }
        }
        if(feasible) break;
    }
    if(!feasible) {
        double vmax=0, amax=0, excess=-1, required=0; int stage=-1;
        for(int i=0;i<omni::N;++i) {
            vmax=std::max(vmax,omni::norm({predicted_[i+1][2],predicted_[i+1][3]}));
            amax=std::max(amax,omni::norm(controls_[i]));
            const double violation=omni::norm({predicted_[i+1][2],predicted_[i+1][3]})-refs[i+1].limit;
            if(violation>excess){excess=violation;stage=i+1;required=refs[i+1].limit;}
        }
        RCLCPP_WARN_THROTTLE(node_->get_logger(),*node_->get_clock(),1000,
                            "Omni norm check failed: v=%.6f a=%.6f stage=%d limit=%.6f excess=%.6f stop=%.3f",
                            vmax,amax,stage,required,excess,execution_.stop_arc.value_or(-1.));
        return false;
    }
    for(int i=0;i<omni::N;++i) {
        auto expected=omni::step(predicted_[i],controls_[i]);
        for(int j=0;j<omni::NX;++j) if(std::abs(expected[j]-predicted_[i+1][j])>1e-4) return false;
    }
    if(!predictionSafe(to_map)) return false;
    if(execution_.enabled&&execution_.stop_arc) {
        nav_core::hole_exec::Polyline line(execution_.path);
        for(int i=1;i<=omni::N;++i) {
            auto q=transform({predicted_[i][0],predicted_[i][1]},to_map);
            const auto projected=line.project({q[0],q[1]},std::max(0.0,refs[i].arc-0.3),
                std::min(line.length(),refs[i].arc+0.3));
            if(projected.arc>*execution_.stop_arc+1e-5)return false;
        }
    }
    result={x0[2]+omni::DT*controls_[0][0],x0[3]+omni::DT*controls_[0][1]};
    warm_=true;
    return true;
}
bool NMPC::predictionSafe(const tf2::Transform& to_map) const {
    if(!map_) return true; // Allows the isolated model harness with no map.
    const double spacing=std::max(0.01,map_->resolution()*0.5);
    for(int i=1;i<=omni::N;++i) {
        const Vec from=transform({predicted_[i-1][0],predicted_[i-1][1]},to_map);
        const Vec to=transform({predicted_[i][0],predicted_[i][1]},to_map);
        const int count=std::max(1,int(std::ceil(std::hypot(to[0]-from[0],to[1]-from[1])/spacing)));
        for(int j=1;j<=count;++j) {
            const auto q=map_->query(from[0]+double(j)/count*(to[0]-from[0]),
                                     from[1]+double(j)/count*(to[1]-from[1]));
            if(!q.valid || q.occupied) return false;
        }
    }
    return true;
}
ControlResult NMPC::computeVelocity(const geometry_msgs::msg::PoseStamped& pose,
                                    geometry_msgs::msg::Twist& command) {
    std::lock_guard<std::mutex> lock(mutex_);
    command=geometry_msgs::msg::Twist();
    const double now=node_->now().seconds();
    const double elapsed=last_time_>0 ? now-last_time_ : omni::DT;
    // Execution leases and sensor stamps use the node clock, including Gazebo /clock.
    if(execution_.enabled&&(!execution_.allowed||now>execution_.valid_until))return stop(command);
    if(!solver_created_ || path_.poses.empty() || !validPose(pose.pose) ||
       !have_lio_ || !omni::fresh(now,lio_received_,pose_timeout_) ||
       !omni::fresh(now,seconds(lio_.header.stamp),pose_timeout_) ||
       elapsed<0 || elapsed>0.1) {
        RCLCPP_WARN_THROTTLE(node_->get_logger(),*node_->get_clock(),1000,
            "Omni input invalid: solver=%d path=%zu pose=%d lio=%d lio_receive_age=%.3f lio_stamp_age=%.3f elapsed=%.3f",
            solver_created_,path_.poses.size(),validPose(pose.pose),have_lio_,
            have_lio_ ? now-lio_received_ : -1.0,
            have_lio_ ? now-seconds(lio_.header.stamp) : -1.0,elapsed);
        return stop(command);
    }
    const bool measured_valid=have_feedback_ &&
        omni::fresh(now,feedback_received_,feedback_timeout_) && omni::fresh(now,feedback_stamp_,feedback_timeout_);
    if(alpha_>0 && !measured_valid) {
        RCLCPP_WARN_THROTTLE(node_->get_logger(),*node_->get_clock(),1000,
            "Omni feedback invalid: have=%d receive_age=%.3f stamp_age=%.3f limit=%.3f",
            have_feedback_,have_feedback_ ? now-feedback_received_ : -1.0,
            have_feedback_ ? now-feedback_stamp_ : -1.0,feedback_timeout_);
        return stop(command);
    }
    tf2::Transform to_map; to_map.setIdentity();
    try {
        if(map_frame_!=odom_frame_) {
            const auto msg=tf_buffer_->lookupTransform(map_frame_,odom_frame_,tf2::TimePointZero);
            tf2::fromMsg(msg.transform,to_map);
        }
    } catch(const tf2::TransformException& error) {
        RCLCPP_WARN_THROTTLE(node_->get_logger(),*node_->get_clock(),1000,
            "Omni map TF invalid: %s",error.what());
        return stop(command);
    }
    if(have_transform_ && ((to_map.getOrigin()-last_odom_to_map_.getOrigin()).length()>0.3 ||
       to_map.getRotation().angleShortestPath(last_odom_to_map_.getRotation())>0.2)) {
        warm_=false; nearest_=0;
    }
    last_odom_to_map_=to_map; have_transform_=true;
    tf2::Transform path_to_odom;
    if(path_.header.frame_id==map_frame_) path_to_odom=to_map.inverse();
    else if(path_.header.frame_id==odom_frame_) path_to_odom.setIdentity();
    else return stop(command);
    std::vector<Vec> points;
    for(const auto& p:path_.poses) {
        if(!std::isfinite(p.pose.position.x) || !std::isfinite(p.pose.position.y) ||
           (!p.header.frame_id.empty() && p.header.frame_id!=path_.header.frame_id)) return stop(command);
        auto point=transform({p.pose.position.x,p.pose.position.y},path_to_odom);
        if(points.empty() || std::hypot(point[0]-points.back()[0],point[1]-points.back()[1])>1e-6)
            points.push_back(point);
    }
    if(points.empty()) return stop(command);
    const Vec fused=observer_->update(now,feedback_,measured_valid);
    State state{lio_.pose.pose.position.x,lio_.pose.pose.position.y,fused[0],fused[1]};
    const double goal_distance=std::hypot(state[0]-points.back()[0],state[1]-points.back()[1]);
    const Vec stop_velocity=alpha_>0 ? feedback_ : fused;
    if(goal_distance<=tolerance_ && omni::norm(stop_velocity)<=stop_speed_) {
        stop(command); return ControlResult::SUCCEEDED;
    }
    double acceleration=execution_.enabled?std::min(config_.max_acceleration,execution_.acceleration):config_.max_acceleration;
    if(have_voltage_) {
        if(voltage_<config_.capacitor_low) acceleration*=config_.low_scale;
        else if(voltage_<config_.capacitor_safe) acceleration*=config_.protect_scale;
    }
    Vec sent;
    if(omni::norm(fused)>config_.max_velocity) {
        sent=omni::limit(fused,std::max(0.0,omni::norm(fused)-acceleration*omni::DT));
        sent=omni::limit(sent,config_.max_velocity); // Hard protection beats ramp smoothness.
        warm_=false;
    } else {
        const auto refs=reference(points,{state[0],state[1]});
        if(!solve(state,refs,to_map,elapsed,acceleration,sent)) {
            if(execution_.enabled) {
                // A newly installed low-speed boundary may initially be infeasible
                // with measured residual speed. Publish only zero while rebuilding
                // from fresh measurements; persistent rejection remains FAILED.
                if(solve_retry_started_<0)solve_retry_started_=now;
                stop(command);
                return now-solve_retry_started_<std::min(.2,pose_timeout_*.5)?ControlResult::RUNNING:ControlResult::FAILED;
            }
            warm_=false;
            sent=omni::limit(last_sent_,std::max(0.0,omni::norm(last_sent_)-acceleration*std::min(elapsed,omni::DT)));
            RCLCPP_WARN_THROTTLE(node_->get_logger(),*node_->get_clock(),1000,"Omni solve/constraint/map check failed; ramping to stop");
        }
    }
    solve_retry_started_=-1;
    sent=omni::limit(sent,config_.max_velocity);
    command.linear.x=sent[0]; command.linear.y=sent[1];
    observer_->record(now,fused,sent); last_sent_=sent; last_time_=now;
    publishObservation(state,feedback_,measured_valid,sent);
    if(warm_) {
        nav_msgs::msg::Path out; out.header.frame_id=odom_frame_; out.header.stamp=node_->now();
        for(const auto& x:predicted_) {
            geometry_msgs::msg::PoseStamped p; p.header=out.header;
            p.pose.position.x=x[0]; p.pose.position.y=x[1]; p.pose.orientation.w=1;
            out.poses.push_back(p);
        }
        predicted_pub_->publish(out);
    }
    return ControlResult::RUNNING;
}
void NMPC::publishObservation(const State& x,Vec measured,bool valid,Vec command) {
    geometry_msgs::msg::TwistStamped msg;
    msg.header.frame_id=fake_frame_; msg.header.stamp=node_->now();
    if(valid) { msg.twist.linear.x=measured[0]; msg.twist.linear.y=measured[1]; measured_pub_->publish(msg); }
    msg.twist.linear.x=x[2]; msg.twist.linear.y=x[3]; fused_pub_->publish(msg);
    msg.twist.linear.x=command[0]; msg.twist.linear.y=command[1]; command_pub_->publish(msg);
}
} // namespace nav_components
