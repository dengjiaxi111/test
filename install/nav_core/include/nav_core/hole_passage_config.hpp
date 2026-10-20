#pragma once
#include "nav_core/hole_geometry_yaml.hpp"
#include <filesystem>
#include <fstream>
#include <map>
#include <sstream>
#include <iomanip>
#include <set>
#include <unistd.h>
#include <sys/stat.h>

namespace nav_core {
inline std::string holeGeometryFingerprint(const std::vector<HoleGeometryInput> &regions) {
    std::ostringstream out;out<<std::setprecision(17);
    for(const auto &r:regions) {out<<r.id<<' '<<r.frame_id<<' '<<r.passable_edge_pair<<' '<<r.enabled<<' '<<r.bidirectional;
        for(auto p:r.polygon)out<<' '<<p.x<<' '<<p.y;out<<'\n';}
    return out.str();
}
// 独立文件是人工范围的唯一来源；几何和通行方向仍归 Terrain 管理。
inline YAML::Node readHolePassageConfig(const YAML::Node &root) {
    if(!root.IsMap() || !root["schema_version"] || root["schema_version"].as<int>()!=1 ||
       !root["frame_id"] || root["frame_id"].as<std::string>()!="map" ||
       !root["holes"] || !root["holes"].IsSequence())
        throw std::runtime_error("洞口参数文件需要 schema_version: 1、frame_id: map 和 holes 列表");
    std::set<std::string> ids;
    for(const auto &entry:root["holes"]) {
        if(!entry.IsMap() || !entry["id"] || !ids.insert(entry["id"].as<std::string>()).second ||
           entry["id"].as<std::string>().empty())throw std::runtime_error("洞口参数 ID 缺失或重复");
        const auto edges=entry["passable_edges"];
        if(!edges || !edges.IsSequence() || edges.size()!=2 || edges[0].as<int>()<0 ||
           edges[0].as<int>()>1 || edges[1].as<int>()!=edges[0].as<int>()+2)
            throw std::runtime_error("洞口参数需要明确绑定对侧通行边");
        if(!entry["prepare_path_distance"] || !std::isfinite(entry["prepare_path_distance"].as<double>()) ||
           entry["prepare_path_distance"].as<double>()<=0)
            throw std::runtime_error("prepare_path_distance 必须是正的有限米数");
        readHoleStraightRange(entry);
    }
    return YAML::Clone(root);
}
inline YAML::Node emptyHolePassageConfig() {
    YAML::Node root;root["schema_version"]=1;root["frame_id"]="map";
    root["holes"]=YAML::Node(YAML::NodeType::Sequence);return root;
}
inline YAML::Node holePassageEntry(const YAML::Node &root,const std::string &id) {
    if(root && root["holes"])for(const auto &entry:root["holes"])
        if(entry["id"].as<std::string>()==id)return entry;
    return YAML::Node(YAML::NodeType::Undefined);
}
inline void overlayHolePassage(YAML::Node traversal,const YAML::Node &entry) {
    traversal.remove("straight_range");traversal.remove("prepare_path_distance");
    if(!entry)return;
    const auto edges=traversal["passable_edges"];
    if(!edges||!edges.IsSequence()||edges.size()!=2||edges[0].as<int>()!=entry["passable_edges"][0].as<int>()||
       edges[1].as<int>()!=entry["passable_edges"][1].as<int>())
        throw std::runtime_error("洞口参数通行边与 Terrain 不一致，请移除旧范围后重新确定");
    traversal["prepare_path_distance"]=entry["prepare_path_distance"].as<double>();
    // 规范化数值及 YAML 风格，避免同一范围读写后因表示不同误触活动承诺保护。
    if(entry["straight_range"])writeHoleStraightRange(traversal,readHoleStraightRange(entry));
}
inline std::string emitHolePassageConfig(const YAML::Node &root) {
    readHolePassageConfig(root);YAML::Emitter out;out.SetDoublePrecision(17);
    out<<YAML::BeginMap<<YAML::Key<<"schema_version"<<YAML::Value<<1<<YAML::Comment("文件格式版本")
       <<YAML::Key<<"frame_id"<<YAML::Value<<"map"<<YAML::Comment("范围所在地图坐标系")
       <<YAML::Key<<"holes"<<YAML::Value<<YAML::BeginSeq;
    for(const auto &entry:root["holes"]) {
        out<<YAML::BeginMap<<YAML::Key<<"id"<<YAML::Value<<entry["id"].as<std::string>()<<YAML::Comment("对应 Terrain 洞口 ID")
           <<YAML::Key<<"passable_edges"<<YAML::Value<<YAML::Flow<<YAML::BeginSeq
           <<entry["passable_edges"][0].as<int>()<<entry["passable_edges"][1].as<int>()<<YAML::EndSeq<<YAML::Block
           <<YAML::Comment("零起点物理通行边编号")
           <<YAML::Key<<"prepare_path_distance"<<YAML::Value<<entry["prepare_path_distance"].as<double>()
           <<YAML::Comment("准备点到实际入口沿最终路径的距离（米）；允许在入口直线内准备，进入 E 前须完成变形");
        const auto range=readHoleStraightRange(entry);
        if(range) {
            out<<YAML::Key<<"straight_range"<<YAML::Value<<YAML::BeginMap
               <<YAML::Key<<"schema_version"<<YAML::Value<<1<<YAML::Comment("固定范围格式版本")
               <<YAML::Key<<"binding"<<YAML::Value<<"passable_edges"<<YAML::Comment("两侧长度绑定物理通行边，反向共用同一区间")
               <<YAML::Key<<"sides"<<YAML::Value<<YAML::BeginSeq;
            for(int i=0;i<2;++i)out<<YAML::BeginMap<<YAML::Key<<"edge_id"<<YAML::Value<<range->edge+2*i
               <<YAML::Comment("物理通行边编号")<<YAML::Key<<"extension_length"<<YAML::Value<<range->extensions[i]
               <<YAML::Comment("从该边向洞外延伸的固定直线长度（米）")<<YAML::EndMap;
            out<<YAML::EndSeq<<YAML::EndMap;
        }
        out<<YAML::EndMap;
    }
    out<<YAML::EndSeq<<YAML::EndMap;
    if(!out.good())throw std::runtime_error(out.GetLastError());return std::string(out.c_str())+"\n";
}
inline void saveHolePassageConfig(const std::string &path,const YAML::Node &root) {
    if(path.empty())throw std::runtime_error("洞口参数保存路径为空");
    const auto output=emitHolePassageConfig(root);
    const auto target=std::filesystem::weakly_canonical(std::filesystem::absolute(path));
    auto pattern=target.string()+".tmp.XXXXXX";std::vector<char> name(pattern.begin(),pattern.end());name.push_back(0);
    const int fd=mkstemp(name.data());if(fd<0)throw std::runtime_error("无法创建洞口参数临时文件");
    bool closed=false;
    try {
        struct stat info{};if(stat(target.c_str(),&info)==0)fchmod(fd,info.st_mode&0777);else fchmod(fd,0644);
        std::size_t written=0;while(written<output.size()) {
            const auto n=write(fd,output.data()+written,output.size()-written);
            if(n<=0)throw std::runtime_error("写入洞口参数失败");written+=n;
        }
        if(fsync(fd)!=0)throw std::runtime_error("同步洞口参数失败");
        const int result=close(fd);closed=true;if(result!=0)throw std::runtime_error("关闭洞口参数文件失败");
        std::filesystem::rename(name.data(),target);
    } catch(...) {if(!closed)close(fd);unlink(name.data());throw;}
}
} // namespace nav_core
