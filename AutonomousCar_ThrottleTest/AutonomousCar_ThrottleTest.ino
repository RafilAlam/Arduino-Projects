const int Motor1Pin1 = 22;
const int Motor1Pin2 = 23;

const int SonarTrigPin = 21;
const int SonarEchoPin = 34;

int dutyCycle = 60;
int dutyCycleInc = 1;

int duration;
int distance;

void Predict(input) {
  return (input * 1) - 20
}

void setup() {
  Serial.begin(115200);

  pinMode(Motor1Pin1, OUTPUT);
  pinMode(Motor1Pin2, OUTPUT);
  
  pinMode(SonarTrigPin, OUTPUT);
  pinMode(SonarEchoPin, INPUT);

  analogWriteFrequency(Motor1Pin1, 1000);
  analogWrite(Motor1Pin1, dutyCycle);
  delay(1000);
}

void PingSonar() {
  digitalWrite(SonarTrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(SonarTrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(SonarTrigPin, LOW);
}

void loop() {
  PingSonar();
  duration = pulseIn(SonarEchoPin, HIGH);
  distance = duration / 58.2;

  Serial.println(String(distance));

  analogWrite(Motor1Pin1, dutyCycle);
  Serial.println(dutyCycle);

  dutyCycle += dutyCycleInc;

  if (dutyCycle >= 255 || dutyCycle <= 60) {
    dutyCycleInc *= -1;
  }
  delay(100);
}
