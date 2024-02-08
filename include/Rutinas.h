#include "Funciones.h"
//funcion para ejecutar la primera rutina del robot
void primera_estrategia(){
    Giro_PID(20.0); //gira 20 grados a la izquierda
    avance_con_tiempo_de_espera('F', 30, 13, 3); //avanza hacia adelante el robot 13 pulgadas 
    Giro_PID(0.0);//gira a su punto cero el robot
    avance_con_tiempo_de_espera('F', 80, 65, 3.5); //avanza el robot 65 pulgadas
    avance_por_tiempo('f', 1.3, 10); //avanza el robot 1.3 segundos hacia adelante
    wait(250,msec);
    Giro_PID(0.0);//el robot se acomoda derecho en su grado 0
    avance_por_tiempo('f', .300, 10);//el robot avanza hacia adelante 0.300 milisegundos 
    Giro_PID(-48.0);//el robot gira a la izquierda 48 grados
    avance_con_tiempo_de_espera('F', 10, 10.5, 2); // el robot avanza 10 pulgadas
    Brazos_Piston.set(1);//se contraen los brazitos del piston del robot
    sacar_triballs(1);//los brazos del robot giran solo una vez
    Brazos_Piston.set(0);//se abren los briztos del piston del robot
    avance_con_tiempo_de_espera('F', 10, 13.5, 2);//el robot avanza hacia adelante 10 pulgadas
    Sensor_inertia.resetRotation();//se reinicia el sensor de inercia
    Giro_PID(-48.0);//giro de 48 grados hacia la izquierda
    avance_con_tiempo_de_espera('F', 90, 15, 1.5);//el robot avanza hacia adelante 15 pulgadas
    avance_con_tiempo_de_espera('R', 20, 15, 1.5);//el robot avanza hacia atras 15 pulgdas para
    avance_con_tiempo_de_espera('F', 90, 15, 1.5);//el robot avanza hacia atras 15 pulgdas para
    avance_con_tiempo_de_espera('R', 20, 4.5, 2);//el robot avanza hacia atras 4.5 pulgadas
    wait(500, msec);
    Sensor_inertia.resetRotation();//se reincia el sensor de inercia en su punto cero
    Giro_PID(-90.0);//gira a la izquierda el robot 90 grados
    avance_con_tiempo_de_espera('F', 20, 51, 2);//avanza el robot 51 pulgadas
    Sensor_inertia.resetRotation();//se reinicia el sensor del robot 
    Giro_PID(90.0);//gira el robot a 90 grados a la izquierda 
    Giro_de_brazos(100, 50);//los brazos giran 100 grados
    avance_con_tiempo_de_espera('F', 20, 27, 2); //el robot avanza 27 pulgadas
    Sensor_inertia.resetRotation();//se reinicia el sensor de inercia
    turnRightWithIndividualSpeeds(90, 20, 0, 3);//el robot tratara de girar a sus 90 grados del lado derecho con solo un grupo de motores
    Giro_PID_con_constantes_aumentadas(90);//el robot retificara si llego a sus 90 y sino pues llega a los 90 grados
    avance_con_tiempo_de_espera('F', 80, 25, 1.5);//el robot avanzara 25 pulgadas  
    avance_con_tiempo_de_espera('R', 80, 25, 1.5);//el robot retrocedera 25 pulgadas  
    avance_con_tiempo_de_espera('F', 80, 25, 1.5);//el robot avanzara 25 pulgadas  
    avance_con_tiempo_de_espera('R', 50, 5, 1.5);//el robot retrocedera 5 pulgadas
    Giro_de_brazos(0, 100);//los brazos del robot giraran hacia atras o a su punto cero
    Sensor_inertia.resetRotation();//se reincia el sensor del robot asu punto cero 
    Giro_PID(90.0);//el robot girara a sus 90 grados a la izquierda
    avance_con_tiempo_de_espera('F', 40, 35, 3);// el robot avanzara 35 pulgadas 
    Giro_de_brazos(100, 50);//los brazos del robot giraran 100 grados
    Sensor_inertia.resetRotation();//se reinicia el sensor de inercia
    Giro_PID(90.0);//el robot girara 90 grados a la derecha
    avance_con_tiempo_de_espera('F', 80, 25, 3);//el robot avanzara 25 pulgadas
    Sensor_inertia.resetRotation();//el sensor de inercia se reinicia
    Giro_PID(-10.0);// el sensor de inercia gira 10 grados a la izquierda
    Brazos_Piston.set(1);//los brazos del piston se contraen 
    Giro_de_brazos(150, 100);
}

