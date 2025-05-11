const int Motor1Pin1 = 22;
const int Motor1Pin2 = 23;

const int maxspeed = 100;

const int SonarTrigPin = 21;
const int SonarEchoPin = 34;

float duration;
float distance;

float Sigmoid(float x) {
  return 1 / (1 + exp(-x));
}

float PredictThrottle(float x) {
  return Sigmoid((x * 0.5) - 10);
}

void setup() {
  Serial.begin(115200);

  pinMode(Motor1Pin1, OUTPUT);
  pinMode(Motor1Pin2, OUTPUT);
  
  pinMode(SonarTrigPin, OUTPUT);
  pinMode(SonarEchoPin, INPUT);

  analogWriteFrequency(Motor1Pin1, 1000);
  analogWrite(Motor1Pin1, 0);
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

  Serial.println(String(PredictThrottle(distance)));

  analogWrite(Motor1Pin1, maxspeed * PredictThrottle(distance));
  delay(100);
}
