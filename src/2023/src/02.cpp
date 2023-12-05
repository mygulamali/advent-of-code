#include <iostream>

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
        if (Day02::has_all_valid_sets(str))
            count += game_id;
    }

    return count;
}

int Day02::part_2(void) {
    return 0;
}

int Day02::get_game_id(const string& str) {
    auto matches = myg::matches(str, Day02::GAME_RGX, 1);
    return stoi(matches[0]);
}

const vector<unordered_map<COLOR, int>> Day02::get_sets(const string& str) {
    vector<unordered_map<COLOR, int>> ret;
    vector<string> sets = myg::split(str, ';');
    for (auto set : sets) {
        vector<string> matches = myg::matches(set, Day02::SET_RGX);
        unordered_map<COLOR, int> set_map;

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

bool Day02::has_all_valid_sets(const string& str) {
    vector<unordered_map<COLOR, int>> sets = Day02::get_sets(str);
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
