#ifndef GENETIC_ALGORITHM_CHARACTERISTIC_HPP
#define GENETIC_ALGORITHM_CHARACTERISTIC_HPP

#include <cmath>
#include <vector>
#include <iostream>
#include "Params.hpp"

struct Point {
    float x;
    float y;
};

using CharacteristicFunction = enum CharacteristicFunction { JUMP_FUNCTION, IMPULSE_FUNCTION };

class Characteristic {
private:
    static constexpr float TIME_STEP { 0.1f };
    static constexpr float MAX_TIME { 30.0f };

    float t { DEFAULT_PARAMS[INIT_T] };
    float k { DEFAULT_PARAMS[INIT_K] };
    float dzeta { DEFAULT_PARAMS[INIT_DZETA] };

    float jumpResponse(float time);
    float impulseResponse(float time);

public:
    Characteristic& setT(float factor);
    Characteristic& setK(float factor);
    Characteristic& setDzeta(float factor);

    std::vector<Point> generateCharacteristic(CharacteristicFunction function);
    static void print(std::vector<Point> points);
};

#endif //GENETIC_ALGORITHM_CHARACTERISTIC_HPP
