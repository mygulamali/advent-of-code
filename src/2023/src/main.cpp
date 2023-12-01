#include <iostream>

#include "01.hpp"

using namespace std;
using namespace myg;

int main() {
    cout << "Day 1" << endl;
    Day01 d01("../../data/2023/01.txt");
    cout << "Part 1: ";
    cout << d01.part_1() << endl;

    return 0;
}
