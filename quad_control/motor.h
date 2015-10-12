#ifndef MOTOR_H
#define MOTOR_H

#include <Servo.h>

// PID container
typedef struct {
    double p, i, d;
} PID;

/**
 * @brief Motor Class
 * A DC brushless motor on a quadcopter.
 */
class Motor {
public:
    Servo ctrl; ///< The servo object for this motor.
    PID err; ///< The P, I, and D errors for this motor.

    /**
     * @brief Create a motor object.
     * 
     * @param servPin Arduino pin.
     */
    Motor(int servPin);

    /**
     * @brief Cleanup and destroy this motor object.
     */
    ~Motor();

    /**
     * @brief Set motor speed.
     * 
     * @param speed Value between -1 and 1 corresponding to low speed and high speed.
     */
    void go(double speed);

    /**
     * @brief Stop this motor.
     */
    void stop();

private:
    /**
     * @brief Set the actual speed of the motor.
     * 
     * @param val Microsecond length of pulses to send to motor.
     */
    void setSpeed(int val);
};

#endif // MOTOR_H