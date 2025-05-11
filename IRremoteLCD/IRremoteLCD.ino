#include <IRremote.hpp>
#include <ESP32Servo.h>
#include <LiquidCrystal.h>

const int IR_RECEIVE_PIN = 19;
const int rs = 12, 

void setup() {
  Serial.begin(115200);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
}

void loop() {
  if (IrReceiver.decode()) {
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);  // Print raw data in HEX
    IrReceiver.printIRResultShort(&Serial);  // Print decoded IR data for debugging

    switch (IrReceiver.decodedIRData.decodedRawData) {
      case 0xEA15FF00: // Remote Button '+'
        Serial.println("Rotate to 90");
        break;

      case 0xF807FF00: // Remote Button '-'
        Serial.println("Rotate to 0");
        break;

      default:
        Serial.println("Unknown signal");  // Handle unrecognized signals
        break;
    }

    IrReceiver.resume();  // Prepare for the next signal
  }
}

