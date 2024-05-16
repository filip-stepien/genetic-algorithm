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
        Range t { 0.1f, 10.0f };
        Range k { 0.1f, 10.0f };
        Range dzeta { 0.01f, 1.0f };
    };
    Range all[RANGES_SIZE];
};

enum RangeType {
    INCLUSIVE,
    EXCLUSIVE
};

#endif //GENETIC_ALGORITHM_RANGES_HPP
