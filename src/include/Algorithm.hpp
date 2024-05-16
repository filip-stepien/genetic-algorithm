#ifndef GENETIC_ALGORITHM_ALGORITHM_HPP
#define GENETIC_ALGORITHM_ALGORITHM_HPP

#include <iostream>
#include <algorithm>
#include "Ranges.hpp"
#include "Individual.hpp"
#include "progressbar.hpp"

class Algorithm {
private:
    std::vector<Point> jumpCharacteristicValues;
    std::vector<Point> impulseCharacteristicValues;
    Ranges ranges;
    float mutationProbability { 0.1f };
    float crossoverProbablity { 0.5f };
    int numOfIterations { 50 };
    int populationSize { 100 };

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
