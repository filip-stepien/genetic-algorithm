#ifndef GENETIC_ALGORITHM_INDIVIDUAL_HPP
#define GENETIC_ALGORITHM_INDIVIDUAL_HPP

#include "Characteristic.hpp"
#include "Random.hpp"
#include "SearchRanges.hpp"
#include <optional>
#include <utility>

class Individual {
private:
    static constexpr int CHROMOSOME_SIZE { 3 };

    union Genetic {
        struct {
            float k { 0 };
            float t { 0 };
            float dzeta { 0 };
        };
        float chromosome[CHROMOSOME_SIZE];
    } genetic;

    float fitness { 0 };
    float parenthoodProbability { 0 };

public:
    Individual& setT(float factor);
    Individual& setK(float factor);
    Individual& setDzeta(float factor);
    Individual& setParenthoodProbability(float probability);
    Individual& mutate(float chance, SearchRanges ranges);
    std::optional<Individual> getOffspring(Individual& targetParent, float chance);
    Individual& calculateFitness(
        std::vector<Point>& initialJump,
        std::vector<Point>& initalImpulse
    );

    float getT() const;
    float getK() const;
    float getDzeta() const;
    float getFitness() const;
    
    void print();

    bool operator<(const Individual& individual) const;
};

#endif //GENETIC_ALGORITHM_INDIVIDUAL_HPP
