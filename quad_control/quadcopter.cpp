#include "quadcopter.h"

Quadcopter::Quadcopter(int FLpin, int FRpin, int BLpin, int BRpin) :
    FL(FLpin),
    FR(FRpin),
    BL(BLpin),
    BR(BRpin),
    desiredOri(0,0,0),
    orientation(0,0,0),
    pError(0,0,0),
    dError(0,0,0) {}

void Quadcopter::stopMotors() {
    FL.stop();
    FR.stop();
    BL.stop();
    BR.stop();
}

void Quadcopter::driveMotors(int FLy, int FLp, int FLr,
                             int FRy, int FRp, int FRr,
                             int BLy, int BLp, int BLr,
                             int BRy, int BRp, int BRr) {
    FL.go(kp*(FLy*pError.yaw + FLp*pError.pitch + FLr*pError.roll) +
          kd*(FLy*dError.yaw + FLp*dError.pitch + FLr*dError.roll));
    FR.go(kp*(FRy*pError.yaw + FRp*pError.pitch + FRr*pError.roll) +
          kd*(FRy*dError.yaw + FRp*dError.pitch + FRr*dError.roll));
    BL.go(kp*(BLy*pError.yaw + BLp*pError.pitch + BLr*pError.roll) +
          kd*(BLy*dError.yaw + BLp*dError.pitch + BLr*dError.roll));
    BR.go(kp*(BRy*pError.yaw + BRp*pError.pitch + BRr*pError.roll) +
          kd*(BRy*dError.yaw + BRp*dError.pitch + BRr*dError.roll));

    Serial.print(pError.pitch);
    Serial.print('\t');
    Serial.print(pError.roll);
    Serial.print('\t');
    Serial.print(FLy*pError.yaw + FLp*pError.pitch + FLr*pError.roll);
    Serial.print('\t');
    Serial.println(kp*(FLy*pError.yaw + FLp*pError.pitch + FLr*pError.roll) +
          kd*(FLy*dError.yaw + FLp*dError.pitch + FLr*dError.roll));
}

void Quadcopter::updateforPID() {
    Orientation lastpError = pError;
    pError = orientation - desiredOri;
    dError = pError - lastpError;
}