#ifndef GENETIC_ALGORITHM_ALGORITHM_HPP
#define GENETIC_ALGORITHM_ALGORITHM_HPP

#include <iostream>
#include <algorithm>
#include "Ranges.hpp"
#include "Individual.hpp"
#include "progressbar.hpp"
#include "Params.hpp"

class Algorithm {
private:
    std::vector<Point> jumpCharacteristicValues;
    std::vector<Point> impulseCharacteristicValues;

    float mutationProbability { DEFAULT_PARAMS[MUTATION] };
    float crossoverProbability { DEFAULT_PARAMS[CROSSOVER] };
    int numOfIterations { static_cast<int>(DEFAULT_PARAMS[ITERATIONS]) };
    int populationSize { static_cast<int>(DEFAULT_PARAMS[POPULATION]) };

    Range rangeT = { DEFAULT_PARAMS[RANGE_T_MIN], DEFAULT_PARAMS[RANGE_T_MAX] };
    Range rangeK = { DEFAULT_PARAMS[RANGE_K_MIN], DEFAULT_PARAMS[RANGE_K_MAX] };
    Range rangeDzeta = { DEFAULT_PARAMS[RANGE_DZETA_MIN], DEFAULT_PARAMS[RANGE_DZETA_MAX] };

    Ranges ranges {
        rangeT, 
        rangeK, 
        rangeDzeta
    };

    std::vector<Individual> population;
    float totalFitness { 0 };
    progressbar* bar;

    void sortPopulation(std::vector<Individual>& populationToSort);
    void generateRandomPopulation();
    void calculatePopulationFitness();
    void calculatePopulationParenthood();
    void advancePopulation();
    void makeNextGeneration(std::vector<Individual>& newPopulation);
    void mutatePopulation();
    void createProgressBar();
    void updateProgressBar(int iteration);

public:
    ~Algorithm();

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
    void printPopulation();
};


#endif //GENETIC_ALGORITHM_ALGORITHM_HPP
