// 特殊地形规划约束接口
//
// 该接口只描述规划约束，不包含任何具体地形识别或控制状态机。
// 狗洞等后续模块可以实现它，并注入 SimplePlanner。

#pragma once

#include <Eigen/Dense>
#include <memory>

namespace nav_core {

class SpecialTerrainConstraint {
public:
    using Ptr = std::shared_ptr<SpecialTerrainConstraint>;

    virtual ~SpecialTerrainConstraint() = default;

    // A* 扩展约束。坐标均为 map 坐标系下的世界坐标（米）。
    virtual bool isTransitionAllowed(double from_x, double from_y,
                                     double to_x, double to_y) const {
        (void)from_x;
        (void)from_y;
        (void)to_x;
        (void)to_y;
        return true;
    }

    // A* 边的非负附加代价。返回负数时会被规划器按 0 处理。
    virtual double transitionCost(double from_x, double from_y,
                                  double to_x, double to_y) const {
        (void)from_x;
        (void)from_y;
        (void)to_x;
        (void)to_y;
        return 0.0;
    }

    // B 样条扩展约束。
    // gradient 的行数为 end_index - begin_index；实现方应把梯度累加到
    // gradient.row(control_point_index - begin_index)，并返回已经加权的代价。
    virtual double addOptimizationCost(const Eigen::MatrixXd& control_points,
                                       int begin_index,
                                       int end_index,
                                       double spline_interval,
                                       Eigen::MatrixXd& gradient) const {
        (void)control_points;
        (void)begin_index;
        (void)end_index;
        (void)spline_interval;
        (void)gradient;
        return 0.0;
    }
};

}  // namespace nav_core
