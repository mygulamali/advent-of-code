#include <iostream>

#include "01.hpp"
#include "02.hpp"

using namespace std;
using namespace myg;

int main() {
    cout << "Day 1" << endl;
    Day01 d01("../../data/2023/01.txt");
    cout << "Part 1: ";
    cout << d01.part_1() << endl;
    cout << "Part 2: ";
    cout << d01.part_2() << endl;

    cout << "Day 2" << endl;
    Day02 d02("../../data/2023/02.txt");
    cout << "Part 1: ";
    cout << d02.part_1() << endl;

    return 0;
}
