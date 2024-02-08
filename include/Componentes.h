#include "vex.h"
using namespace vex;
using signature = vision::signature;
using code = vision::code;
brain Brain;

controller Control = controller(primary);

//grupo de motores para el gancho o trepatubos
motor MotorGanchoA = motor(PORT19, ratio36_1, true);
motor MotorGanchoB = motor(PORT12, ratio36_1, false);
motor_group Gancho = motor_group(MotorGanchoA, MotorGanchoB);

//grupo de motores de la base del lado izquierdo
motor leftMotorA = motor(PORT11, ratio6_1, true);
motor leftMotorB = motor(PORT1, ratio6_1, true);
motor leftMotorC = motor(PORT2, ratio6_1, true);
motor_group MotoresIzquierdos = motor_group(leftMotorA, leftMotorB, leftMotorC);

//grupo de motores de la base del lado derecho
motor rightMotorA = motor(PORT20, ratio6_1, false);
motor rightMotorB = motor(PORT10, ratio6_1, false);
motor rightMotorC = motor(PORT9, ratio6_1, false);
//declaracion de toda la base
motor_group MotoresDerechos = motor_group(rightMotorA, rightMotorB, rightMotorC);
drivetrain Base = drivetrain(MotoresDerechos, MotoresIzquierdos);

//declaracion del sensor de inercia 
inertial Sensor_inertia = inertial(PORT17);
smartdrive Drivetrain = smartdrive(MotoresIzquierdos, MotoresDerechos, Sensor_inertia, 319.19, 320, 40, mm, 0.6);

//declaracion de motores de los brazos del motor
motor Brazo1 = motor(PORT16, ratio36_1, false);
motor Brazo2 = motor(PORT15, ratio36_1, true);
motor_group Brazos_group = motor_group(Brazo1, Brazo2);

//delcaracion de pistones para los ganchos de los brazos del robot
digital_out Brazos_Piston = digital_out(Brain.ThreeWirePort.H);

bool RemoteControlCodeEnabled = true;

void vexcodeInit( void ) {
    Brain.Screen.print("Device initialization...");
    Brain.Screen.setCursor(2, 1);
    wait(200, msec);
    Sensor_inertia.calibrate();
    Brain.Screen.print("Calibrating Inertial for Drivetrain");
    while (Sensor_inertia.isCalibrating()) {
        wait(25, msec);
    }
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1,1);
    wait(50, msec);
    Brain.Screen.clearScreen();
}
