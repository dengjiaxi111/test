#pragma once
#include "nav_core/hole_execution_types.hpp"

namespace nav_core::hole_exec {
// 上坡区域拥有速度输出，离开区域或安全许可撤销才交还。
// 真实无进展由通行状态机计时，不把低于目标速度等同于执行失败。
class SlopeSpeedTakeover {
public:
    struct Result {bool active=false,failed=false;double speed=0;};
    void reset(){key_.clear();last_=-1;sent_=0;}
    Result update(const Config& c,const std::string& key,double now,double measured,
                  double normal_speed,double minimum,bool allowed) {
        (void)minimum; // 门限只用于监测，不决定坡中控制权。
        if(!allowed||!std::isfinite(now)||!std::isfinite(measured)||
           !std::isfinite(normal_speed)||now<last_) {reset();return {};}
        if(key_!=key){reset();key_=key;sent_=std::clamp(std::max(measured,normal_speed),0.0,c.boost_speed);}
        const double dt=last_<0?.02:std::clamp(now-last_,0.0,0.1);last_=now;
        sent_=std::min(c.boost_speed,sent_+c.boost_acceleration*dt);
        return {true,false,sent_};
    }
private:
    std::string key_;
    double last_=-1,sent_=0;
};
} // namespace nav_core::hole_exec
