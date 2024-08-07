#include "main.h"

pros::Controller controller(pros::E_CONTROLLER_MASTER);

pros::Motor left_front(1, pros::E_MOTOR_GEAR_200, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor left_middle(2, pros::E_MOTOR_GEAR_200, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor left_back(3, pros::E_MOTOR_GEAR_200, false, pros::E_MOTOR_ENCODER_COUNTS);

pros::Motor right_front(4, pros::E_MOTOR_GEAR_200, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor right_middle(5, pros::E_MOTOR_GEAR_200, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor right_back(6, pros::E_MOTOR_GEAR_200, true, pros::E_MOTOR_ENCODER_COUNTS);

pros::MotorGroup right_drive({right_back, right_middle, right_front});
pros::MotorGroup left_drive({left_back, left_middle, left_front});
pros::MotorGroup drivetrain({right_back, right_middle, right_front, left_back, left_middle, left_front});

pros::Motor intake_motor(7, pros::E_MOTOR_GEAR_600, false, pros::E_MOTOR_ENCODER_COUNTS);

pros::ADIDigitalIn cylinder1('A');
pros::ADIDigitalIn cylinder2('B');


