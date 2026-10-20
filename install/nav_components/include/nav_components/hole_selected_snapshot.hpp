#pragma once
#include "nav_components/hole_passage_planner.hpp"
namespace nav_components {
struct HoleSelectedSnapshot {
    nav_msgs::msg::Path path;
    std::vector<nav_core::HolePassageCandidate> passages;
    std::vector<nav_core::HolePreparationEvent> preparation;
    std::vector<nav_core::HoleDepartureEvent> departure;
    std::vector<HoleRouteAttempt> selected;
    std::uint64_t terrain_revision=0,configuration_revision=0,map_revision=0;
    double removed_prefix=0;
};
}
