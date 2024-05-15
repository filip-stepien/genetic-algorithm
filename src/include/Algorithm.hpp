#ifndef GENETIC_ALGORITHM_ALGORITHM_HPP
#define GENETIC_ALGORITHM_ALGORITHM_HPP

#include <algorithm>
#include "SearchRanges.hpp"
#include "Individual.hpp"

class Algorithm {
private:
    std::vector<Point> jumpCharacteristicValues;
    std::vector<Point> impulseCharacteristicValues;
    SearchRanges ranges;
    float mutationProbability { 0.5f };
    float crossoverProbablity { 0.5f };
    int numOfIterations { 30 };
    int populationSize { 100 };

    std::vector<Individual> population;
    float totalFitness { 0 };

    void generateRandomPopulation();
    void calculatePopulationFitness();
    void performSelection();
    void performCrossover();
    void performMutation();

public:
    Algorithm& setSearchRangeT(Range range);
    Algorithm& setSearchRangeK(Range range);
    Algorithm& setSearchRangeDzeta(Range range);
    Algorithm& setMutationProbability(float probability);
    Algorithm& setCrossoverProbability(float probability);
    Algorithm& setNumberOfIterations(int num);
    Algorithm& setPopulationSize(int size);
    Algorithm& setJumpCharacteristic(Characteristic& characteristic);
    Algorithm& setImpulseCharacteristic(Characteristic& characteristic);
    Individual getResult();
};


#endif //GENETIC_ALGORITHM_ALGORITHM_HPP
