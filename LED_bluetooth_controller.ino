#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11); // RX, TX

#define RED_LED 7
#define GREEN_LED 8

char data;

void setup() {

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  Serial.begin(9600);
  BT.begin(9600);

  Serial.println("Bluetooth LED Controller Ready");
}

void loop() {

  if (BT.available()) {

    data = BT.read();

    Serial.print("Received: ");
    Serial.println(data);

    if (data == '1') {
      digitalWrite(RED_LED, HIGH);
    }

    else if (data == '0') {
      digitalWrite(RED_LED, LOW);
    }

    else if (data == '2') {
      digitalWrite(GREEN_LED, HIGH);
    }

    else if (data == '3') {
      digitalWrite(GREEN_LED, LOW);
    }
  }
}
