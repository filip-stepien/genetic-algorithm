#include "Random.hpp"

// [min, max]
int Random::randomInt(int min, int max) {
    std::random_device rd;
    std::mt19937 generator { rd() };
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(generator);
}

// [min, max)
float Random::randomFloat(float min, float max) {
    std::random_device rd;
    std::mt19937 generator { rd() };
    std::uniform_real_distribution<> distrib(min, max);
    return distrib(generator);
}

bool Random::randomChance(float chance) {
    return randomFloat(0, 1) < chance;
}