#include <Stepper.h>

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
const int stepsinDegree = 5.68888888889;
int Speed = 10;

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 18, 12, 19, 13);

void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(Speed);
}

void loop() {
  myStepper.step(90*stepsinDegree);
  myStepper.step(-90*stepsinDegree);
  myStepper.step(90*stepsinDegree);
}
