#ifndef ORIENTATION_H
#define ORIENTATION_H

#include "helper_3dmath.h"

// Orientation object
class Orientation {
public:
    double yaw, pitch, roll; ///< In degrees.

    Orientation(double y, double p, double r);

    void updateFromQ(Quaternion *q);

    Orientation operator-(const Orientation &orient);
};

#endif // ORIENTATION_H