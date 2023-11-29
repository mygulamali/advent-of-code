#include <fstream>
#include <iostream>

#include "00.hpp"

using namespace std;
using namespace myg;

Problem::Problem(const string filename) {
    _filename = filename;
    read_data();
}

Problem::Problem(const vector<string> data) {
    _filename = "";
    _data = data;
}

Problem::Problem(const Problem& problem) {
    _filename = problem.filename();
    _data = problem.data();
}

Problem::~Problem(void) {}

void Problem::read_data(void) {
    ifstream fs(_filename);

    if (!fs.is_open()) {
        cout << "ERROR: cannot find file " << _filename << endl;
    }

    string line;
    _data = vector<string>{};
    while (getline(fs, line)) {
        _data.push_back(line);
    }

    fs.close();
}
