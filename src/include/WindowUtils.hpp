#ifndef GENETIC_ALGORITHM_WINDOWUTILS_HPP
#define GENETIC_ALGORITHM_WINDOWUTILS_HPP

#include <iostream>
#include <limits>
#include "VariadicTable.h"
#include "Params.hpp"

class WindowUtils {
public:
    static void getInput(float params[PARAMS_SIZE]);
    static void printParamsTable(float params[PARAMS_SIZE], const std::string &title = "");
    static void getConfirmation(const std::string &text, bool ignore = false);
    static void printTitle();
};

#endif //GENETIC_ALGORITHM_WINDOWUTILS_HPP
