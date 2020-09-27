#include "pch.h" 
#include <cmath>
#include "MathLibrary.h"

double geron(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return 0.5*abs((x3-x1)*(y2-y1)-(x2-x1)*(y3-y1));
}