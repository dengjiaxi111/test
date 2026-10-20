#pragma once

#include <nav_msgs/msg/occupancy_grid.hpp>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <vector>

namespace nav_core {
// -2 表示从未人工指定；-1/0/100 分别为未知/自由/障碍。
constexpr int8_t kNoRasterOverride = -2;
inline bool sameRasterGeometry(const nav_msgs::msg::OccupancyGrid &a,
                               const nav_msgs::msg::OccupancyGrid &b) {
    return a.header.frame_id == b.header.frame_id && a.info.width == b.info.width &&
        a.info.height == b.info.height && a.info.resolution == b.info.resolution &&
        a.info.origin == b.info.origin;
}
inline void validateRaster(const nav_msgs::msg::OccupancyGrid &map) {
    if (map.header.frame_id.empty() || !std::isfinite(map.info.resolution) ||
        map.info.resolution <= 0 || map.info.width == 0 || map.info.height == 0 ||
        map.data.size() != std::size_t(map.info.width) * map.info.height)
        throw std::runtime_error("地图尺寸、分辨率或坐标系无效");
    for (const auto v : map.data)
        if (v < -1 || v > 100) throw std::runtime_error("地图包含无效占用值");
}
// 忽略发布时间和加载时间，只标识实际地图内容及坐标。用于拒绝另一张地图的笔迹。
inline std::string rasterSourceId(const nav_msgs::msg::OccupancyGrid &map) {
    std::uint64_t hash = 14695981039346656037ULL;
    const auto append = [&](const auto &value) {
        const auto *bytes = reinterpret_cast<const unsigned char *>(&value);
        for (std::size_t i=0;i<sizeof(value);++i) { hash ^= bytes[i]; hash *= 1099511628211ULL; }
    };
    for (const auto c : map.header.frame_id) append(c);
    append(map.info.width); append(map.info.height); append(map.info.resolution);
    const auto &p=map.info.origin.position; const auto &q=map.info.origin.orientation;
    append(p.x); append(p.y); append(p.z); append(q.x); append(q.y); append(q.z); append(q.w);
    for (const auto v : map.data) append(v);
    std::ostringstream out; out << std::hex << std::setw(16) << std::setfill('0') << hash;
    return out.str();
}
inline std::vector<int8_t> rasterOverrides(std::size_t size,
        const std::vector<std::uint32_t> &indices, const std::vector<int8_t> &values) {
    if (indices.size()!=values.size()) throw std::runtime_error("笔迹索引与数值数量不一致");
    std::vector<int8_t> result(size,kNoRasterOverride);
    for (std::size_t i=0;i<indices.size();++i) {
        if (indices[i]>=size || (values[i]!=-1 && values[i]!=0 && values[i]!=100))
            throw std::runtime_error("笔迹索引越界或占用值无效");
        if (result[indices[i]]!=kNoRasterOverride) throw std::runtime_error("笔迹包含重复索引");
        result[indices[i]]=values[i];
    }
    return result;
}
inline void applyRasterOverrides(nav_msgs::msg::OccupancyGrid &map,
                                 const std::vector<int8_t> &overrides) {
    if (map.data.size()!=overrides.size()) throw std::runtime_error("笔迹与地图尺寸不一致");
    for (std::size_t i=0;i<overrides.size();++i)
        if (overrides[i]!=kNoRasterOverride) map.data[i]=overrides[i];
}
inline void sparseRasterOverrides(const std::vector<int8_t> &overrides,
        std::vector<std::uint32_t> &indices, std::vector<int8_t> &values) {
    indices.clear(); values.clear();
    for (std::size_t i=0;i<overrides.size();++i) if (overrides[i]!=kNoRasterOverride) {
        indices.push_back(static_cast<std::uint32_t>(i)); values.push_back(overrides[i]);
    }
}
}  // namespace nav_core
