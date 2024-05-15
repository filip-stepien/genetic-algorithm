#ifndef GENETIC_ALGORITHM_SEARCHRANGES_HPP
#define GENETIC_ALGORITHM_SEARCHRANGES_HPP

#include <utility>

constexpr int RANGES_SIZE = 3;

struct Range {
    float min;
    float max;
};

union SearchRanges {
    struct {
        Range t;
        Range k;
        Range dzeta;
    };
    Range all[RANGES_SIZE];
};

#endif //GENETIC_ALGORITHM_SEARCHRANGES_HPP
