#ifndef GENETIC_ALGORITHM_INDIVIDUAL_HPP
#define GENETIC_ALGORITHM_INDIVIDUAL_HPP

#include "Characteristic.hpp"
#include "Random.hpp"
#include "Algorithm.hpp"
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

public:
    Individual& setT(float factor);
    Individual& setK(float factor);
    Individual& setDzeta(float factor);
    Individual& mutate(float chance, Algorithm::Ranges ranges);
    std::optional<Individual> getOffspring(Individual& targetParent, float chance);
    Individual& calculateFitness(
        std::vector<Characteristic::Point>& initialJump,
        std::vector<Characteristic::Point>& initalImpulse
    );

    float getT() const;
    float getK() const;
    float getDzeta() const;
};

#endif //GENETIC_ALGORITHM_INDIVIDUAL_HPP
