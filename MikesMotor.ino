/*
This program uses the Adafruit motor shield to drive a motor forward and backward. Everytime the motor changes direction it prints either "Running forward" or "Running in reverse" or
"Motor has stopped."
*/

#include <Wire.h>
#include <Adafruit_MotorShield.h>
// These librarys are needed to run the motor driver circuit.

Adafruit_MotorShield FeatherBoard = Adafruit_MotorShield();
Adafruit_DCMotor *leftmotor = FeatherBoard.getMotor(1);


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);           // set up Serial library at 9600 bps
Serial.println("Adafruit Motorshield v2 - DC Motor test! \n \r");

  FeatherBoard.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
}

void loop() {
//Print forward
leftmotor->run(FORWARD);
leftmotor->setSpeed(125);
//run forward
Serial.println("Running forward \r");
// wait a second
delay(1000);

//Stop
leftmotor->run(RELEASE);
//Print Stopped
Serial.println("Motor has stopped \r");
//Wait a second
delay(1000);

leftmotor->run(BACKWARD);
leftmotor->setSpeed(125);
//run in reverse
Serial.println(BACKWARD, DEC);
Serial.println("Running reversed \r");
// wait a second
delay(1000);

//Stop
leftmotor->run(RELEASE);
//Print Stopped
Serial.println("Motor has stopped \r");
//Wait a second
delay(1000);
}
