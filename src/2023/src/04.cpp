#include <algorithm>
#include <cmath>

#include "utils.hpp"

#include "04.hpp"

using namespace std;
using namespace myg;

const regex Day04::CARD_RGX("Card\\s+(\\d+)");
const regex Day04::NUMBER_RGX("(\\d+)");

int Day04::part_1(void) {
    int total_points = 0;

    for (auto str : _data) {
        card c = parse_card(str);
        total_points += card_points(c);
    }

    return total_points;
}

int Day04::part_2(void) {
    int total_cards = 0;

    return total_cards;
}

const card Day04::parse_card(const string& str) {
    vector<string> str_parts = myg::split(str, ':');

    string id_str = myg::matches(str_parts.front(), CARD_RGX, 1).front();

    vector<string> numbers = myg::split(str_parts.back(), '|');

    vector<string> winning_number_strs = myg::matches(numbers.front(), NUMBER_RGX);
    set<int> winning_numbers = number_set(winning_number_strs);

    vector<string> chosen_number_strs = myg::matches(numbers.back(), NUMBER_RGX);
    set<int> chosen_numbers = number_set(chosen_number_strs);

    struct card ret = {
        stoi(id_str),
        winning_numbers,
        chosen_numbers,
    };

    return ret;
}

const set<int> Day04::number_set(const vector<string>& strs) {
    set<int> ret;
    for (auto str : strs)
        ret.insert(stoi(str));
    return ret;
}

int Day04::card_points(const card& c) {
    vector<int> intersection;
    set_intersection(
        c.winning_numbers.begin(), c.winning_numbers.end(),
        c.chosen_numbers.begin(), c.chosen_numbers.end(),
        back_inserter(intersection)
    );

    if (intersection.empty()) return 0;

    return pow(2.0, intersection.size() - 1);
}
