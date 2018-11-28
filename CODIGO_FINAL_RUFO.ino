
#include <Servo.h>
//Nombramos los servos con los nombres de las partes que van a mover//
Servo CACHITO;
Servo BOCA;
Servo PARPADO;
Servo OJOA;
Servo OJOL;
 
int i; //Esta variable nos permite hacer que los led deseados se prendan y apaguen paulatinamente//
int pos = 0; //Esta variable es para hacer que el arduino se mueva de cierta posición a otra paulatinamente//

//Definimos los nombres de los led que vamos a usar y el pin en el que se encontraran//

const int LED1A =1;
const int LED2A =2;
const int LED3A =3;
const int LED4A =4;
const int LED1V =5;
const int LED2V =6;
const int LED3V =7;
const int LED4V =8;


//Definimos el nombre de los pulsadores que vamos a usar y el pin en el que se encuentran//
const int BOTONT = 9;
const int BOTONV = 10;
//Definimos contadores o variables para establecer el estado de los pulsadores//
int val = 0; 
int state = 0; 
 

void setup(){  
//Definimos los pines a los cuales estan conectados los servos//
 CACHITO.attach(11); 
 BOCA.attach(12);
 PARPADO.attach(13);
 OJOA.attach(14); 
 OJOL.attach(15); 


 //Declaramos que dipo de dispositivo son los leds y los pulsadores (entrada-salida)//
 pinMode(LED1A,OUTPUT); 
  pinMode(LED2A,OUTPUT); 
   pinMode(LED3A,OUTPUT); 
    pinMode(LED4A,OUTPUT); 
    
 pinMode(LED1V,OUTPUT);
  pinMode(LED2V,OUTPUT);
   pinMode(LED3V,OUTPUT);
    pinMode(LED4V,OUTPUT);
 pinMode(BOTONT,INPUT); 
 pinMode(BOTONV,INPUT);


}

