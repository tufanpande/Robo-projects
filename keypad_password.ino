#include <Keypad.h>
#include <Servo.h>

Servo myServo;

// Password
String password = "1234";
String enteredPassword = "";

// Keypad Setup
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Pins
#define SERVO_PIN 10
#define BUZZER_PIN 11

void setup() {

  Serial.begin(9600);

  pinMode(BUZZER_PIN, OUTPUT);

  myServo.attach(SERVO_PIN);

  // Door starts locked
  myServo.write(0);

  Serial.println("=== KEYPAD DOOR LOCK ===");
  Serial.println("Password: 1234");
  Serial.println("Press # to confirm");
  Serial.println("Press * to clear");
  Serial.println("Press D to lock");
}

void loop() {

  char key = keypad.getKey();

  if (key) {

    Serial.print("Key Pressed: ");
    Serial.println(key);

    // Clear Password
    if (key == '*') {

      enteredPassword = "";
      Serial.println("Password Cleared");
    }

    // Lock Door
    else if (key == 'D') {

      myServo.write(0);
      Serial.println("Door Locked");
    }

    // Check Password
    else if (key == '#') {

      if (enteredPassword == password) {

        Serial.println("ACCESS GRANTED");

        digitalWrite(BUZZER_PIN, HIGH);
        delay(100);
        digitalWrite(BUZZER_PIN, LOW);

        myServo.write(90);   // Open Door
      }
      else {

        Serial.println("ACCESS DENIED");

        for (int i = 0; i < 3; i++) {

          digitalWrite(BUZZER_PIN, HIGH);
          delay(200);

          digitalWrite(BUZZER_PIN, LOW);
          delay(200);
        }

        myServo.write(0);   // Keep Door Locked
      }

      enteredPassword = "";
    }

    // Store Digits
    else {

      enteredPassword += key;

      Serial.print("Entered: ");
      Serial.println(enteredPassword);
    }
  }
}
