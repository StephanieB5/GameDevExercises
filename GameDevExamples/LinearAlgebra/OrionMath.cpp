#include <cmath>
#include "OrionMath.h"

namespace OrionMath
{
    bool IsEqual(float a, float b)
    {
        return std::fabs(a - b) < epsilon;
    }
}