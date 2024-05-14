#include "Random.hpp"

void Random::start() {
    generator = std::mt19937(rd());
}

// [min, max]
int Random::randomInt(int min, int max) {
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(generator);
}

// [min, max)
float Random::randomFloat(float min, float max) {
    std::uniform_real_distribution<> distrib(min, max);
    return distrib(generator);
}

bool Random::randomChance(float chance) {
    return randomFloat(0, 1) < chance;
}