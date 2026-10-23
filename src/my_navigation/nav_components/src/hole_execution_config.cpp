#include "nav_components/hole_execution_config.hpp"
namespace nav_components {
nav_core::hole_exec::Config loadHoleExecutionConfig(const std::string& filename) {
    nav_core::hole_exec::Config c;
    if(filename.empty())return c;
    auto root=YAML::LoadFile(filename);auto n=root["hole_state_machine"];
    if(!n||!n.IsMap())throw std::invalid_argument("missing hole_state_machine map");
    std::set<std::string> known;
#define HOLE_EXEC_LOAD(name,value,meaning,unit) known.insert(#name);if(n[#name])c.name=n[#name].as<double>();
    HOLE_EXEC_DOUBLE_PARAMETERS(HOLE_EXEC_LOAD)
#undef HOLE_EXEC_LOAD
    // 兼容旧测试配置；准备阶段已无独立限速，此字段不再参与控制。
    known.insert("prepare_speed");
    for(auto key:{"enabled","allow_free","physical_parameters_confirmed","simulation_only","max_replans","max_action_retries","max_traversal_retries"})known.insert(key);
    if(n["enabled"])c.enabled=n["enabled"].as<bool>();
    if(n["allow_free"])c.allow_free=n["allow_free"].as<bool>();
    if(n["physical_parameters_confirmed"])c.physical_parameters_confirmed=n["physical_parameters_confirmed"].as<bool>();
    if(n["simulation_only"])c.simulation_only=n["simulation_only"].as<bool>();
    if(n["max_replans"])c.max_replans=n["max_replans"].as<int>();
    if(n["max_action_retries"])c.max_action_retries=n["max_action_retries"].as<int>();
    if(n["max_traversal_retries"])c.max_traversal_retries=n["max_traversal_retries"].as<int>();
    for(auto item:n)if(!known.count(item.first.as<std::string>()))throw std::invalid_argument("unknown hole FSM parameter: "+item.first.as<std::string>());
    return c;
}
}
