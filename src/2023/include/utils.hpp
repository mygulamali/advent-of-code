#pragma once

#include <regex>
#include <string>
#include <vector>

namespace myg {
    std::vector<std::string> matches(const std::string& str, const std::regex& rgx, const int grp = 0);
    std::vector<std::string> split(const std::string& str, const char& delim);
}
