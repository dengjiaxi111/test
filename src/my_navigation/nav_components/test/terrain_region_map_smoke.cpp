#include "nav_components/terrain_region_map.hpp"

#include <iostream>
#include <string>

int main(int argc, char** argv) {
    if (argc != 2 && argc != 3) return 2;
    nav_components::TerrainRegionMap map;
    std::string error;
    if (!map.loadFromFile(argv[1], "map", &error)) {
        std::cerr << error << '\n';
        return 1;
    }
    if (argc == 3 && std::string(argv[2]) == "--real-map") {
        if (map.getRegions().size() != 8 || map.countType("slope") != 4 ||
            map.countType("low_clearance") != 4) return 6;
        for (const auto& region : map.getRegions()) {
            if (region.polygon.size() != 4 || !region.attributes().IsMap()) return 7;
            std::cout << "id=" << region.id << " type=" << region.type
                      << " name=" << region.name << " polygon:";
            for (const auto& point : region.polygon) {
                std::cout << " (" << point.x << ',' << point.y << ')';
            }
            std::cout << '\n';
        }
        std::cout << "Loaded 8 terrain regions: slope=4, low_clearance=4\n";
        return 0;
    }
    if (map.getRegions().size() != 2 || map.countType("slope") != 1 ||
        map.countType("low_clearance") != 1) return 3;
    const auto& slope = map.getRegions()[0];
    const auto& hole = map.getRegions()[1];
    if (slope.name != "test_slope" || slope.polygon.size() != 4 ||
        slope.attributes()["future"]["mode"].as<std::string>() != "SOME_MODE" ||
        hole.raw["attributes"]["traversal"]["robot_mode"].as<std::string>() != "LOW") return 4;
    if (map.regionsAt(1.5, 1.5).size() != 2 ||
        map.regionsAt(8.0, 8.0).size() != 0 ||
        !nav_components::TerrainRegionMap::pointInPolygon(slope.polygon, 0.0, 1.0)) return 5;
    std::cout << "Loaded " << map.getRegions().size()
              << " terrain regions; arbitrary nested attributes and map coordinates preserved\n";
    return 0;
}
