#pragma once
#include "nav_core/hole_execution_types.hpp"
#include <yaml-cpp/yaml.h>
namespace nav_components {
nav_core::hole_exec::Config loadHoleExecutionConfig(const std::string& filename);
}
