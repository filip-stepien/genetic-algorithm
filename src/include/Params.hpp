#ifndef GENETIC_ALGORITHM_PARAMS_HPP
#define GENETIC_ALGORITHM_PARAMS_HPP

#include <string>
#include "Ranges.hpp"

enum Param {
    INIT_K,
    INIT_T,
    INIT_DZETA,
    CROSSOVER,
    MUTATION,
    RANGE_KT_MIN,
    RANGE_KT_MAX,
    RANGE_DZETA_MIN,
    RANGE_DZETA_MAX,
    ITERATIONS,
    POPULATION,
    PARAMS_SIZE
};

extern float DEFAULT_PARAMS[PARAMS_SIZE];
extern std::string PARAM_LABELS[PARAMS_SIZE];
extern std::string PARAM_ERRORS[PARAMS_SIZE];
extern Range PARAM_CONSTRAINTS[PARAMS_SIZE];
extern RangeType PARAM_CONSTRAINT_TYPES[PARAMS_SIZE];

#endif //GENETIC_ALGORITHM_PARAMS_HPP
