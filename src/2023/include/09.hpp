#pragma once

#include <deque>
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
        const std::vector<std::deque<int>> create_histories(const std::string& s) const;
        static bool all_zeros(const std::deque<int>& d);
    };
};
