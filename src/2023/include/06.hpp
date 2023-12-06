#pragma once

#include <regex>

#include "problem.hpp"

namespace myg {
    struct race {
        int time;
        int distance;
    };

    class Day06: public Problem {
    public:
        using Problem::Problem;

        static const std::regex RGX;

        int part_1(void);
        int part_2(void);

    private:
        std::vector<race> parse_races(void);
        static int n_winning_races(const race& r);
    };
};
