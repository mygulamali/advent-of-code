#include <iostream>

#include "01.hpp"
#include "02.hpp"
#include "03.hpp"
#include "04.hpp"
#include "05.hpp"
#include "06.hpp"
#include "07.hpp"
#include "08.hpp"
#include "09.hpp"
#include "11.hpp"

using namespace std;
using namespace myg;

int main() {
    cout << "Day 1" << endl;
    Day01 d01("../../data/2023/01.txt");
    cout << "Part 1: " << d01.part_1() << endl;
    cout << "Part 2: " << d01.part_2() << endl;

    cout << "Day 2" << endl;
    Day02 d02("../../data/2023/02.txt");
    cout << "Part 1: " << d02.part_1() << endl;
    cout << "Part 2: " << d02.part_2() << endl;

    cout << "Day 3" << endl;
    Day03 d03("../../data/2023/03.txt");
    cout << "Part 1: " << d03.part_1() << endl;

    cout << "Day 4" << endl;
    Day04 d04("../../data/2023/04.txt");
    cout << "Part 1: " << d04.part_1() << endl;

    cout << "Day 5" << endl;
    Day05 d05("../../data/2023/05.txt");
    cout << "Part 1: " << d05.part_1() << endl;
    // NOTE: commented out because it takes a long time to run (~10-min)
    // cout << "Part 2: " << d05.part_2() << endl;

    cout << "Day 6" << endl;
    Day06 d06("../../data/2023/06.txt");
    cout << "Part 1: " << d06.part_1() << endl;
    cout << "Part 2: " << d06.part_2() << endl;

    cout << "Day 7" << endl;
    Day07 d07("../../data/2023/07.txt");
    cout << "Part 1: " << d07.part_1() << endl;

    cout << "Day 8" << endl;
    Day08 d08("../../data/2023/08.txt");
    cout << "Part 1: " << d08.part_1() << endl;
    // NOTE: commented out because it takes a long time to run
    // cout << "Part 2: " << d08.part_2() << endl;

    cout << "Day 9" << endl;
    Day09 d09("../../data/2023/09.txt");
    cout << "Part 1: " << d09.part_1() << endl;
    cout << "Part 2: " << d09.part_2() << endl;

    cout << "Day 11" << endl;
    Day11 d11("../../data/2023/11.txt");
    cout << "Part 1: " << d11.part_1() << endl;
    cout << "Part 2: " << d11.part_2(1000000) << endl;

    return 0;
}
