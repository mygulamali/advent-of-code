#include <limits>

#include "utils.hpp"

#include "05.hpp"

using namespace std;
using namespace myg;

void Map::add_mapping(const struct mapping_t& m)  {
    _mappings.push_back(m);
};

ulong Map::operator[](const ulong& src) const {
    for (auto m : _mappings)
        if ((m.src <= src) && (src <= m.src + m.range))
            return m.dest + src - m.src;

    return src;
}

const vector<string> Day05::MAP_TITLES({
    "seed-to-soil",
    "soil-to-fertilizer",
    "fertilizer-to-water",
    "water-to-light",
    "light-to-temperature",
    "temperature-to-humidity",
    "humidity-to-location",
});

const regex Day05::RGX("(\\d+)");

ulong Day05::part_1(void) {
    vector<ulong> seeds = get_seeds();
    unordered_map<string, Map> maps = get_maps();

    ulong location = numeric_limits<ulong>::max();
    for (auto seed : seeds) {
        location = min(location, get_location(maps, seed));
    }

    return location;
}

ulong Day05::part_2(void) {
    vector<pair<ulong, ulong>> seed_ranges = get_seed_ranges();
    unordered_map<string, Map> maps = get_maps();

    ulong location = numeric_limits<ulong>::max();
    for (auto range : seed_ranges) {
        ulong n = range.first + range.second;
        for (auto seed = range.first; seed <= n; seed++)
            location = min(location, get_location(maps, seed));
    }

    return location;
}

const vector<ulong> Day05::get_seeds(void) const {
    vector<string> strs = myg::matches(_data[0], RGX);
    vector<ulong> seeds;

    for (auto str : strs)
        seeds.push_back(stoul(str));

    return seeds;
}

const vector<pair<ulong, ulong>> Day05::get_seed_ranges(void) const {
    vector<string> strs = myg::matches(_data[0], RGX);
    vector<pair<ulong, ulong>> seeds;

    for (uint i = 0, n = strs.size(); i < n; i += 2) {
        pair<ulong, ulong> p(stoul(strs[i]), stoul(strs[i + 1]));
        seeds.push_back(p);
    }

    return seeds;
}

const unordered_map<string, Map> Day05::get_maps(void) const {
    unordered_map<string, Map> maps;

    for (auto title : MAP_TITLES)
        maps[title] = get_map(title);

    return maps;
}

const Map Day05::get_map(const string& name) const {
    Map map;
    string title = name + " map:";

    bool read_line = false;
    for (auto line : _data) {
        if (line == title) {
            read_line = true;
            continue;
        }

        if (!read_line) continue;

        if (read_line && line.empty()) {
            break;
        }

        vector<string> nums = myg::matches(line, RGX);
        struct mapping_t mapping = {
            stoul(nums[0]),
            stoul(nums[1]),
            stoul(nums[2])
        };

        map.add_mapping(mapping);
    }

    return map;
}

ulong Day05::get_location(
    const unordered_map<string, Map>& maps,
    const ulong& seed
) {
    ulong next = seed;
    for (auto title : MAP_TITLES) {
        next = maps.at(title)[next];
    }
    return next;
}
