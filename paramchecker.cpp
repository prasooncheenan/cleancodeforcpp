#include "paramchecker.h"

#include <limits>
#include <functional>


std::pair<float,float> GetBPMLimits()
{
    return std::make_pair(70, 150);
}

std::pair<float, float> GetSPOLimits()
{
    return std::make_pair(80, std::numeric_limits<float>::max());
}

std::pair<float, float> GetRespRateLimits()
{
    return std::make_pair(30, 60);
}


bool isWithinLimits(float input, std::pair<float, float> limits)
{
    if (input < limits.first || input > limits.second)
        return false;
    return true;
}
bool vitalsAreOk(float bpm, float spo2, float respRate) {
    int check = isWithinLimits(bpm, GetBPMLimits());
    check += isWithinLimits(spo2, GetSPOLimits());
    check += isWithinLimits(respRate, GetRespRateLimits());

    if (check < 3) return false;

    return true;
}
