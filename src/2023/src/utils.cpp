#include <sstream>

#include "utils.hpp"

using namespace std;
using namespace myg;

vector<string> myg::split(const string& str, const char& delim) {
    istringstream ss(str);
    string token;
    vector<string> tokens;
    while (getline(ss, token, delim)) tokens.push_back(token);
    return tokens;
}
