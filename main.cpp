#include "mbed.h"
#include "MotorControl.hpp"

MotorCtrl motor1(D4, D5, D12, D11);
MotorCtrl motor2(D7, D8, PB_1, PB_2);

float setpoint1 = 20.0;
float setpoint2 = 10.0;

int main() {
    
    motor1.motor.set_pid_gain(20.0, 0.001, 0.005, 0.0);
    motor2.motor.set_pid_gain(20.0, 0.001, 0.005, 0.0);

    motor1.set_encoder_resolution(0.0007633);
    motor1.init();
    motor1.start();

    motor2.set_encoder_resolution(0.0007633);
    motor2.init();
    motor2.start();

    while(1) {
        motor1.update();
        motor1.setSpeed(setpoint1);

        motor2.update();
        motor2.setSpeed(setpoint2);

        printf("%f, %f, %f, %f\n",setpoint1, setpoint2, motor1.getMotorSpeed(), motor2.getMotorSpeed());

        wait_us(1000);
    }
    
}