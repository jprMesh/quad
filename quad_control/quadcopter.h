#ifndef QUADCOPTER_H
#define QUADCOPTER_H

#include "motor.h"
#include "orientation.h"

// Quadcopter Class
class Quadcopter {
public:
    Quadcopter(int FLpin, int FRpin, int BLpin, int BRpin);

    void stopMotors();

    void driveMotors(int FLy, int FLp, int FLr,
                     int FRy, int FRp, int FRr,
                     int BLy, int BLp, int BLr,
                     int BRy, int BRp, int BRr);

    void updateforPID();

    Orientation desiredOri; ///< Desired orientation of the quadcopter.
    Orientation orientation; ///< Current orientation of the quadcopter.
    double kp;
    double ki;
    double kd;

private:
    Orientation pError;
    Orientation dError;
    Motor FL;
    Motor FR;
    Motor BL;
    Motor BR;
};

#endif // QUADCOPTER_H