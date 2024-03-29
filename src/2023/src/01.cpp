#include "utils.hpp"

#include "01.hpp"

using namespace std;
using namespace myg;

const int Day01::VAL_0 = static_cast<int>('0');
const int Day01::VAL_9 = static_cast<int>('9');
const regex Day01::RGX("(?=(\\d|one|two|three|four|five|six|seven|eight|nine))");
const std::unordered_map<std::string, char> Day01::NUMBER_MAP({
    {"0",     '0'},
    {"1",     '1'},
    {"2",     '2'},
    {"3",     '3'},
    {"4",     '4'},
    {"5",     '5'},
    {"6",     '6'},
    {"7",     '7'},
    {"8",     '8'},
    {"9",     '9'},
    {"one",   '1'},
    {"two",   '2'},
    {"three", '3'},
    {"four",  '4'},
    {"five",  '5'},
    {"six",   '6'},
    {"seven", '7'},
    {"eight", '8'},
    {"nine",  '9'},
});

int Day01::part_1(void) {
    int sum = 0;

    for (auto str : _data) {
        string digits;
        for (int j = 0, m = str.length(); j < m; j++) {
            char c = str.at(j);
            if (is_numeric(c))
                digits.push_back(c);
        }

        string value = {digits[0], digits.back()};
        sum += stoi(value);
    }

    return sum;
}

int Day01::part_2(void) {
    int sum = 0;

    for (auto str : _data) {
        vector<string> digits = matches(str, Day01::RGX, 1);
        string value = {as_number(digits[0]), as_number(digits.back())};
        sum += stoi(value);
    }

    return sum;
}

bool Day01::is_numeric(const char& c) {
    int c_val = static_cast<int>(c);
    return ((Day01::VAL_0 <= c_val) && (c_val <= Day01::VAL_9));
}

char Day01::as_number(const string& s) {
    return Day01::NUMBER_MAP.at(s);
}
