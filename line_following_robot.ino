// Line Following Robot - Fixed Code

// Motor one
#define ENA 5
#define IN1 2
#define IN2 3

// Motor two
#define ENB 6
#define IN3 7
#define IN4 8

// Sensor pins
#define SL 9
#define SR 10

int mSpeed = 120; // adjust speed (0–255)

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(SL, INPUT);
  pinMode(SR, INPUT);

  Serial.begin(9600);
}

void loop() {
  bool LValue = digitalRead(SL); // left sensor
  bool RValue = digitalRead(SR); // right sensor

  // Debug output
  Serial.print("Left: ");
  Serial.print(LValue);
  Serial.print("  Right: ");
  Serial.println(RValue);

  // LINE FOLLOWING LOGIC
  if (LValue == 0 && RValue == 0) {
    forward();     // both on black line
  } 
  else if (LValue == 0 && RValue == 1) {
    turnLeft();    // left sees line
  } 
  else if (LValue == 1 && RValue == 0) {
    turnRight();   // right sees line
  } 
  else {
    Stop();        // both on white (line lost)
  }

  delay(10); // small delay for stability
}

// Move Forward
void forward() {
  analogWrite(ENA, mSpeed);
  analogWrite(ENB, mSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// Turn Right
void turnRight() {
  analogWrite(ENA, mSpeed);
  analogWrite(ENB, 0);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// Turn Left
void turnLeft() {
  analogWrite(ENA, 0);
  analogWrite(ENB, mSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// Stop Robot
void Stop() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
