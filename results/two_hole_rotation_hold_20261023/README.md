# 连续双洞云台保持验收

第一次降低和对准完成后，云台保持第一次对准的地面朝向，直到最后一洞 D 且整车净空确认。洞间底盘维持原普通导航旋转，第二洞 A 再执行底盘对准及入口复核；机构保持 LOW。最后释放后恢复普通云台自旋。

最终实现只修改 `test/sim/sim_bridge.py` 和 `test/sim/rotation_control.py` 两个旋转执行接口；本任务基线下的全部 `test/src`、模型、调参文件和启动脚本哈希相同，见 `scope_audit.json`。保持地面朝向时使用实测底盘角速度补偿云台关节速度。

模型 3 最终仿真三次通过：

| 记录 | 双洞路线 | 云台地面朝向最大波动 |
| --- | --- | --- |
| upper_1 | A2/B2 | 0.02957 rad（1.69°） |
| lower_1 | B1/A1 | 0.04283 rad（2.45°） |
| final_default | A2/B2 复跑 | 0.02551 rad（1.46°） |

三次均通过连续 LOW、对准后不恢复云台自旋、最后 D 后恢复普通旋转检查；详见 `audit.json` 和各目录的 `run.json`。这是带物理接触波动的朝向保持，不是实测角度绝对零变化。

四项旋转回归通过，见 `python_regressions.log`；当前安装版本四项 ROS 集成通过，见 `ros_integration.log`。`build.log` 对应恢复原 C++ 适配器后的构建。

早期同时锁定底盘与云台的方案在下方双洞连接段出现两次普通求解失败，因此已撤销；相关证据单独保存在 `both_locked_*`、`connector_solve_rejected`。`parallel_feedback_interruption_rejected` 是早期中断运行，不计入最终通过次数。

验证使用独立运行目录、ROS domain 和 Gazebo partition；未终止用户仿真进程。默认入口仍为 `bash test/start_demo.sh`，模型 3、起点 `(4.694,5)`，手动设置目标，不自动规划测试路线。已经运行的旧桥接进程需要重启才能加载更新。
