// Motor A
#define ENA 5
#define IN1 2
#define IN2 3

// Motor B
#define ENB 6
#define IN3 7
#define IN4 8

// LDR
#define LDR A0

int speedMotor = 150;

void setup() {

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  int lightValue = analogRead(LDR);

  Serial.print("Light Value: ");
  Serial.println(lightValue);

  // Change threshold if needed
  if(lightValue > 300) {
    forward();
  }
  else {
    stopRobot();
  }

  delay(100);
}

// Forward
void forward() {

  analogWrite(ENA, speedMotor);
  analogWrite(ENB, speedMotor);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// Stop
void stopRobot() {

  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
