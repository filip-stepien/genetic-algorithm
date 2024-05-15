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
        Range t { 0.1f, 1.0f };
        Range k { 0.1f, 1.0f };
        Range dzeta { 0.01f, 0.99f };
    };
    Range all[RANGES_SIZE];
};

#endif //GENETIC_ALGORITHM_SEARCHRANGES_HPP
