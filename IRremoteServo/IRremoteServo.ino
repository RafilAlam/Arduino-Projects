#include <IRremote.hpp>

const int IR_RECEIVE_PIN = 19;
const int FanMotorPin = 17;
const int GrnledPin = 2;
const int RedledPin = 5;

int On = false;

void setup() {
  Serial.begin(115200);

  pinMode(GrnledPin, OUTPUT);
  pinMode(RedledPin, OUTPUT);

  pinMode(FanMotorPin, OUTPUT);
  
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
}

void loop() {
  if (IrReceiver.decode()) {
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);  // Print raw data in HEX
    IrReceiver.printIRResultShort(&Serial);  // Print decoded IR data for debugging
    IrReceiver.printIRSendUsage(&Serial);

    switch (IrReceiver.decodedIRData.decodedRawData) {
      case 0xEA15FF00: // Remote Button '+'
        On = true;
        break;

      case 0xF807FF00: // Remote Button '-'
        On = false;
        break;

      case 0xF609FF00: // Remote Button 'EQ'
        break;

      default:
        Serial.println("Unknown signal");  // Handle unrecognized signals
        break;
    }

    IrReceiver.resume();  // Prepare for the next signal
  }
  if (On) {
    digitalWrite(FanMotorPin, HIGH);

    digitalWrite(GrnledPin, HIGH);
    digitalWrite(RedledPin, LOW);
  } else {
    digitalWrite(FanMotorPin, LOW);

    digitalWrite(GrnledPin, LOW);
    digitalWrite(RedledPin, HIGH);
  }
}

