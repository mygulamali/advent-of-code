#pragma once

#include <regex>

#include "problem.hpp"

namespace myg {
    class Day09: public Problem {
    public:
        using Problem::Problem;

        static const std::regex RGX;

        int part_1(void);
        int part_2(void);

    protected:
        static bool all_zeros(const std::vector<int>& v);
    };
};
