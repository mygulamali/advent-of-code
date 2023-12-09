#include <iostream>

#include "01.hpp"
#include "02.hpp"
#include "04.hpp"
#include "06.hpp"
#include "07.hpp"
#include "08.hpp"

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

    cout << "Day 4" << endl;
    Day04 d04("../../data/2023/04.txt");
    cout << "Part 1: " << d04.part_1() << endl;

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

    return 0;
}
