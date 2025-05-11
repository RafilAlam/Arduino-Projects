int ledPin = 1; // Built-in LED pin
void setup() {
  ledcAttach(ledPin, 5000, 8); // Attach GPIO2 to channel 0
}

void loop() {
    for (int duty = 0; duty <= 255; duty++) {
        ledcWrite(ledPin, duty); // Gradually increase brightness
        delay(3);
    }
    for (int duty = 255; duty >= 0; duty--) {
        ledcWrite(ledPin, duty); // Gradually decrease brightness
        delay(3);
    }
}
