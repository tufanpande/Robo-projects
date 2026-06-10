#define RAIN_SENSOR 2
#define BUZZER 8

void setup() {

  pinMode(RAIN_SENSOR, INPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(BUZZER, LOW);

  Serial.begin(9600);
}

void loop() {

  int rain = digitalRead(RAIN_SENSOR);

  Serial.print("Rain Status: ");
  Serial.println(rain);

  if (rain == LOW) {   // Rain detected

    digitalWrite(BUZZER, LOW);

    Serial.println("RAIN DETECTED!");
  }
  else {

    digitalWrite(BUZZER, HIGH);
  }

  delay(100);
}
