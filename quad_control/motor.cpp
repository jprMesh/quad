#include "motor.h"
#include <Arduino.h>

Motor::Motor(int servPin) {
    ctrl.attach(servPin);
    Motor::stop();
}

Motor::~Motor() {
    Motor::stop();
    ctrl.detach();
}

void Motor::go(double speed) {
    speed = constrain(speed, -1.0, 1.0);
    int val = map(speed * 1024, -1024, 1024, 1170, 1450);
    setSpeed(val);
}

void Motor::stop() {
    Motor::setSpeed(1000);
}

void Motor::setSpeed(int val) {
    ctrl.writeMicroseconds(val);
}