#pragma once

#include <string>
#include <vector>

namespace myg {
    class Problem {
    public:
        Problem(const std::string filename);
        Problem(const std::vector<std::string> data);
        Problem(const Problem& problem);
        ~Problem(void);

        const std::string filename(void) const;
        void filename(const std::string filename);

        const std::vector<std::string> data(void) const;
        void data(const std::vector<std::string> data);

    protected:
        std::string              _filename;
        std::vector<std::string> _data;

        void read_data(void);
    };

    inline const std::string Problem::filename(void) const { return _filename; }
    inline void Problem::filename(const std::string f) { _filename = f; }

    inline const std::vector<std::string> Problem::data(void) const { return _data; }
    inline void Problem::data(const std::vector<std::string> d) { _data = d; }
};
