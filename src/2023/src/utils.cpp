#include <sstream>

#include "utils.hpp"

using namespace std;
using namespace myg;

vector<string> myg::matches(const string& str, const regex& rgx, const int grp) {
    sregex_iterator iter(str.begin(), str.end(), rgx);
    sregex_iterator end;
    vector<string> ret;

    while (iter != end) {
        smatch match = *iter;
        ret.push_back(match.str(grp));
        ++iter;
    }

    return ret;
}

vector<string> myg::split(const string& str, const char& delim) {
    istringstream ss(str);
    string token;
    vector<string> tokens;
    while (getline(ss, token, delim)) tokens.push_back(token);
    return tokens;
}
