const int GrnledPin = 2;
const int RedledPin = 16;

const int MotorIn1 = 23;
const int MotorIn2 = 22;

void setup() {
  Serial.begin(115200);
  pinMode(GrnledPin, OUTPUT);
  pinMode(RedledPin, OUTPUT);

  pinMode(MotorIn1, OUTPUT);
  pinMode(MotorIn2, OUTPUT);

  digitalWrite(GrnledPin, HIGH);
  digitalWrite(RedledPin, LOW);

  digitalWrite(MotorIn1, HIGH);
  digitalWrite(MotorIn2, LOW);
}

void loop() {
}
