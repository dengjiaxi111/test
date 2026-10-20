#pragma once
#include <array>
#include <algorithm>
#include <cmath>
#include <limits>
#include <stdexcept>

namespace nav_components::omni {
constexpr int NX=4, NU=2, NP=18, N=75;
constexpr double DT=0.02;
using Vec = std::array<double, 2>;
using State = std::array<double, NX>;
using Params = std::array<double, NP>;
enum Parameter { XREF, YREF, VXREF, VYREF, TX, TY, DISTANCE, ANCHOR_X,
    ANCHOR_Y, GRAD_X, GRAD_Y, Q_POSITION, Q_VELOCITY, R_ACCELERATION,
    Q_CONTOUR, Q_OBSTACLE, SAFE_DISTANCE, WEIGHT_SCALE };
inline double norm(Vec v) { return std::hypot(v[0], v[1]); }
inline bool finite(Vec v) { return std::isfinite(v[0]) && std::isfinite(v[1]); }
inline double pathCurvature(Vec a,Vec b,Vec c) {
    const Vec u{b[0]-a[0],b[1]-a[1]},v{c[0]-b[0],c[1]-b[1]};
    const double nu=norm(u),nv=norm(v),chord=norm({c[0]-a[0],c[1]-a[1]});
    if(nu<1e-12||nv<1e-12) return 0;
    if(chord<1e-12) return std::numeric_limits<double>::infinity();
    return 2*std::abs(u[0]*v[1]-u[1]*v[0])/(nu*nv*chord);
}
inline double curvatureSpeed(double curvature,double lateral_acceleration,double epsilon) {
    return std::sqrt(lateral_acceleration/std::max(curvature,epsilon));
}
inline Vec limit(Vec v, double bound) {
    const double n=norm(v);
    if(n>bound && n>0) { v[0]*=bound/n; v[1]*=bound/n; }
    return v;
}
inline State step(State x, Vec a, double dt=DT) {
    return {x[0]+dt*x[2]+0.5*dt*dt*a[0], x[1]+dt*x[3]+0.5*dt*dt*a[1],
            x[2]+dt*a[0], x[3]+dt*a[1]};
}
inline Vec rotate(Vec v, double yaw) {
    return {std::cos(yaw)*v[0]-std::sin(yaw)*v[1],
            std::sin(yaw)*v[0]+std::cos(yaw)*v[1]};
}
inline bool fresh(double now, double stamp, double timeout) {
    // Separate /clock subscribers can briefly disagree by a few milliseconds.
    // Accept a small future offset without masking genuinely stale feedback.
    constexpr double kClockSkewSeconds = 0.01;
    const double age = now - stamp;
    return std::isfinite(stamp) && age >= -kClockSkewSeconds && age <= timeout;
}
// Prediction is a one-step ramp to the FINAL published target, then a hold.
// Alpha=0 ignores velocity measurements after initialization, but not pose validity.
class VelocityObserver {
public:
    explicit VelocityObserver(double alpha=0.8): alpha_(alpha) {
        if(!std::isfinite(alpha) || alpha<0 || alpha>1) throw std::invalid_argument("alpha outside [0,1]");
    }
    bool required() const { return alpha_>0; }
    void reset() { initialized_=false; estimate_={0,0}; sent_={0,0}; stamp_=0; }
    Vec update(double now, Vec measured, bool valid) {
        if(required() && !valid) throw std::runtime_error("velocity feedback required");
        if(!initialized_) {
            estimate_= valid ? measured : Vec{0,0}; sent_=estimate_; stamp_=now; initialized_=true;
            return estimate_;
        }
        const double ratio=std::clamp((now-stamp_)/DT,0.0,1.0);
        Vec predicted{estimate_[0]+ratio*(sent_[0]-estimate_[0]),
                      estimate_[1]+ratio*(sent_[1]-estimate_[1])};
        if(valid) for(int j=0;j<2;++j) predicted[j]=(1-alpha_)*predicted[j]+alpha_*measured[j];
        return predicted;
    }
    void record(double now, Vec fused, Vec sent) { estimate_=fused; sent_=sent; stamp_=now; initialized_=true; }
private:
    double alpha_, stamp_=0;
    bool initialized_=false;
    Vec estimate_{0,0}, sent_{0,0};
};
} // namespace nav_components::omni
