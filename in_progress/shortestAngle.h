#include <cmath>

#ifndef SHORTESTANGLE_H_
#define SHORTESTANGLE_H_
double shortestAngle (double startAngle, double endAngle) {
    double out = std::fmod(endAngle - startAngle, 180);
    return out;
}
#endif SHORTESTANGLE_H_