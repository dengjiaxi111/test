// 仅测试副本的在线参数接口；调用原NMPC现有数值参数，不改其计算。
#include "nav_components/slopehole_ros_adapter.hpp"
#include <fstream>
#include <cstdio>
namespace nav_components {
using namespace nav_core::hole_exec;
void SlopeHoleRosAdapter::initializeTuning() {
    using Member=double Config::*;
    const std::map<std::string,Member> fields{{"flat_speed",&Config::flat_speed},{"boost_speed",&Config::boost_speed},
        {"minimum_entry_speed",&Config::minimum_entry_speed},{"minimum_slope_speed",&Config::minimum_slope_speed},
        {"restore_speed",&Config::restore_speed}};
    for(const auto& item:fields)node_->declare_parameter("hole_runtime."+item.first,config_.*item.second);
    tuning_save_file_=node_->declare_parameter("hole_runtime.save_file",std::string("sim/runtime_tuning.yaml"));
    tuning_service_=node_->create_service<rcl_interfaces::srv::SetParametersAtomically>("hole_runtime/set_parameters_atomically",
        [this,fields](const std::shared_ptr<rcl_interfaces::srv::SetParametersAtomically::Request> req,
                     std::shared_ptr<rcl_interfaces::srv::SetParametersAtomically::Response> res) {
            try {
                if(req->parameters.empty())throw std::runtime_error("empty tuning request");
                if(req->parameters.size()==1&&req->parameters[0].name=="save") {
                    const rclcpp::Parameter save=rclcpp::Parameter::from_parameter_msg(req->parameters[0]);
                    if(save.get_type()!=rclcpp::ParameterType::PARAMETER_BOOL||!save.as_bool())throw std::runtime_error("save expects true");
                    const auto tmp=tuning_save_file_+".tmp";
                    std::ofstream file(tmp);file<<"# 隔离仿真显式保存的在线调参；速度m/s，加速度m/s^2。\n";
                    for(const auto& f:fields)file<<f.first<<": "<<config_.*f.second<<"\n";
                    file<<"max_linear_accel: "<<node_->get_parameter("nmpc.max_linear_accel").as_double()<<"\n";
                    file.close();if(!file||std::rename(tmp.c_str(),tuning_save_file_.c_str())!=0)throw std::runtime_error("cannot save test tuning file");
                    res->result.successful=true;res->result.reason="saved "+tuning_save_file_;return;
                }
                auto next=config_;
                double acceleration=node_->get_parameter("nmpc.max_linear_accel").as_double();
                std::set<std::string> seen;
                for(const auto& msg:req->parameters) {
                    const auto p=rclcpp::Parameter::from_parameter_msg(msg);
                    if(!seen.insert(p.get_name()).second||p.get_type()!=rclcpp::ParameterType::PARAMETER_DOUBLE||
                        !std::isfinite(p.as_double())||p.as_double()<0||
                        (p.as_double()==0&&p.get_name()!="minimum_entry_speed"&&p.get_name()!="minimum_slope_speed"))throw std::runtime_error("expected distinct finite positive numeric tuning values");
                    if(p.get_name()=="max_linear_accel") {
                        if(p.as_double()>100.)throw std::runtime_error("simulation acceleration range: (0,100] m/s^2");
                        acceleration=p.as_double();
                    }else {
                        const auto f=fields.find(p.get_name());
                        if(f==fields.end()||p.as_double()>3.5)throw std::runtime_error("unsupported field or simulation speed outside (0,3.5] m/s");
                        next.*f->second=p.as_double();
                    }
                }
                next.acceleration_limit=acceleration; // 同步进度预算；实际优化约束仍是原NMPC参数。
                SlopeHoleController validate(next);
                auto speeds=core_.plan().speeds;
                std::vector<rclcpp::Parameter> update,old;
                for(const auto& f:fields)update.emplace_back("hole_runtime."+f.first,next.*f.second);
                double max_speed=node_->get_parameter("nmpc.max_linear_vel").as_double();
                for(const auto& f:fields)max_speed=std::max(max_speed,next.*f.second);
                update.emplace_back("nmpc.max_linear_vel",max_speed);update.emplace_back("nmpc.max_linear_accel",acceleration);
                for(const auto& p:update)old.push_back(node_->get_parameter(p.get_name()));
                const auto accepted=node_->set_parameters_atomically(update);
                if(!accepted.successful) {
                    // 原NMPC预提交回调会改缓存，后续回调拒绝时显式恢复原值。
                    if(!node_->set_parameters_atomically(old).successful){invalidate("runtime tuning rollback failed");}
                    throw std::runtime_error("tuning rejected: "+accepted.reason);
                }
                core_.applyRuntimeConfig(next,std::move(speeds));config_=next;speed_takeover_.reset();takeover_authorized_=false;publishPlan();
                res->result.successful=true;res->result.reason="applied; traversal history and structure requests preserved";
            }catch(const std::exception& e){res->result.successful=false;res->result.reason=e.what();}
        });
}
}
