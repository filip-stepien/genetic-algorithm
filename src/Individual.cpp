#include "Individual.hpp"
#include "Algorithm.hpp"

Individual& Individual::setT(float factor) {
    genetic.k = factor;
    return *this;
}

Individual& Individual::setK(float factor) {
    genetic.t = factor;
    return *this;
}

Individual& Individual::setDzeta(float factor) {
    genetic.dzeta = factor;
    return *this;
}

Individual& Individual::setParenthoodProbability(float probability) {
    parenthoodProbability = probability;
    return *this;
} 

float Individual::getT() const {
    return genetic.t;
}

float Individual::getK() const {
    return genetic.k;
}

float Individual::getDzeta() const {
    return genetic.dzeta;
}

float Individual::getFitness() const {
    return fitness;
}

void Individual::print() {
    std::printf("T: %d\tK: %d\tDZETA: %d\tJ: %d\n", getT(), getK(), getDzeta(), getFitness());
}

bool Individual::operator<(const Individual &individual) const {
    return this->fitness < individual.fitness;
}

Individual& Individual::calculateFitness(std::vector<Point>& initialJump, std::vector<Point>& initalImpulse) {
    Characteristic jump;
    std::vector<Point> currentJump = jump
        .setK(genetic.k)
        .setT(genetic.k)
        .setDzeta(genetic.dzeta)
        .generateCharacteristic(JUMP_FUNCTION);

    Characteristic impulse;
    std::vector<Point> currentImpulse = impulse
        .setK(genetic.k)
        .setT(genetic.t)
        .setDzeta(genetic.dzeta)
        .generateCharacteristic(IMPULSE_FUNCTION);

    float jumpDt, impulseDt;
    for (int i = 0; i < currentJump.size(); i++) {
        jumpDt = initialJump[i].y - currentJump[i].y;
        impulseDt = initalImpulse[i].y - currentImpulse[i].y;
        fitness += (jumpDt * jumpDt) + (impulseDt * impulseDt);
    }

    return *this;
}

Individual &Individual::mutate(float chance, SearchRanges ranges) {
    if (!Random::randomChance(chance))
        return *this;

    int trait = Random::randomInt(0, CHROMOSOME_SIZE - 1);
    genetic.chromosome[trait] = Random::randomFloat(
        ranges.all[trait].min,
        ranges.all[trait].max
    );

    return *this;
}

std::optional<Individual> Individual::getOffspring(Individual& targetParent, float chance) {
    if (!Random::randomChance(chance))
        return {};

    float avgT = (getT() + targetParent.getT()) / 2;
    float avgK = (getK() + targetParent.getK()) / 2;
    float avgDzeta = (getDzeta() + targetParent.getDzeta()) / 2;

    Individual offspring;
    return offspring
        .setT(avgT)
        .setK(avgK)
        .setDzeta(avgDzeta);
}