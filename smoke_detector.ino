#define MQ A0
#define LED 8
#define BUZZER 9

int threshold = 100;

void setup() {

  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  int gasValue = analogRead(MQ);

  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  if (gasValue > threshold) {

    digitalWrite(LED, HIGH);
    digitalWrite(BUZZER, HIGH);

    Serial.println("SMOKE DETECTED!");
  }
  else {

    digitalWrite(LED, LOW);
    digitalWrite(BUZZER, LOW);
  }

  delay(500);
}
