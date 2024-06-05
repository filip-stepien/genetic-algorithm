#ifndef GENETIC_ALGORITHM_INDIVIDUAL_HPP
#define GENETIC_ALGORITHM_INDIVIDUAL_HPP

#include "Characteristic.hpp"
#include "Random.hpp"
#include "Ranges.hpp"
#include "VariadicTable.h"
#include <optional>
#include <utility>

class Individual {
private:
    static constexpr int CHROMOSOME_SIZE { 3 };

    union Genetic {
        struct {
            float k;
            float t;
            float dzeta;
        };
        float chromosome[CHROMOSOME_SIZE];
    } genetic { 0 };

    float fitness { 0 };
    float parenthoodProbability { 0 };
    bool mated { false };

public:
    Individual& setT(float factor);
    Individual& setK(float factor);
    Individual& setDzeta(float factor);
    Individual& setParenthoodProbability(float probability);
    Individual& setMated(bool didMate);
    Individual& mutate(float chance, Ranges ranges);
    std::optional<Individual> getOffspring(Individual& targetParent, float chance);
    Individual& calculateFitness(
        std::vector<Point>& initialJump,
        std::vector<Point>& initalImpulse
    );

    float getT() const;
    float getK() const;
    float getDzeta() const;
    float getFitness() const;
    float getParenthoodProbability() const;
    bool didMate() const;
    
    void print() const;

    bool operator<(const Individual& individual) const;
};

#endif //GENETIC_ALGORITHM_INDIVIDUAL_HPP
