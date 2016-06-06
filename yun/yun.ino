#include <Bridge.h>
#include <BridgeServer.h>
#include <BridgeClient.h>
#include <LiquidCrystal.h>
#include <Wire.h>

BridgeServer server;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
byte x = 0;

void setup() {
  // When LED on pin 13 is on the Bridge library is ready.
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Bridge.begin();
  digitalWrite(13, HIGH);

  // Start listening on localhost connecctions.
  server.listenOnLocalhost();
  server.begin();

  // Start the Wire library.
  Wire.begin();

  // Start LCD communication.
  lcd.begin(16, 2);
}

void loop() {
   // Get clients coming from server.
  BridgeClient client = server.accept();

  // There is a new client?
  if (client) {
    // Process request.
    process(client);

    // Close connection and free resources.
    client.stop();
  }

  delay(50); // Poll every 50ms
}

void process(BridgeClient client) {
  // Extract data from URL.
  String username = client.readStringUntil('/');
  int score = client.parseInt();

  // Print on LCD.
  lcd.setCursor(0, 0);
  lcd.print(username);
  lcd.setCursor(0, 1);
  lcd.print("Your score is " + score);

  // Send response to the client.
  client.print(username + " your score is " + score);

  // Begin Wire transmission to I2C with address 8.
  Wire.beginTransmission(8);

  // Send one byte to slave and turn on/off LED 13.
  if(score > 8) {
    Wire.write(1);
    digitalWrite(13, HIGH);
  }
  else {
    Wire.write(0);
    digitalWrite(13, LOW);
  }

  // Close I2C transmission.
  Wire.endTransmission();
}


