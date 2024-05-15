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

void Algorithm::printPopulation() {
    for (auto& individual : population) {
        individual.print();
    }
}

void Algorithm::sortPopulation(std::vector<Individual>& populationToSort) {
    std::sort(populationToSort.begin(), populationToSort.end());
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

void Algorithm::calculatePopulationParenthood() {
    float probability, previousProbability = 1.0f;

    sortPopulation(population);

    for (auto& individual : population) {
        probability = previousProbability - (individual.getFitness() / totalFitness);
        previousProbability = probability;

        individual.setParenthoodProbability(probability);
    }
}

void Algorithm::makeNextGeneration(std::vector<Individual>& newPopulation) {
    sortPopulation(newPopulation);

    if (newPopulation.size() < populationSize) {
        for (int i = newPopulation.size(); i < populationSize; i++) {
            newPopulation.push_back(population[i]);
        }
    } else if (newPopulation.size() > populationSize) {
        while (newPopulation.size() != populationSize) {
            newPopulation.pop_back();
        }
    }

    population = { newPopulation };
}

void Algorithm::advancePopulation() {
    std::vector<Individual> newPopulation;
    Individual father, mother;
    std::optional<Individual> offspring;
    int randIndex;

    for (auto& individual : population) {
        individual.setMated(false);

        if (!Random::randomChance(individual.getParenthoodProbability()))
            continue;

        newPopulation.push_back(individual);
    }

    for (int i = 0; i < newPopulation.size(); i++) {
        father = newPopulation[i];

        if (father.didMate())
            continue;

        do {
            randIndex = Random::randomInt(i, newPopulation.size() - 1);
            mother = newPopulation[randIndex];

            if (!mother.didMate())
                mother.setMated(true);

        } while (!mother.didMate());

        offspring = father.getOffspring(mother, crossoverProbablity);

        if (offspring) {
            offspring->setMated(true);
            newPopulation.push_back(*offspring);
        }
    }

    makeNextGeneration(newPopulation);
}

void Algorithm::mutatePopulation() {
    for (auto& individual : population) {
        individual.mutate(mutationProbability, ranges);
    }
}

Individual Algorithm::getResult() {
    if (jumpCharacteristicValues.empty() || impulseCharacteristicValues.empty()) {
        std::cout << "Characteristics are not defined!" << std::endl;
        return {};
    }

    generateRandomPopulation();
    for (int i = 0; i < numOfIterations; i++) {
        mutatePopulation();
        calculatePopulationFitness();
        calculatePopulationParenthood();
        advancePopulation();
    }

    calculatePopulationFitness();
    sortPopulation(population);

    return population.front();
}

