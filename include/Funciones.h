#include "Componentes.h"

//Funcion para que la base del robot conduzca hacia adelante
void Hacia_adelante(){
    MotoresIzquierdos.spin(forward);
    MotoresDerechos.spin(forward);
}

//funcion para que la base del robot conduzca hacia atras
void Hacia_atras(){
    Drivetrain.drive(reverse);
}

/*Funcion con toma de desiciones, si es 'F' que la base conduzca hacia adelante,
si es 'R' que la base conduzca hacia atras*/
void avance(char dir, int velocidad, double ava){
    Drivetrain.setDriveVelocity(velocidad, pct);
    Drivetrain.stop(hold);
    if (dir == 'F'){ // forward
        Drivetrain.driveFor(forward, ava, inches);
    }
    else if (dir == 'R'){ // reverse
        Drivetrain.driveFor(reverse, ava, inches);
    }
}

//Funcion similar a la anterior pero con un tiempo de espera donde si falla esta funcion sigue con la siguiente instruccion de la rutina 
void avance_con_tiempo_de_espera(char dir, int velocidad, double ava, double tiempo){
    Drivetrain.setTimeout(tiempo, sec);
    Drivetrain.setDriveVelocity(velocidad, pct);
    Drivetrain.stop(hold);
    if (dir == 'F'){
        Drivetrain.driveFor(fwd, ava, inches);
    }
    else if (dir == 'R'){
        Drivetrain.driveFor(reverse, ava, inches);
    }
    Drivetrain.stop(hold);
}


//funcion que sirve para hacer girar el robot mediante heading
void Giro_mediante_heading(double cuanto, double tiempo){
Drivetrain.setTimeout(tiempo, sec);
Drivetrain.setHeading(0, deg);
float margen_de_error = 0.05;
    while(Sensor_inertia.rotation(deg) < cuanto - margen_de_error){
        Drivetrain.turnToHeading(cuanto, deg);
    }
    Drivetrain.stop(hold);
}

//funcion similar a la anterior pero con pulgadas desde su punto cero
void Giro_mediante_position(double cuanto){
//Drivetrain.setTimeout(tiempo, sec);
Drivetrain.setRotation(0, deg);
float margen_de_error = 0.05;
    while(Sensor_inertia.rotation(deg) < cuanto){
        Drivetrain.turnToRotation(cuanto - margen_de_error, deg);
    }
    Drivetrain.stop(hold);
}


//funcion tambien para el giramiento del robot mediante una formula para evadir errores de giros
void Giro_PID (double gradosDeseados){
    double kp=0.4, ki=.9, kd=0.03;/*double kp=0.5, ki=1, kd=0.035;*/
    double gradosActual = 0.0, error = 0.0, errorPrev = 0.0, 
    proporcional = 0.0, integral = 0.0, derivada = 0.0, salida = 0.0;
    bool saturacion = true;
    double tiempoInicial = Brain.timer(sec);
    double tiempoLimite = 10.0;
    double tolerancia = 0.4;
    while((Brain.timer(sec) - tiempoInicial) < tiempoLimite){
    gradosActual = Sensor_inertia.rotation(degrees);
    error = gradosDeseados - gradosActual;
    if(fabs(error) < tolerancia){
    Drivetrain.stop(hold);
        break;
    }
    proporcional = error * kp;
    if(!saturacion){
      integral += (error*0.02) * ki;
    }
    if(integral > 3){
        integral = 3;
    }
    else if(integral < -3){
        integral = -3;
    }
    derivada = ((error - errorPrev)/0.02) * kd;
    salida = proporcional + integral + derivada;
    if(salida > 12){
        salida = 12;
    }
    else if(salida < -12){
        salida = -12;
    }
    saturacion = fabs(salida) >= 4;
    MotoresIzquierdos.spin(fwd, salida, volt);
    MotoresDerechos.spin(fwd, -salida, volt);
    errorPrev = error;
    wait(20, msec);
    }
    Drivetrain.stop(hold);
}

//similar a la anterior pero con la constante subida
void Giro_PID_con_constantes_aumentadas (double gradosDeseados){
    double kp=0.5, ki=.9, kd=0.03;
    double gradosActual = 0.0, error = 0.0, errorPrev = 0.0, 
    proporcional = 0.0, integral = 0.0, derivada = 0.0, salida = 0.0;
    bool saturacion = true;
    double tiempoInicial = Brain.timer(sec);
    double tiempoLimite = 10.0;
    double tolerancia = 0.4;
    while((Brain.timer(sec) - tiempoInicial) < tiempoLimite){
    gradosActual = Sensor_inertia.rotation(degrees);
    error = gradosDeseados - gradosActual;
    if(fabs(error) < tolerancia){
    Drivetrain.stop(hold);
        break;
    }
    proporcional = error * kp;
    if(!saturacion){
      integral += (error*0.02) * ki;
    }
    if(integral > 3){
        integral = 3;
    }
    else if(integral < -3){
        integral = -3;
    }
    derivada = ((error - errorPrev)/0.02) * kd;
    salida = proporcional + integral + derivada;
    if(salida > 12){
        salida = 12;
    }
    else if(salida < -12){
        salida = -12;
    }
    saturacion = fabs(salida) >= 4;
    MotoresIzquierdos.spin(fwd, salida, volt);
    MotoresDerechos.spin(fwd, -salida, volt);
    errorPrev = error;
    wait(20, msec);
    }
    Drivetrain.stop(hold);
}


//funcion para hacer girar los brazos del robot mediante grados
void Giro_de_brazos(int d, int vel){
    Brazos_group.setVelocity(vel, pct); 
    Brazos_group.spinToPosition(d, degrees);
    Brazos_group.stop(hold);
}

//funcion para sacar las triballs mediante los giros de los brazos con las veces que se declaren
void sacar_triballs(int veces){
    Drivetrain.stop(hold);
    Brazos_group.setPosition(0, deg);
    Brazos_group.setVelocity(100, pct);
    repeat(veces){
        Brazos_group.spinToPosition(120, deg);
        wait(100, msec);
        Brazos_group.spinToPosition(0, deg);
    }
}

//funcion para el avance del robot que en vez de utilizar pulgadas, se declara el tiempo en que debe conducir el robot
void avance_por_tiempo(char dir, double tiempo, int vel){
    Drivetrain.stop(hold);
    Drivetrain.setDriveVelocity(vel, pct);
    if (dir == 'f' || dir == 'F'){
        MotoresIzquierdos.spin(fwd);
        MotoresDerechos.spin(fwd);
        wait(tiempo, sec);
        MotoresIzquierdos.stop(hold);
        MotoresDerechos.stop(hold);
    }
    else if (dir == 'r' || dir == 'R'){
        MotoresIzquierdos.spin(reverse);
        MotoresDerechos.spin(reverse);
        wait(tiempo, sec);
        MotoresIzquierdos.stop(hold);
        MotoresDerechos.stop(hold);
    }
    else{
        MotoresIzquierdos.stop(hold);
        MotoresDerechos.stop(hold);
    }
}

//funcion para hacer girar el robot hacia la derecha 
void turnRightWithIndividualSpeeds(double degrees, int leftSpeed, int rightSpeed, double tiempo) {
  Drivetrain.setTimeout(tiempo, sec);
  MotoresIzquierdos.spin(forward, leftSpeed, pct);
  MotoresDerechos.spin(reverse, rightSpeed, pct);
  waitUntil(Sensor_inertia.rotation(deg) >= degrees);
  MotoresIzquierdos.stop(hold);
  MotoresDerechos.stop(hold);
}