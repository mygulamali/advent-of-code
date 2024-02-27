#pragma once

#include <regex>
#include <unordered_map>

#include "problem.hpp"

namespace myg {
    struct mapping_t {
        ulong dest;
        ulong src;
        ulong range;
    };

    class Map {
    public:
        void add_mapping(const struct mapping_t& m);
        ulong operator[](const ulong& src) const;

    protected:
        std::vector<mapping_t> _mappings;
    };

    class Day05: public Problem {
    public:
        using Problem::Problem;

        static const std::vector<std::string> MAP_TITLES;
        static const std::regex RGX;

        ulong part_1(void);
        ulong part_2(void);

    protected:
        const std::vector<ulong> get_seeds(void) const;
        const std::vector<std::pair<ulong, ulong>> get_seed_ranges(void) const;
        const std::unordered_map<std::string, Map> get_maps(void) const;
        const Map get_map(const std::string& name) const;
        static ulong get_location(
            const std::unordered_map<std::string, Map>& maps,
            const ulong& seed
        );
    };
};
