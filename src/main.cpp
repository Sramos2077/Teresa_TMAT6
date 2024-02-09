/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "Rutinas.h"
using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
//se inician antes del autonomo en 0 grados el sensor de inercia y los brazos
void pre_auton(void) {
  Sensor_inertia.setRotation(0, deg);
  Brazos_group.setPosition(0, deg);
  Brazos_group.stop(hold);
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
//variable para escoger una opcion de rutina en el switch
int seleccion_rutina = 2;
void autonomous(void) {
  Brazos_group.stop(hold);
  Brazos_group.setPosition(0, deg);
  Drivetrain.stop(hold);
  Sensor_inertia.setRotation(0, deg);
//seleccion de rutinas mediante la variable de arriba
  switch (seleccion_rutina){
    case 0:
      primera_estrategia();
      break;
    case 1:
      copia_de_la_rutina_la_rutina_1();
      break;
    case 2:
      segunda_estrategia_con_WP();
      break;

  //si no se haya ninguna rutina en el swtich se imprimira este mensaje
    default:
      Brain.Screen.print("any autonomous");
      break;
  }
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  //se inician en 100 pct los motores de la base y los brazos
  MotoresDerechos.setVelocity(100, pct);
  MotoresIzquierdos.setVelocity(100, pct);

  Drivetrain.setStopping(hold);
  MotorGanchoA.setVelocity(100, pct);
  MotorGanchoB.setVelocity(100, pct);

  double vel = 127 / 100;
  int k = 1;
  while (1) {
    //jousticks del lado izquierdo de la base
      MotoresIzquierdos.spin(forward, Control.Axis3.value() / vel * 0.75, percent);
  //jousticks del lado derecho de la base
      MotoresDerechos.spin(forward, Control.Axis2.value() / vel * 0.75, percent);
        
    //si se precionan L1 los ganchos del robot van hacia arriba si se preciona L2 se agachan
    if(Control.ButtonL1.pressing()){
        Gancho.setVelocity(100, pct);
        Gancho.spin(fwd);
    }
    else if(Control.ButtonL2.pressing()){
      Gancho.spin(reverse);
    }
    else{
      Gancho.stop(hold);
    }

  //si se preciona r1 los brazos del robot van hacia adelante, si se preciona r2 van hacia atras
      if(Control.ButtonR1.pressing()){
      Brazos_group.setVelocity(100, pct);
      Brazos_group.spin(fwd);
    }
    else if(Control.ButtonR2.pressing()){
      Brazos_group.setVelocity(100, pct);
      Brazos_group.spin(reverse);
    }
    else{
      Brazos_group.stop(hold);
    }

  //si se preciona UP una vez se activan los pistones si se preciona otra vez se apagan
    if(Control.ButtonUp.pressing()&& k == 1){
      Brazos_Piston.set(1);
      wait(200, msec);
      k = 2;
    }
    else if(Control.ButtonUp.pressing()&& k == 2){
      Brazos_Piston.set(0);
      wait(200, msec);
      k = 1;
    }

//si se preciona el boton X va hacia adelante el robot
    if (Control.ButtonX.pressing()){
      Hacia_adelante();
    }
//si se preciona el boton B va hacia atras el robot
    if(Control.ButtonB.pressing()){
      Hacia_atras();
    }

    wait(20, msec); 
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    //se imprimen los grados de la base en el control
    Control.Screen.setCursor(1,1);
    Control.Screen.print("DEG: %f", Drivetrain.rotation(deg));
    wait(100, msec);
  }
}

