#include "paramchecker.h"

#include <iostream>






bool isWithinLimits(float input, std::pair<float, float> limits)
{
    if (input < limits.first || input > limits.second)
        return false;
    return true;
}
bool vitalsAreOk(float bpm, float spo2, float respRate) {
    HealthResult hrResult;
    Limits allLimits;
    hrResult.AddResult(BPM,isWithinLimits(bpm, allLimits.GetLimits(BPM)));
    hrResult.AddResult(SPO, isWithinLimits(spo2, allLimits.GetLimits(SPO)));
    hrResult.AddResult(RESP, isWithinLimits(respRate, allLimits.GetLimits(RESP)));

    if ((bool)(hrResult)!= true) return false;

    return true;
}
