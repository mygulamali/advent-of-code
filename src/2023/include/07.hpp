#pragma once

#include <map>

#include "problem.hpp"

namespace myg {
    class Hand {
    public:
        std::string cards;
        std::map<char, int> card_map;
        int bid;

        Hand(const std::string& cards, const int bid);

        bool operator<(const Hand& h) const;

        const std::vector<int> card_counts(void) const;
        int card_value(const int i) const;
        int strength(void) const;

        bool is_five(void) const;
        bool is_four(void) const;
        bool is_full(void) const;
        bool is_three(void) const;
        bool is_two(void) const;
        bool is_one(void) const;
        bool is_high(void) const;
    };

    class Day07: public Problem {
    public:
        using Problem::Problem;

        int part_1(void);
        int part_2(void);

    protected:
        static const Hand parse_hand(const std::string& str);
    };
};
