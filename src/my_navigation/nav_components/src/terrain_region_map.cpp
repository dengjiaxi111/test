#include "nav_components/terrain_region_map.hpp"
#include <nav_core/hole_geometry_yaml.hpp>
#include <nav_core/hole_passage_config.hpp>

#include <cmath>
#include <stdexcept>
#include <unordered_set>
#include <utility>

namespace nav_components {
namespace {

TerrainPoint parsePoint(const YAML::Node& value) {
    TerrainPoint point;
    if (value.IsSequence() && value.size() >= 2) {
        point.x = value[0].as<double>();
        point.y = value[1].as<double>();
    } else if (value.IsMap() && value["x"] && value["y"]) {
        point.x = value["x"].as<double>();
        point.y = value["y"].as<double>();
    } else {
        throw std::runtime_error("polygon point must be [x, y] or {x, y}");
    }
    if (!std::isfinite(point.x) || !std::isfinite(point.y)) {
        throw std::runtime_error("polygon point is not finite");
    }
    return point;
}

}  // namespace

bool TerrainRegionMap::loadFromFile(const std::string& path,
                                    const std::string& expected_frame,
                                    std::string* error) {
    try {
        const YAML::Node root = YAML::LoadFile(path);
        const YAML::Node entries = root["regions"];
        if (!entries || !entries.IsSequence()) {
            throw std::runtime_error("terrain YAML requires a regions sequence");
        }
        std::vector<TerrainRegion> parsed;
        std::unordered_set<std::string> ids;
        for (const YAML::Node& entry : entries) {
            if (!entry.IsMap() || !entry["id"] || !entry["type"] ||
                !entry["id"].IsScalar() || !entry["type"].IsScalar()) {
                throw std::runtime_error("each terrain region needs scalar id and type");
            }
            TerrainRegion region;
            region.id = entry["id"].as<std::string>();
            region.type = entry["type"].as<std::string>();
            region.name = entry["name"] ? entry["name"].as<std::string>() : region.id;
            region.frame_id = entry["frame_id"] ? entry["frame_id"].as<std::string>() : "map";
            if (region.id.empty() || region.type.empty() || !ids.insert(region.id).second) {
                throw std::runtime_error("terrain ids must be unique and id/type nonempty");
            }
            if (region.frame_id != expected_frame) {
                throw std::runtime_error("region " + region.id + " has frame_id=" +
                    region.frame_id + ", expected " + expected_frame);
            }
            const YAML::Node polygon = entry["geometry"] && entry["geometry"]["polygon"]
                ? entry["geometry"]["polygon"] : entry["points"];
            if (!polygon || !polygon.IsSequence() || polygon.size() < 3) {
                throw std::runtime_error("region " + region.id + " needs at least 3 polygon points");
            }
            for (const YAML::Node& point : polygon) {
                region.polygon.push_back(parsePoint(point));
            }
            const YAML::Node traversal = entry["traversal"];
            if (traversal && traversal.IsMap() && traversal["passable_edges"] &&
                traversal["passable_edges"].IsSequence() &&
                traversal["passable_edges"].size() == 2) {
                const int first = traversal["passable_edges"][0].as<int>();
                const int opposite = traversal["passable_edges"][1].as<int>();
                if ((first == 0 || first == 1) && opposite == first + 2)
                    region.passable_edge_pair = first;
            }
            nav_core::readHoleStraightRange(traversal);
            region.raw = YAML::Clone(entry);
            parsed.push_back(std::move(region));
        }
        regions_ = std::move(parsed);
        source_path_ = path;
        return true;
    } catch (const std::exception& exception) {
        if (error) *error = exception.what();
        return false;
    }
}

std::shared_ptr<TerrainRegionMap> TerrainRegionMap::withHolePassageConfig(const YAML::Node &config) const {
    nav_core::readHolePassageConfig(config);
    auto result=std::make_shared<TerrainRegionMap>(*this);
    std::unordered_set<std::string> matched;
    for(auto &region:result->regions_) {
        region.raw=YAML::Clone(region.raw);
        const auto entry=nav_core::holePassageEntry(config,region.id);
        if(entry && region.type!="low_clearance" && region.type!="2")
            throw std::runtime_error("参数 ID 不是洞口："+region.id);
        if(region.type!="low_clearance" && region.type!="2")continue;
        if(entry)matched.insert(region.id);
        if(!region.raw["traversal"])region.raw["traversal"]=YAML::Node(YAML::NodeType::Map);
        nav_core::overlayHolePassage(region.raw["traversal"],entry);
    }
    if(matched.size()!=config["holes"].size())throw std::runtime_error("参数文件含不存在的洞口 ID");
    return result;
}

bool TerrainRegionMap::pointInPolygon(const std::vector<TerrainPoint>& polygon,
                                      double x, double y) {
    if (polygon.size() < 3 || !std::isfinite(x) || !std::isfinite(y)) return false;
    bool inside = false;
    for (std::size_t i = 0, j = polygon.size() - 1; i < polygon.size(); j = i++) {
        const auto& a = polygon[j];
        const auto& b = polygon[i];
        const double dx = b.x - a.x;
        const double dy = b.y - a.y;
        const double cross = (x - a.x) * dy - (y - a.y) * dx;
        const double dot = (x - a.x) * dx + (y - a.y) * dy;
        const double length_sq = dx * dx + dy * dy;
        if (length_sq > 0.0 && std::abs(cross) <= 1e-9 * std::sqrt(length_sq) &&
            dot >= 0.0 && dot <= length_sq) return true;
        if ((a.y > y) != (b.y > y) &&
            x < (b.x - a.x) * (y - a.y) / (b.y - a.y) + a.x) inside = !inside;
    }
    return inside;
}

std::vector<const TerrainRegion*> TerrainRegionMap::regionsAt(double x, double y) const {
    std::vector<const TerrainRegion*> found;
    for (const auto& region : regions_) {
        if (pointInPolygon(region.polygon, x, y)) found.push_back(&region);
    }
    return found;
}

std::size_t TerrainRegionMap::countType(const std::string& type) const {
    std::size_t count = 0;
    for (const auto& region : regions_) {
        if (region.type == type) ++count;
    }
    return count;
}

}  // namespace nav_components
