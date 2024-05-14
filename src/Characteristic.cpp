#include "Characteristic.hpp"

Characteristic &Characteristic::setT(float factor) {
    t = factor;
    return *this;
}

Characteristic &Characteristic::setK(float factor) {
    t = factor;
    return *this;
}

Characteristic &Characteristic::setDzeta(float factor) {
    t = factor;
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
    int thresholdIterations = 0;

    for (float time = 0.0f; thresholdIterations <= MAX_THRESHOLD_ITERATIONS; time += TIME_STEP) {
        float funcValue = function == JUMP_FUNCTION ? jumpResponse(time) : impulseResponse(time);
        float lastValue = result.empty() ? 0 : result.back().y;

        if (std::abs(lastValue - funcValue) <= THRESHOLD_VALUE)
            thresholdIterations++;

        result.push_back({ time, funcValue });
    }

    return result;
}