void loop() {      

//Usamos un condicional y las variables definidas anteriormente para declarar las acciones que se llevaran a acabo si el pulsador BOTONT esta encendido//


val= digitalRead(BOTONT); 
if ((val == HIGH)){


//Decimos que todos los leds van a estar en estado apagado//  
digitalWrite(LED1A, LOW);
digitalWrite(LED2A, LOW);
digitalWrite(LED3A, LOW);
digitalWrite(LED4A, LOW);

digitalWrite(LED1V, LOW); 
digitalWrite(LED2V, LOW); 
digitalWrite(LED3V, LOW); 
digitalWrite(LED4V, LOW);
delay(10);

//Declaramos la acción de los servos o su posición//
OJOA.write(150); 
    BOCA.write(0);

    //Basados en el ejemplo de Sweep de arduino usamos el for y la variable pos declarada con anterioridad para crear al servo una trayectoria dinámica haciendo que regrese a su posicion original//
for (pos = 170; pos <= 180; pos += 1) { 
    // in steps of 1 degree
    PARPADO.write(pos);              
    delay(20);                      
  }
  for (pos = 180; pos >= 170; pos -= 1) {
    PARPADO.write(pos);              
    delay(50);                      
  }
  
for (pos = 0; pos <= 180; pos += 1) { 
    OJOL.write(pos);             
    delay(15);                      
  }
  for (pos = 180; pos >= 0; pos -= 1) { 
    OJOL.write(pos);             
    delay(15);                       
  }
   

for (pos = 100; pos <= 180; pos += 1) { 
    CACHITO.write(pos);              
    delay(20);                       
  }
  for (pos = 180; pos >= 100; pos -= 1) { 
    CACHITO.write(pos);              
    delay(50);                      
  }



}

val= digitalRead(BOTONV); 
if ((val == HIGH)){

for(i=10; i<256; i++){ 
    analogWrite(LED1V,i);
    analogWrite(LED2V,i);
    analogWrite(LED3V,i);
    analogWrite(LED4V,i);
    delay(30);
  }

  for(i=255; i>10; i--){
    analogWrite(LED1V,i);
    analogWrite(LED2V,i);
    analogWrite(LED3V,i);
    analogWrite(LED4V,i);
    delay(10);
  }


digitalWrite(LED1A, LOW);
digitalWrite(LED2A, LOW);
digitalWrite(LED3A, LOW);
digitalWrite(LED4A, LOW);
delay(10);

for (pos = 30; pos <= 120; pos += 1) { 
    PARPADO.write(pos);              
    delay(20);                      
  }

 for (pos = 60; pos <= 170; pos += 1) { 
   OJOA.write(pos);              
    delay(10);                      
  }
  
  for (pos = 120; pos >= 30; pos -= 1) {
    PARPADO.write(pos);              
    delay(20);                      
  }
  

  for (pos = 170; pos >= 60; pos -= 1) {
    OJOA.write(pos);              
    delay(10);                      
  }
  
for (pos = 10; pos <= 170; pos += 1) { 
   OJOL.write(pos);              
    delay(5);                      
  }
  for (pos = 170; pos >= 10; pos -= 1) {
    OJOL.write(pos);              
    delay(5);                      
  }
  for (pos = 140; pos >= 60; pos -= 1) {
    CACHITO.write(pos);              
    delay(40);                      
  }
for (pos = 60; pos <= 140; pos += 1) { 
   CACHITO.write(pos);              
    delay(5);                      
  }

BOCA.write(0);


}

//Definimos las variables declaradas con anterioridad y con ayuda de un condicionales hicimos que si el BOTON1 y el BOTON 2 estan apagados algunos leds y servos se enciendan//
val= digitalRead(BOTONT); 
state= digitalRead(BOTONV); 
if ((val == LOW) && (state == LOW)){
digitalWrite(LED1A,HIGH);
delay(10); 
digitalWrite(LED2A,HIGH);
delay(10); 
digitalWrite(LED3A,HIGH);
delay(10); 
digitalWrite(LED4A,HIGH); 
delay(10);

digitalWrite(LED1A, LOW);
delay(20);
digitalWrite(LED2A, LOW);
delay(20);
digitalWrite(LED3A, LOW);
delay(20);
digitalWrite(LED4A, LOW);
delay(20);

digitalWrite(LED1V, LOW); 
digitalWrite(LED2V, LOW); 
digitalWrite(LED3V, LOW); 
digitalWrite(LED4V, LOW); 

for (pos = 20; pos <= 60; pos += 1) { 
    // in steps of 1 degree
    PARPADO.write(pos);  
    //Este delay  permite hacer más rápidos o lentos lo movimientos de los servoa//              
    delay(random(5,30));  
    }
  for (pos = 60; pos >= 20; pos -= 1) {
    PARPADO.write(pos);              
    delay(random(5,30));                      
  }


 for (pos = 120; pos >= 10; pos -= 1) {
    OJOA.write(pos);              
    delay(5);                      
  }

for (pos = 180; pos >= 10; pos -= 1) {
    OJOL.write(pos);              
    delay(5);                      
  }
 for (pos = 10; pos >= 120; pos -= 1) {
    OJOA.write(pos);              
    delay(5);                      
  }
for (pos = 180; pos >= 10; pos -= 1) {
    OJOL.write(pos);              
    delay(5);                      
  }                      
  
for (pos = 5; pos <= 40; pos += 1) { 
    // in steps of 1 degree
    CACHITO.write(pos);                
    delay(5);  
    }
  for (pos = 40; pos >= 5; pos -= 1) {
    CACHITO.write(pos);              
    delay(5);                      
  }

 for (pos = 50; pos >= 5; pos -= 1) {
    CACHITO.write(pos);              
    delay(5);                      
  }
 for (pos = 5; pos >= 50; pos -= 1) {
    CACHITO.write(pos);              
    delay(5);                      
  }

BOCA.write(170);
  
}
}
