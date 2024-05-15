#include "Algorithm.hpp"

Algorithm &Algorithm::setSearchRangeT(Range range) {
    ranges.t = range;
    return *this;
}

Algorithm &Algorithm::setSearchRangeK(Range range) {
    ranges.k = range;
    return *this;
}

Algorithm &Algorithm::setSearchRangeDzeta(Range range) {
    ranges.dzeta = range;
    return *this;
}

Algorithm &Algorithm::setMutationProbability(float probability) {
    mutationProbability = probability;
    return *this;
}

Algorithm &Algorithm::setCrossoverProbability(float probability) {
    crossoverProbablity = probability;
    return *this;
}

Algorithm &Algorithm::setNumberOfIterations(int num) {
    numOfIterations = num;
    return *this;
}

Algorithm &Algorithm::setPopulationSize(int size) {
    populationSize = size;
    return *this;
}

Algorithm &Algorithm::setJumpCharacteristic(Characteristic& characteristic) {
    jumpCharacteristicValues = characteristic.generateCharacteristic(JUMP_FUNCTION);
    return *this;
}

Algorithm &Algorithm::setImpulseCharacteristic(Characteristic& characteristic) {
    impulseCharacteristicValues = characteristic.generateCharacteristic(IMPULSE_FUNCTION);
    return *this;
}

void Algorithm::generateRandomPopulation() {
    Individual individual;
    float randT, randK, randDzeta;

    while (population.size() < populationSize) {
        randT = Random::randomFloat(ranges.t.min, ranges.t.max);
        randK = Random::randomFloat(ranges.k.min, ranges.k.max);
        randDzeta = Random::randomFloat(ranges.dzeta.min, ranges.dzeta.max);

        individual
            .setT(randT)
            .setK(randK)
            .setDzeta(randDzeta);

        population.push_back(individual);
    }
}

void Algorithm::calculatePopulationFitness() {
    totalFitness = 0;

    for (auto& individual : population) {
        individual.calculateFitness(jumpCharacteristicValues, impulseCharacteristicValues);
        totalFitness += individual.getFitness();
    }
}

Individual Algorithm::getResult() {
    generateRandomPopulation();

    for (int i = 0; i < numOfIterations; i++) {
        calculatePopulationFitness();
    }
}

