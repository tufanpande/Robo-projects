#include <Servo.h>

// ----------------------
// Road 1 LEDs
// ----------------------
#define LEDR1 2
#define LEDY1 3
#define LEDG1 4

// ----------------------
// Road 2 LEDs
// ----------------------
#define LEDR2 5
#define LEDY2 6
#define LEDG2 7

// ----------------------
// Servo Objects
// ----------------------
Servo servo1;
Servo servo2;

// ----------------------
// Setup
// ----------------------
void setup() {

  pinMode(LEDR1, OUTPUT);
  pinMode(LEDY1, OUTPUT);
  pinMode(LEDG1, OUTPUT);

  pinMode(LEDR2, OUTPUT);
  pinMode(LEDY2, OUTPUT);
  pinMode(LEDG2, OUTPUT);

  servo1.attach(8);
  servo2.attach(9);

  // Initial Gate Position
  servo1.write(0);
  servo2.write(0);
}

// ----------------------
// Main Loop
// ----------------------
void loop() {

  // ==========================
  // ROAD 2 GREEN
  // ==========================

  digitalWrite(LEDR1, HIGH);
  digitalWrite(LEDG2, HIGH);

  openServo2();

  delay(5000);

  digitalWrite(LEDG2, LOW);
  digitalWrite(LEDY2, HIGH);

  halfServo2();

  delay(2000);

  digitalWrite(LEDY2, LOW);

  closeServo2();

  digitalWrite(LEDR1, LOW);

  // ==========================
  // ROAD 1 GREEN
  // ==========================

  digitalWrite(LEDR2, HIGH);
  digitalWrite(LEDG1, HIGH);

  openServo1();

  delay(5000);

  digitalWrite(LEDG1, LOW);
  digitalWrite(LEDY1, HIGH);

  halfServo1();

  delay(2000);

  digitalWrite(LEDY1, LOW);

  closeServo1();

  digitalWrite(LEDR2, LOW);
}

// ==========================
// SERVO 1 FUNCTIONS
// ==========================

void openServo1() {

  for (int pos = 0; pos <= 90; pos++) {

    servo1.write(pos);
    delay(10);
  }
}

void halfServo1() {

  for (int pos = 90; pos >= 45; pos--) {

    servo1.write(pos);
    delay(10);
  }
}

void closeServo1() {

  for (int pos = 45; pos >= 0; pos--) {

    servo1.write(pos);
    delay(10);
  }
}

// ==========================
// SERVO 2 FUNCTIONS
// ==========================

void openServo2() {

  for (int pos = 0; pos <= 90; pos++) {

    servo2.write(pos);
    delay(10);
  }
}

void halfServo2() {

  for (int pos = 90; pos >= 45; pos--) {

    servo2.write(pos);
    delay(10);
  }
}

void closeServo2() {

  for (int pos = 45; pos >= 0; pos--) {

    servo2.write(pos);
    delay(10);
  }
}
