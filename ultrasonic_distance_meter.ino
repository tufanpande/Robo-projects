#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define TRIG_PIN 9
#define ECHO_PIN 10

LiquidCrystal_I2C lcd(0x27, 16, 2);

long duration;
float distance;

void setup() {

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Distance Meter");

  delay(2000);
  lcd.clear();
}

void loop() {

  // Send ultrasonic pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  // Read echo pulse
  duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate distance
  distance = duration * 0.0343 / 2;

  // LCD Display
  lcd.setCursor(0, 0);
  lcd.print("Distance:");

  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm   ");

  // Serial Monitor Display
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);
}
