#include "utils.hpp"

#include "02.hpp"

using namespace std;
using namespace myg;

const regex Day02::GAME_RGX("Game (\\d+):");
const regex Day02::SET_RGX("\\d+ (r|g|b)");

int Day02::part_1(void) {
    int count = 0;

    for (auto str : _data) {
        int game_id = Day02::get_game_id(str);
        vector<set_map_t> sets = Day02::get_sets(str);
        if (Day02::has_all_valid_sets(sets))
            count += game_id;
    }

    return count;
}

int Day02::part_2(void) {
    int sum = 0;

    for (auto str : _data) {
        vector<set_map_t> sets = Day02::get_sets(str);
        sum += Day02::min_set_power(sets);
    }

    return sum;
}

int Day02::get_game_id(const string& str) {
    auto matches = myg::matches(str, Day02::GAME_RGX, 1);
    return stoi(matches[0]);
}

const vector<set_map_t> Day02::get_sets(const string& str) {
    vector<set_map_t> ret;
    vector<string> sets = myg::split(str, ';');
    for (auto set : sets) {
        vector<string> matches = myg::matches(set, Day02::SET_RGX);
        set_map_t set_map;

        for (auto match : matches) {
            vector<string> parts = myg::split(match, ' ');
            int value = stoi(parts[0]);
            char color = parts[1][0];

            switch(color) {
                case 'r':
                    set_map[COLOR::r] += value;
                    break;
                case 'g':
                    set_map[COLOR::g] += value;
                    break;
                case 'b':
                    set_map[COLOR::b] += value;
                    break;
            }
        }

        ret.push_back(set_map);
    }
    return ret;
}

bool Day02::has_all_valid_sets(const vector<set_map_t>& sets) {
    for (auto set : sets) {
        if (
            (set[COLOR::r] > 12) ||
            (set[COLOR::g] > 13) ||
            (set[COLOR::b] > 14)
        )
            return false;
    }
    return true;
}

int Day02::min_set_power(const std::vector<set_map_t>& sets) {
    set_map_t min_set({
        {COLOR::r, 1},
        {COLOR::g, 1},
        {COLOR::b, 1},
    });

    for (auto set : sets)
        for (auto color : vector<COLOR>({ COLOR::r, COLOR::g, COLOR::b }))
            min_set[color] = max({min_set[color], set[color], 1});

    return min_set[COLOR::r] * min_set[COLOR::g] * min_set[COLOR::b];
}
