#pragma once

#include <regex>

#include "problem.hpp"

namespace myg {
    struct race {
        ulong time;
        ulong distance;
    };

    class Day06: public Problem {
    public:
        using Problem::Problem;

        static const std::regex RGX;

        int part_2(void);
        ulong part_1(void);

    private:
        std::vector<race> parse_races(void);
        static ulong n_winning_races(const race& r);
    };
};
