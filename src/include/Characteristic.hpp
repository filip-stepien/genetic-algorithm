#ifndef GENETIC_ALGORITHM_CHARACTERISTIC_HPP
#define GENETIC_ALGORITHM_CHARACTERISTIC_HPP

#include <cmath>
#include <vector>

struct Point {
    float x;
    float y;
};

class Characteristic {
private:
    const float TIME_STEP { 0.1f };
    const float THRESHOLD_VALUE { 0.0001f };
    const int MAX_THRESHOLD_ITERATIONS { 10 };

    float t { 1.0f };
    float k { 1.0f };
    float dzeta { 0.5f };

    float jumpResponse(float time);
    float impulseResponse(float time);

public:
    using CharacteristicFunction = enum { JUMP_FUNCTION, IMPULSE_FUNCTION };

    Characteristic& setT(float factor);
    Characteristic& setK(float factor);
    Characteristic& setDzeta(float factor);

    std::vector<Point> generateCharacteristic(CharacteristicFunction function);
};


#endif //GENETIC_ALGORITHM_CHARACTERISTIC_HPP
