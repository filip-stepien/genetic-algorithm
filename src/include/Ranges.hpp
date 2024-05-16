#ifndef GENETIC_ALGORITHM_RANGES_HPP
#define GENETIC_ALGORITHM_RANGES_HPP

#include <utility>
#include <limits>

constexpr int RANGES_SIZE = 3;
constexpr float RANGE_MIN = std::numeric_limits<float>::lowest();
constexpr float RANGE_MAX = std::numeric_limits<float>::max();

struct Range {
    float min;
    float max;
};

union Ranges {
    struct {
        Range t;
        Range k;
        Range dzeta;
    };
    Range all[RANGES_SIZE];
};

enum RangeType {
    INCLUSIVE,
    EXCLUSIVE
};

#endif //GENETIC_ALGORITHM_RANGES_HPP
