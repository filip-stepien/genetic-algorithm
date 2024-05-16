#include "Algorithm.hpp"
#include "WindowUtils.hpp"

int main() {
    float params[PARAMS_SIZE];

    WindowUtils::printTitle();
    WindowUtils::printParamsTable(DEFAULT_PARAMS, "Default params");
    WindowUtils::getInput(params);
    WindowUtils::printParamsTable(params, "Selected params");
    WindowUtils::getConfirmation("Begin?", true);

    Characteristic jumpCharacteristic;
    jumpCharacteristic
        .setK(params[INIT_K])
        .setT(params[INIT_T])
        .setDzeta(params[INIT_DZETA]);

    Characteristic impulseCharacteristic;
    impulseCharacteristic
        .setK(params[INIT_K])
        .setT(params[INIT_T])
        .setDzeta(params[INIT_DZETA]);

    Algorithm algorithm;
    algorithm
        .setPopulationSize(params[POPULATION])
        .setNumberOfIterations(params[ITERATIONS])
        .setMutationProbability(params[MUTATION])
        .setCrossoverProbability(params[CROSSOVER])
        .setSearchRangeT({ params[RANGE_KT_MIN], params[RANGE_KT_MAX] })
        .setSearchRangeK({ params[RANGE_KT_MIN], params[RANGE_KT_MAX] })
        .setSearchRangeDzeta({ params[RANGE_DZETA_MIN], params[RANGE_DZETA_MAX] })
        .setImpulseCharacteristic(impulseCharacteristic)
        .setJumpCharacteristic(jumpCharacteristic);

    Individual result = algorithm.getResult();
    result.print();

    WindowUtils::getConfirmation("Press ENTER to exit.");

    return 0;
}
