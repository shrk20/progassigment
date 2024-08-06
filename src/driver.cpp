#include "main.h"
#include <cmath>
#include "globals.cpp"
#include "driver.h"


bool intakes_on = false;
bool mogos_on = false;

int curve_controls(int x)
{
    return static_cast<int>((1 / 16129.0) * pow(x, 3));
}

int enough(int number, int not_enough) {
    if(abs(number) < not_enough) {
        return 0;
    }
    return number;

}
void drive() {
    int forward = enough(-controller.get_analog(ANALOG_LEFT_Y), 10);
    int turning = enough(-controller.get_analog(ANALOG_RIGHT_X), 10);
    int left_voltage = forward + turning;
    int right_voltage = forward - turning;

    int forward_curve = curve_controls(forward);
    int turning_curve = curve_controls(turning);
    int left_voltage_curve = forward_curve + turning_curve;
    int right_voltage_curve = forward_curve - turning_curve;

    right_drive.move(-right_voltage_curve);
    left_drive.move(-left_voltage_curve);




}

void intake() {
    if(controller.get_digital(DIGITAL_L1)) {
        intakes_on = !intakes_on;
    }
    if(intakes_on) {
        intake_motor.move(127);
    }
}

void mogo() {
    if(controller.get_digital(DIGITAL_R1)) {
        mogos_on = !mogos_on;
    }
    if(mogos_on) {
       cylinder1.move_velocity(200);
       cylinder2.move_velocity(200);
    }
    else {
        cylinder1.move_velocity(0);
        cylinder2.move_velocity(0);
        
    }
}