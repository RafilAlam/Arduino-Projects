#include <ESP32Servo.h>

const int OpenbuttonPin = 22;
const int ClosebuttonPin = 23;

const int GrnledPin = 4;
const int RedledPin = 17;
const int servoPin = 18;

bool GateOpen = false;

Servo GateServo;


void gateOpen() {
  digitalWrite(GrnledPin, HIGH);
  digitalWrite(RedledPin, LOW);
}

void gateClose() {
  digitalWrite(GrnledPin, LOW);
  digitalWrite(RedledPin, HIGH);
}


void setup() {
  Serial.begin(115200);

  pinMode(OpenbuttonPin, INPUT);
  pinMode(ClosebuttonPin, INPUT);

  pinMode(GrnledPin, OUTPUT);
  pinMode(RedledPin, OUTPUT);

  gateClose();
}

int openButtonInput;
int closeButtonInput;

void loop() {
  openButtonInput = digitalRead(OpenbuttonPin);
  closeButtonInput = digitalRead(ClosebuttonPin);
  Serial.println(openButtonInput + closeButtonInput);

  if (openButtonInput == 1) {
    GateOpen = true;
  } else if (closeButtonInput == 1) {
    GateOpen = false;
  }

  if (GateOpen) {
    gateOpen();
  } else {
    gateClose();
  }
  delay(100);
}
