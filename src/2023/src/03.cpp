#include <cctype>

#include "utils.hpp"

#include "03.hpp"

using namespace std;
using namespace myg;

const regex Day03::RGX("(\\d+)");

Day03::Day03(const string& filename) :
Problem(filename)
{
    _height = _data.size();
    _width = _data[0].size();
    fetch_numbers();
}

Day03::Day03(const vector<string>& data) :
Problem(data)
{
    _height = _data.size();
    _width = _data[0].size();
    fetch_numbers();
}

int Day03::part_1(void) {
    int total = 0;

    for (int i = 0, n = _numbers.size(); i < n; i++)
        if (is_part_number(i))
            total += stoi(get<0>(_numbers[i]));

    return total;
}

int Day03::part_2(void) {
    return 0;
}

void Day03::fetch_numbers(void) {
    _numbers = numbers_t();

    for (int l = 0; l < _height; l++) {
        sregex_iterator iter(_data[l].begin(), _data[l].end(), RGX);
        sregex_iterator end;

        while (iter != end) {
            smatch match = *iter;
            string str = match.str();
            int p = match.position();

            _numbers.push_back(make_tuple(str, p, l));

            ++iter;
        }
    }
}

bool Day03::is_part_number(const int& i) const {
    string str = get<0>(_numbers[i]);
    int x = get<1>(_numbers[i]);
    int y = get<2>(_numbers[i]);

    int left = max(0, x - 1);
    int right = min(_width - 1, x + static_cast<int>(str.size()));
    int top = max(0, y - 1);
    int bottom = min(_height - 1, y + 1);

    for (int l = top; l <= bottom; l++)
        for (int p = left; p <= right; p++)
            if (_data[l][p] != '.' && !isdigit(_data[l][p]))
                return true;

    return false;
}
