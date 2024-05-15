#ifndef GENETIC_ALGORITHM_RANDOM_HPP
#define GENETIC_ALGORITHM_RANDOM_HPP

#include <random>

class Random {
public:
    static int randomInt(int min, int max);         // [min, max]
    static float randomFloat(float min, float max); // [min, max)
    static bool randomChance(float chance);
};


#endif //GENETIC_ALGORITHM_RANDOM_HPP
