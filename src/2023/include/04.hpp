#pragma once

#include <regex>
#include <set>

#include "problem.hpp"

namespace myg {
    struct card {
        int id;
        std::set<int> winning_numbers;
        std::set<int> chosen_numbers;
    };

    class Day04: public Problem {
    public:
        using Problem::Problem;

        static const std::regex CARD_RGX;
        static const std::regex NUMBER_RGX;

        int part_1(void);
        int part_2(void);

    private:
        static const card parse_card(const std::string& str);
        static const std::set<int> number_set(const std::vector<std::string>& strs);
        static int card_points(const card& c);
    };
};
