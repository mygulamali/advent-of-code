#include "01.hpp"

using namespace std;
using namespace myg;

const int Day01::VAL_0 = static_cast<int>('0');
const int Day01::VAL_9 = static_cast<int>('9');

int Day01::part_1(void) {
    int sum = 0;

    for (int i = 0, n = _data.size(); i < n; i++) {
        string digits;
        for (int j = 0, m = _data.at(i).length(); j < m; j++) {
            char c = _data.at(i).at(j);
            if (is_numeric(c))
                digits.push_back(c);
        }

        string value = {digits[0], digits.back()};
        sum += stoi(value);
    }

    return sum;
}

bool Day01::is_numeric(const char& c) {
    int c_val = static_cast<int>(c);
    return ((Day01::VAL_0 <= c_val) && (c_val <= Day01::VAL_9));
}
