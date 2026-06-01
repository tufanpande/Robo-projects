// ===============================
// SMART Obstacle Avoiding Robot
// FIXED FOR REVERSED MOTOR B
// NO HARDWARE CHANGE REQUIRED
// ===============================

#include <Servo.h>

// ---------- Motor A ----------
#define ENA 5
#define IN1 2
#define IN2 3

// ---------- Motor B ----------
#define ENB 6
#define IN3 7
#define IN4 8

// ---------- Ultrasonic ----------
#define TRIG 11
#define ECHO 12

// ---------- Servo ----------
Servo myServo;
#define SERVO_PIN 10

int mSpeed = 220;
String action = "STOP";

// ===============================
// SETUP
// ===============================
void setup() {

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  myServo.attach(SERVO_PIN);
  myServo.write(90);

  Serial.begin(9600);
}

// ===============================
// LOOP
// ===============================
void loop() {

  int front = getDistance(90);

  Serial.print("Front: ");
  Serial.print(front);

  action = "FORWARD";

  // ---------- CLEAR PATH ----------
  if (front > 25) {

    forward();
    action = "FORWARD";
  }

  // ---------- OBSTACLE ----------
  else {

    Stop();
    delay(150);

    backward();
    action = "BACKWARD";
    delay(300);

    Stop();
    delay(100);

    int left = getDistance(150);
    delay(100);

    int right = getDistance(30);
    delay(100);

    Serial.print(" | Left: ");
    Serial.print(left);
    Serial.print(" Right: ");
    Serial.print(right);

    if (left > right) {

      turnLeft();
      action = "LEFT";
      delay(500);
    }
    else {

      turnRight();
      action = "RIGHT";
      delay(500);
    }

    Stop();
    delay(100);
  }

  Serial.print(" | Action: ");
  Serial.println(action);

  delay(60);
}

// ===============================
// ULTRASONIC FUNCTION
// ===============================
int getDistance(int angle) {

  myServo.write(angle);
  delay(120);

  long duration;
  int distance;
  int sum = 0;

  for (int i = 0; i < 3; i++) {

    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);

    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);

    duration = pulseIn(ECHO, HIGH, 30000);

    distance = duration * 0.034 / 2;

    if (distance <= 0 || distance > 400) {
      distance = 200;
    }

    sum += distance;
    delay(10);
  }

  return sum / 3;
}

// ===============================
// MOVEMENT FUNCTIONS (FIXED)
// MOTOR B IS INVERTED IN SOFTWARE
// ===============================

void forward() {

  analogWrite(ENA, mSpeed);
  analogWrite(ENB, mSpeed);

  // Motor A normal
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Motor B REVERSED (FIX)
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void backward() {

  analogWrite(ENA, mSpeed);
  analogWrite(ENB, mSpeed);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  // Motor B REVERSED (FIX)
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnLeft() {

  analogWrite(ENA, 0);
  analogWrite(ENB, mSpeed);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  // Motor B reversed
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnRight() {

  analogWrite(ENA, mSpeed);
  analogWrite(ENB, 0);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Motor B OFF
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void Stop() {

  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
