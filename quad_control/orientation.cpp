#include "orientation.h"

Orientation::Orientation(double y, double p, double r) :
    yaw(y), pitch(p), roll(r) {}

void Orientation::updateFromQ(Quaternion *q) {
    yaw = asin(2* q->x * q->y + 2* q->z * q->w) * 180/3.1415926535;
    pitch = atan2(2* q->y * q->w - 2* q->x * q->z, 1 - 2* q->y * q->y - 2* q->z * q->z) * 180/3.1415926535;
    roll = atan2(2* q->x * q->w - 2* q->y * q->z, 1 - 2* q->x * q->x - 2* q->z * q->z) * 180/3.1415926535;
}

Orientation Orientation::operator-(const Orientation &orient) {
    return Orientation(yaw-orient.yaw, pitch-orient.pitch, roll-orient.roll);
}