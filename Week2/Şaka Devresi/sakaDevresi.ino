#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>                            // ESP8266WiFi kütüphanesini import ettik.
#include <BlynkSimpleEsp8266.h>                     // BlynkSimpleEsp8266 kütüphanesini import ettik.

char auth[] = "u2NHIRUq85CZC";                      // Blynk'in gönderdiği token'in yarısını yazdım :)
char ssid[] = "circassian";                         // Wifi ağ adı yazdık.
char pass[] = "parola";                             // Wifi parolası yazdık.

#define yellowLed D6                                // Degişken tanımladık.
#define redLed D7
#define greenRed D8
int button;

void setup()
{
  Serial.begin(9600);                               // Seri haberleşmeyi başlattık.
  Blynk.begin(auth, ssid, pass);
  pinMode(yellowLed, OUTPUT);                       // Çıkış pinlerini belirttik.
  pinMode(redLed, OUTPUT);
  pinMode(greenRed, OUTPUT);
}

BLYNK_WRITE(V1)
{             
 button = param.asInt();
 if(button == 1)
    {
      digitalWrite(yellowLed , HIGH);               // Sarı ledi yaktık.
      delay(5000);                                  // 5 saniye beklettik.
      digitalWrite(yellowLed , LOW);                // Sarı ledi söndürdük.
      digitalWrite(redLed, HIGH);.
      delay(5000);
      digitalWrite(redLed, LOW);
      digitalWrite(greenRed , HIGH);
      delay(5000);
      digitalWrite(greenRed , LOW);
    } else
    {
     digitalWrite(yellowLed , LOW);
     digitalWrite(redLed, LOW);
     digitalWrite(greenRed , LOW);
    }
}

void loop()
{ 
  Blynk.run();                      
}
