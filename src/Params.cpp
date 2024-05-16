#include "Params.hpp"

float DEFAULT_PARAMS[PARAMS_SIZE] = {
    1.0f,   // INIT_K
    1.0f,   // INIT_T
    0.1f,   // INIT_DZETA
    0.1f,   // CROSSOVER
    0.5f,   // MUTATION
    0.1f,   // RANGE_KT_MIN
    10.0f,  // RANGE_KT_MAX
    0.01f,  // RANGE_DZETA_MIN
    0.99f,  // RANGE_DZETA_MAX
    50,     // ITERATIONS
    100     // POPULATION
};

std::string PARAM_LABELS[PARAMS_SIZE] = {
    "K",                // INIT_K
    "T",                // INIT_T
    "DZETA",            // INIT_DZETA
    "Crossover prob.",  // CROSSOVER
    "Mutation prob.",   // MUTATION
    "K, T range min.",  // RANGE_KT_MIN
    "K, T range max.",  // RANGE_KT_MAX
    "DZETA range min.", // RANGE_DZETA_MIN
    "DZETA range max.", // RANGE_DZETA_MAX
    "Iterations",       // ITERATIONS
    "Population"        // POPULATION
};

std::string PARAM_ERRORS[PARAMS_SIZE] = {
    "",                                 // INIT_K
    "",                                 // INIT_T
    "Must fit in range (0, 1).",        // INIT_DZETA
    "Must fit in range [0, 1].",        // CROSSOVER
    "Must fit in range [0, 1].",        // MUTATION
    "",                                 // RANGE_KT_MIN
    "Must fit in range (min, inf).",    // RANGE_KT_MAX
    "Must fit in range (0, 1).",        // RANGE_DZETA_MIN
    "Must fit in range (min, 1).",      // RANGE_DZETA_MAX
    "Must be greater than 0.",          // ITERATIONS
    "Must be greater than 0."           // POPULATION
};

Range PARAM_CONSTRAINTS[PARAMS_SIZE] = {
    { RANGE_MIN, RANGE_MAX },   // INIT_K
    { RANGE_MIN, RANGE_MAX },   // INIT_T
    { 0.0f, 1.0f },             // INIT_DZETA
    { 0.0f, 1.0f },             // CROSSOVER
    { 0.0f, 1.0f },             // MUTATION
    { RANGE_MIN, RANGE_MAX },   // RANGE_KT_MIN
    { RANGE_MIN, RANGE_MAX },   // RANGE_KT_MAX
    { 0.0f, 1.0f },             // RANGE_DZETA_MIN
    { 0.0f, 1.0f },             // RANGE_DZETA_MAX
    { 0.0f, RANGE_MAX },        // ITERATIONS
    { 0.0f, RANGE_MAX }         // POPULATION
};

RangeType PARAM_CONSTRAINT_TYPES[PARAMS_SIZE] = {
    {},         // INIT_K
    {},         // INIT_T
    EXCLUSIVE,  // INIT_DZETA
    INCLUSIVE,  // CROSSOVER
    INCLUSIVE,  // MUTATION
    {},         // RANGE_KT_MIN
    {},         // RANGE_KT_MAX
    EXCLUSIVE,  // RANGE_DZETA_MIN
    EXCLUSIVE,  // RANGE_DZETA_MAX
    EXCLUSIVE,  // ITERATIONS
    EXCLUSIVE   // POPULATION
};