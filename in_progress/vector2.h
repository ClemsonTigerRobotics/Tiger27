#include <utility>
#include <iostream>
#ifndef VECTOR2_H_
#define VECTOR2_H_
class vector2 {
public:
    double x;
    double y;

    vector2 (double newx, double newy) {
    x = newx;
    y = newy;
    }

    double getX() {
       return x;
    }

    double getY() {
       return y;
    }

    double setX(double newx) {
       x = newx;
    }

    double setY(double newy) {
       y = newy;
    }
};

#endif VECTOR2_H_