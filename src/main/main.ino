#include <Servo.h>
#include <Time.h>  

//FORMATO DE FECHA
#define TIME_MSG_LEN  11   // time sync to PC is HEADER followed by Unix time_t as ten ASCII digits
#define TIME_HEADER  'T'   // Header tag for serial time sync message
#define TIME_REQUEST  7    // ASCII bell character requests a time sync message 

//Crea el objeto del servo
Servo servo;
//Cre la variable para controlar la posicion del arduino. 0 = posicion inicial
int pos = 0;    // variable to store the servo position

void setup() {
  Serial.begin(9600);
  //Setea la fecha
  setTime(19,59,55,18,07,2016);
  //Setea el pin del servo
  servo.attach(9);  // attaches the servo on pin 9 to the servo object
  //Pone al servo en la posicion inicial
  servo.write(pos);
}

void loop() {
  Serial.println(hour());
  if(int(hour()) == 20) {
    for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      servo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(20);                       // waits 15ms for the servo to reach the position
    }
    delay(2000);                       // waits 15ms for the servo to reach the position
    for (pos = 90; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      servo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(20);                       // waits 15ms for the servo to reach the position
    }
    Serial.println(pos);
  }
}

