#ifndef GENETIC_ALGORITHM_RANDOM_HPP
#define GENETIC_ALGORITHM_RANDOM_HPP

#include <random>

class Random {
private:
    static std::random_device rd;
    static std::mt19937 generator;

public:
    static void start();
    static int randomInt(int min, int max);         // [min, max]
    static float randomFloat(float min, float max); // [min, max)
    static bool randomChance(float chance);
};


#endif //GENETIC_ALGORITHM_RANDOM_HPP