void copia_de_la_rutina_la_rutina_1(){
    Giro_PID(0.0);//se acomoda el robot en su punto 0
    avance_con_tiempo_de_espera('F', 80, 70, 2.5);//el robot avanza 70 pulgadas hacia adelante
    wait(250,msec);
    Giro_PID(0.0);//el robot se acomoda girando a su grado 0
    avance_por_tiempo('f', .380, 10); //el robot avanza 0.380 milisegundos
    Giro_PID(-48.0);//el robot gira 48 grados a la izquerida 
    Brazos_Piston.set(1);//los brazitos del piston se contraen
    sacar_triballs(1);//los brazos del robot giran solo una vez
    Brazos_Piston.set(0);//se abren los brazitos del piston del robot
    avance_con_tiempo_de_espera('F', 10, 5, 2);//el robot avanza 5 pulgadas
    Brazos_Piston.set(1);//los brazitos del piston se contraen
    sacar_triballs(1);//los brazos del robot giran solo una vez
    Brazos_Piston.set(0);//se abren los brazitos del piston del robot
    avance_con_tiempo_de_espera('F', 10, 8, 2);//el robot avanza 8 pulgadas
    Brazos_Piston.set(1);//los brazos del robot giran solo una vez
    sacar_triballs(1);//saca una vez la triball de la esquina
    Brazos_group.setTimeout(2, sec);//se espera dos segundos en caso de que no funcione la instruccion pasada
    Brazos_Piston.set(0);//se abren los pistones
    avance_con_tiempo_de_espera('F', 10, 8, 2);//avanza 8 pulgadas
    Sensor_inertia.resetRotation();//se reinicia el sensor
    Giro_PID(-48.0);//el robot girara 48 grados a la izquierda 
    avance_con_tiempo_de_espera('F', 90, 15, 1.5);//el robot avanzara 15 pulgadas
    avance_con_tiempo_de_espera('R', 20, 15, 1.5);//el robot retrocedera 15 pulgadas
    avance_con_tiempo_de_espera('F', 90, 15, 1.5);// el robot avanzara 15 pulgadas 
    avance_con_tiempo_de_espera('R', 20, 4.5, 2);//el robot retrocedera 4.5 pulgadas
    wait(500, msec);
    Sensor_inertia.resetRotation();// se reinicia el sensor de inercia 
    Giro_PID(-90.0);//el robot girara 90 grados a la izquierda  
    avance_con_tiempo_de_espera('F', 20, 51, 2);//el robot avanzara 51 pulgadas
    Sensor_inertia.resetRotation();//el sensor se reincia 
    Giro_PID(90.0);//el robot girara 90 grados a la izquierda
    Giro_de_brazos(100, 50);//los brazos del robot giraran 100 grados
    avance_con_tiempo_de_espera('F', 20, 27, 2);//el robot avanzara 27 pulgadas
    Sensor_inertia.resetRotation();//el sensor se reinicia
    turnRightWithIndividualSpeeds(90, 20, 0, 3);//el robot girara 90 grados a la derecha
    avance_con_tiempo_de_espera('F', 80, 25, 1.5);// el robot avanzara 25 pulgada
    avance_con_tiempo_de_espera('R', 80, 25, 1.5);// el robot retrocedera 25 pulgadas
    avance_con_tiempo_de_espera('F', 80, 25, 1.5);// el robot avanzara 25 pulgadas
    avance_con_tiempo_de_espera('R', 50, 5, 1.5);// el robot retrocedera 25 pulgadas
    Giro_de_brazos(0, 100);//los brazos retrocederan a su punto cero
    Sensor_inertia.resetRotation();// se reincia el sensor de inercia
    Giro_PID(90.0);//el robot gira 90 grados a la derecha
    avance_con_tiempo_de_espera('F', 40, 35, 3);// el robot avanzara 35 pulgadas hacia adelante
    Sensor_inertia.resetRotation();//se reinicia el sensor de inercia
    Giro_PID(90.0);//el robot girara 90 grados hacia la derecha
    Giro_de_brazos(100, 50);//los brazos del robot giraran a 100 grados
    avance_con_tiempo_de_espera('F', 80, 25, 3);// el robot avanzara 25 pulgadas hacia adelante
    Sensor_inertia.resetRotation();//se reinicia el sensor de inercia
    Giro_PID(-10.0);//el robot gira 10 grados a la izquierda
    Brazos_Piston.set(1);//el brazos del piston del robot se contraen
    Giro_de_brazos(180, 100);//giran 180 grados los brazos del robot
}

