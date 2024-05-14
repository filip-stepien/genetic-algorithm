#include "Algorithm.hpp"

Algorithm &Algorithm::setSearchRangeT(std::pair<float, float> range) {
    rangeT = range;
    return *this;
}

Algorithm &Algorithm::setSearchRangeK(std::pair<float, float> range) {
    rangeK = range;
    return *this;
}

Algorithm &Algorithm::setSearchRangeDzeta(std::pair<float, float> range) {
    rangeDzeta = range;
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
