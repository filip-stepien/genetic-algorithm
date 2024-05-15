#include "Algorithm.hpp"
#include "Individual.hpp"

#include <fstream>

int main() {
    Characteristic jumpCharacteristic;
    Characteristic impulseCharacteristic;

    Algorithm algorithm;
    algorithm
        .setPopulationSize(100)
        .setNumberOfIterations(500)
        .setMutationProbability(0.2f)
        .setCrossoverProbability(0.4f)
        .setSearchRangeT({ 0.0f, 10.0f })
        .setSearchRangeK({ 0.0f, 10.0f })
        .setSearchRangeDzeta({ 0.0f, 1.0f })
        .setImpulseCharacteristic(impulseCharacteristic)
        .setJumpCharacteristic(jumpCharacteristic);


    Individual result = algorithm.getResult();
    result.print();

    return 0;
}