void segunda_estrategia(){
    Sensor_inertia.resetRotation();//se reinicia el sensor de inercia
    avance_con_tiempo_de_espera('F',70, 38, 2.5);// el robot avanzara 38 pulgadas hacia adelante
    Giro_de_brazos(100, 50);//giran 100 grados los brazos del robot
    Sensor_inertia.resetRotation();//se reinicia el sensor de inercia
    turnRightWithIndividualSpeeds(90.00, 30, 0, 3);//el robot girara 90 grados a la derecha
    Giro_PID_con_constantes_aumentadas(90);//el robot gira 10 grados a la derecha
    avance_con_tiempo_de_espera('F', 100, 30, 1);// el robot avanzara 30 pulgadas hacia adelant
    avance_con_tiempo_de_espera('R', 30, 20, 1);// el robot retrocedera 20 pulgadas hacia adelante
    Giro_PID_con_constantes_aumentadas(90.0);//el robot gira 90 grados a la derecha
    avance_con_tiempo_de_espera('F', 100, 30, 1);//el robot avanzara 30 pulgadas
    avance_con_tiempo_de_espera('R', 30, 20, 1);//el robot retrocedera 20 pulgadasd
    Giro_PID_con_constantes_aumentadas(90.0);//el robot girara 90 grados a la dercha
    avance_con_tiempo_de_espera('F', 100, 30, 1);//el robot avanzara 30 pulgadas hacia adelante
    Giro_PID_con_constantes_aumentadas(90.0);//el robot girara 90 grados a la dercha
    avance_con_tiempo_de_espera('R', 30, 35, 1);// el robot avanzara 35 pulgadas hacia adelante
    Giro_PID_con_constantes_aumentadas(90.0);//el robot girara 90 grados a la derecha
    Giro_de_brazos(0, 100);//el robot contraera sus brazos o llegara a su punto cero
    Sensor_inertia.resetRotation();// se reinica el sensor
    avance_por_tiempo('r', 0.100, 10);// el robot retrocedera 0.100 milisegundos 
    Giro_PID_con_constantes_aumentadas(90.00);// el robot girara 90 grados a la derecha
    avance_con_tiempo_de_espera('F', 70, 59, 2);// el robot avanzara 59 pulgadas
    Sensor_inertia.resetRotation();//se reinicia el sensor de inercia
    Giro_PID(0.00);//se acomoda el robot en su punto cero
    Giro_PID_con_constantes_aumentadas(-90.00);//el robot gira 90 grados a la izquierda
    Sensor_inertia.resetRotation();//el robot reinicia el sensor de inercia
    Giro_PID_con_constantes_aumentadas(0.00);//se acomoda el robot en su punto cero
    avance_con_tiempo_de_espera('F', 70, 75, 2.5);// el robot avanzara 75 pulgadas hacia adelante
    avance_por_tiempo('f', .500, 5);//el robot avanzara .500 milisegundos hacia adelante
    Giro_PID_con_constantes_aumentadas(0.00);//se acomoda el robot en su punto cero
    wait(250, msec);
    Giro_PID_con_constantes_aumentadas(-90.00);//el robot gira 90 grados a la izquierda
    avance_con_tiempo_de_espera('F', 30, 17, 1);// el robot avanzara 17 pulgadas hacia adelante
    Sensor_inertia.resetRotation();
    Giro_PID_con_constantes_aumentadas(-90.00);//el robot gira 90 grados a la izquierda
    avance_con_tiempo_de_espera('F', 70, 14, 1.5);
    Sensor_inertia.resetRotation();
    Giro_PID_con_constantes_aumentadas(90.0);// el robot girara 90 grados a la derecha
    Giro_de_brazos(70, 50);//los brazos del robot giraran 70 grados para llevarse las triballs
    avance_con_tiempo_de_espera('F', 70, 30, 2);// el robot avanzara 30 pulgadas hacia adelante
    Sensor_inertia.resetRotation();//se reinica el sensor
    turnRightWithIndividualSpeeds(90, 20, 0, 3);//el robot gira 90 grados a la derecha
    Giro_PID_con_constantes_aumentadas(90.0);// el robot se acomodara a sus 90 grados 
    avance_con_tiempo_de_espera('F', 80, 25, 1.5);// el robot avanzara 25 pulgadas hacia adelante
    avance_con_tiempo_de_espera('R', 80, 25, 1.5);// el robot retrocedera 25 pulgadas hacia adelante
    Giro_PID_con_constantes_aumentadas(90);// el robot se acomodara a sus 90 grados
    avance_con_tiempo_de_espera('F', 80, 25, 1.5);// el robot avanzara 25 pulgadas hacia adelante
    Giro_PID_con_constantes_aumentadas(90);// el robot se acomodara a sus 90 grados
    avance_con_tiempo_de_espera('R', 50, 5, 1.5);// el robot retrocedera 5 pulgadas hacia adelante
    Giro_PID_con_constantes_aumentadas(90);// el robot se acomodara a sus 90 grados
    Giro_de_brazos(0, 100);//los brazos del robot se retraen 
    Sensor_inertia.resetRotation();//se reinica el robot
    Giro_PID(90.0); //el robot gira 90 grados a la derecha
    avance_con_tiempo_de_espera('F', 40, 35, 3);// el robot avanzara 35 pulgadas hacia adelante
    Sensor_inertia.resetRotation();//se reinicia el sensor de inercia
    Giro_PID(90.0);//el robot girara 90 grados a la derecha
    Giro_de_brazos(100, 50);//los brazos del robot giran 100 grados 
    avance_con_tiempo_de_espera('F', 80, 28, 3);//los brazos del robot avanzaran 26 pulgadas
    Sensor_inertia.resetRotation();//se reinicia el sensor
    Giro_PID(-10.0);//el robot gira 10 grados a la izuwierda al poste
    Brazos_Piston.set(1);//contraen los pistones
    Giro_de_brazos(150, 100);//toca el poste a los 150 grados de los brazos
}
