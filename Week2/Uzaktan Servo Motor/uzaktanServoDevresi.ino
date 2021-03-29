#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>                              // Servo kütüphanesini import ettik.

char auth[] = "TdDxm2qioRk19h";                 // Blynk'in gönderdiği token'ın yarısını yazdım :)
char ssid[] = "circassian";
char pass[] = "sifre";

Servo servoMotor;

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  servoMotor.attach(D8);
}

BLYNK_WRITE(V0)
{
   servoMotor.write(param.asInt());            // Servo motorun 0 ile 180 derece arasında hareket etmesini sağladık.
}
BLYNK_WRITE(V1)
{
  servoMotor.write(0);
}
BLYNK_WRITE(V2)
{
  servoMotor.write(45);                       // 45 derecelik açıya hareket ettirdik.
}
BLYNK_WRITE(V3)
{
  servoMotor.write(90);
}
BLYNK_WRITE(V4)
{ 
  servoMotor.write(180);
}

void loop()
{
  Blynk.run();
}
