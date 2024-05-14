#ifndef GENETIC_ALGORITHM_ALGORITHM_HPP
#define GENETIC_ALGORITHM_ALGORITHM_HPP

#include <utility>

class Algorithm {
public:
    constexpr static int RANGES_SIZE = 3;

    union Ranges {
        struct {
            std::pair<float, float> k { 0.1f, 10.0f };;
            std::pair<float, float> t { 0.1f, 10.0f };
            std::pair<float, float> dzeta { 0.01f, 0.99f };
        };
        std::pair<float, float> all[RANGES_SIZE];
    };

private:
    Ranges ranges;
    float mutationProbability { 0.5f };
    float crossoverProbablity { 0.5f };
    int numOfIterations { 30 };
    int populationSize { 100 };

public:
    Algorithm& setSearchRangeT(std::pair<float, float> range);
    Algorithm& setSearchRangeK(std::pair<float, float> range);
    Algorithm& setSearchRangeDzeta(std::pair<float, float> range);
    Algorithm& setMutationProbability(float probability);
    Algorithm& setCrossoverProbability(float probability);
    Algorithm& setNumberOfIterations(int num);
    Algorithm& setPopulationSize(int size);
};


#endif //GENETIC_ALGORITHM_ALGORITHM_HPP
