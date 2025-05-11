#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

#include <Wire.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 64, &Wire, -1);

String URL = "https://v2.jokeapi.dev/joke/Any?blacklistFlags=nsfw,explicit&type=twopart";

const char* ssid = "Linksys05341";
const char* password = "nxnxcpncay";

void setup() {
  Wire.begin(21, 22);
  Serial.begin(115200);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {

    HTTPClient http;

    //Set HTTP Request Final URL
    http.begin(URL);

    //Start connection and send HTTP Request
    int httpCode = http.GET();

    //httpCode will be negative on error
    if (httpCode > 0) {
      //Read Data as a JSON string
      String JSON_Data = http.getString();
      Serial.println(JSON_Data);

      //Retrieve the joke from the JSON format
      DynamicJsonDocument doc(2048);
      deserializeJson(doc, JSON_Data);
      JsonObject obj = doc.as<JsonObject>();

      const char* setup = obj["setup"].as<const char*>();
      const char* delivery = obj["delivery"].as<const char*>();

      //Display the Two parts of the joke
      display.clearDisplay();

      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);

      display.print("Setup: ");
      display.println(F(setup));
      display.print("\nDelivery: ");
      display.println(F(delivery));
      display.display();

    } else {
      Serial.println("Error!");
      delay(2000);
    }
    http.end();
  }
  delay(30000);
}
