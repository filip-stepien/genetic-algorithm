#include "Characteristic.hpp"

Characteristic &Characteristic::setT(float factor) {
    t = factor;
    return *this;
}

Characteristic &Characteristic::setK(float factor) {
    k = factor;
    return *this;
}

Characteristic &Characteristic::setDzeta(float factor) {
    dzeta = factor;
    return *this;
}

float Characteristic::jumpResponse(float time) {
    using namespace std;
    float exponent = exp(-dzeta * time / t);
    float sqRoot = sqrt(1 - dzeta * dzeta);
    return k * (1 - (exponent / sqRoot) * sin(sqRoot * time / t + atan(sqRoot / dzeta)));
}

float Characteristic::impulseResponse(float time) {
    using namespace std;
    float exponent = exp(-dzeta * time / t);
    float sqRoot = sqrt(1 - dzeta * dzeta);
    return (k * exponent) / (t * sqRoot) * sin(sqRoot * time / t);
}

std::vector<Point> Characteristic::generateCharacteristic(CharacteristicFunction function) {
    std::vector<Point> result;
    float funcValue;

    for (float time = 0.0f; time <= MAX_TIME; time += TIME_STEP) {
        funcValue = function == JUMP_FUNCTION ? jumpResponse(time) : impulseResponse(time);
        result.push_back({ time, funcValue });
    }

    return result;
}

void Characteristic::print(std::vector<Point> points) {
    for (auto& p : points) {
        std::cout << p.x << "," << p.y << std::endl;
    }
}
