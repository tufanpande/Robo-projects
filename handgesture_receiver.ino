#include <SoftwareSerial.h>

SoftwareSerial BT(10,11);

#define ENA 5
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 7
#define ENB 6

void forward()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);

  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);

  analogWrite(ENA,200);
  analogWrite(ENB,200);
}

void backward()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);

  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);

  analogWrite(ENA,200);
  analogWrite(ENB,200);
}

void left()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);

  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);

  analogWrite(ENA,180);
  analogWrite(ENB,180);
}

void right()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);

  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);

  analogWrite(ENA,180);
  analogWrite(ENB,180);
}

void stopRobot()
{
  analogWrite(ENA,0);
  analogWrite(ENB,0);

  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}

void setup()
{
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);

  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);

  BT.begin(9600);
  Serial.begin(9600);

  stopRobot();
}

void loop()
{
  if(BT.available())
  {
    char command = BT.read();

    Serial.println(command);

    switch(command)
    {
      case 'F':
        forward();
        break;

      case 'B':
        backward();
        break;

      case 'L':
        left();
        break;

      case 'R':
        right();
        break;

      default:
        stopRobot();
        break;
    }
  }
}
