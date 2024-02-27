#pragma once

#include <regex>
#include <unordered_map>

#include "problem.hpp"

namespace myg {
    enum class COLOR { r, g, b };

    typedef std::unordered_map<COLOR, int> set_map_t;

    class Day02: public Problem {
    public:
        using Problem::Problem;

        static const std::regex GAME_RGX;
        static const std::regex SET_RGX;

        int part_1(void);
        int part_2(void);

    private:
        static int parse_game_id(const std::string& str);
        static const std::vector<set_map_t> parse_sets(const std::string& str);
        static bool has_all_valid_sets(const std::vector<set_map_t>& sets);
        static int min_set_power(const std::vector<set_map_t>& sets);
    };
};
