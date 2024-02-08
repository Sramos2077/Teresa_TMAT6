using namespace vex;

extern brain Brain;

extern controller Control;
extern motor_group Gancho;
extern smartdrive Drivetrain;
extern motor_group Brazos_group;
extern digital_out Brazos_piston;
extern motor_group MotoresDerechos;
extern motor_group MotoresIzquierdos;
extern inertial Sensor_inertia;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);
