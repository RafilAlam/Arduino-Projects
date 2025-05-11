#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C // Use the address detected by the I2C scanner

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int GrnledPin = 4;
const int RedledPin = 17;

const int sonarTrigPin = 23;
const int sonarEchoPin = 34;

long duration, distance;

void setup() {
  Wire.begin(21, 22);
  Serial.begin(115200);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  pinMode(sonarTrigPin, OUTPUT);
  pinMode(sonarEchoPin, INPUT);

  display.display();
  display.clearDisplay();
}

void PingSonar() {
  digitalWrite(sonarTrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(sonarTrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(sonarTrigPin, LOW);
}

void loop() {
  PingSonar();

  duration = pulseIn(sonarEchoPin, HIGH);
  distance = duration / 58.2;

  String disp = String(distance);
  String DisplayText = disp + " cm";

  Serial.println("Distance: " + disp);
  
  display.clearDisplay();
  display.setTextSize(3);      // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(0,0);     // Start at top-left corner
  display.println(DisplayText);
  display.display();

  delay(100);
}
