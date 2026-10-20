#pragma once

#include <yaml-cpp/yaml.h>

#include <memory>
#include <string>
#include <vector>

namespace nav_components {

// Coordinates are metres in frame_id (normally "map"), never PGM pixel indices.
struct TerrainPoint {
    double x = 0.0;
    double y = 0.0;
};

struct TerrainRegion {
    std::string id;
    std::string type;
    std::string name;
    std::string frame_id;
    std::vector<TerrainPoint> polygon;
    int passable_edge_pair = -1;

    // Preserve the complete YAML entry, including attributes and per-hole
    // static clearance overrides, without changing the source document.
    YAML::Node raw;
    YAML::Node attributes() const { return raw["attributes"]; }
};

class TerrainRegionMap {
public:
    using ConstPtr = std::shared_ptr<const TerrainRegionMap>;

    bool loadFromFile(const std::string& path, const std::string& expected_frame,
                      std::string* error = nullptr);
    std::shared_ptr<TerrainRegionMap> withHolePassageConfig(const YAML::Node &config) const;
    const std::vector<TerrainRegion>& getRegions() const { return regions_; }
    std::vector<const TerrainRegion*> regionsAt(double x, double y) const;
    std::size_t countType(const std::string& type) const;
    const std::string& sourcePath() const { return source_path_; }

    static bool pointInPolygon(const std::vector<TerrainPoint>& polygon,
                               double x, double y);

private:
    std::vector<TerrainRegion> regions_;
    std::string source_path_;
};

}  // namespace nav_components
