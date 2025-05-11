const int Motor1Pin1 = 22;
const int Motor1Pin2 = 23;

int dutyCycle = 0;
int dutyCycleInc = 1;

void setup() {
  Serial.begin(115200);
  pinMode(Motor1Pin1, OUTPUT);
  pinMode(Motor1Pin2, OUTPUT);

  analogWriteResolution(Motor1Pin1, 16);
  analogWriteResolution(Motor1Pin2, 16);
}

void loop() {
  if (dutyCycle >= 0 && dutyCycle <= 255) {
    analogWrite(Motor1Pin2, dutyCycle);
  } else if (dutyCycle < 0 && dutyCycle >= -255) {
    analogWrite(Motor1Pin1, -dutyCycle);
  } else {
    dutyCycleInc *= -1;
  }
  Serial.println(dutyCycle);

  dutyCycle += dutyCycleInc;
  delay(50);
}
