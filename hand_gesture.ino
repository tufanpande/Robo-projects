#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;
WiFiUDP udp;

const char* ssid = "GestureRobot";
const char* password = "12345678";

IPAddress receiverIP(192,168,4,2);

const int receiverPort = 4210;

int16_t ax, ay, az;
int16_t gx, gy, gz;

char command='S';

void setup()
{
  Serial.begin(115200);

  Wire.begin(D2,D1);

  mpu.initialize();

  if(!mpu.testConnection())
  {
    Serial.println("MPU6050 Failed");
    while(1);
  }

  Serial.println("MPU6050 Connected");

  WiFi.mode(WIFI_AP);

  WiFi.softAP(ssid,password);

  Serial.println(WiFi.softAPIP());

  udp.begin(receiverPort);
}

void loop()
{
  mpu.getMotion6(&ax,&ay,&az,&gx,&gy,&gz);

  if(ay<-8000)
    command='F';

  else if(ay>8000)
    command='B';

  else if(ax<-8000)
    command='L';

  else if(ax>8000)
    command='R';

  else
    command='S';

  udp.beginPacket(receiverIP,receiverPort);
  udp.write(command);
  udp.endPacket();

  Serial.println(command);

  delay(100);
}
