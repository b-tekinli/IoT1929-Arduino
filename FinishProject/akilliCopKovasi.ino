#include <Servo.h>                        // Servo kütüphanesini import ettik.

Servo motor;                              // Servo'yu motor olarak tanımladık.

#define echo 6                            // Değişkenlerimizi ve pinlerimizi tanımladık.
#define trig 7

void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  motor.attach(9);                        // 9 numaralı pine bağlı olup olmadığını kontrol ettik.
  Serial.begin(9600);                     // Seri haberleşmeyi başlattık.
}

void loop()
{
  digitalWrite(trig, LOW);
  delayMicroSeconds(2);
  digitalWrite(trig, HIGH);
  delayMicroSeconds(2);
  digitalWrite(trig, LOW);
  
  float time = pulseIn(echo, HIGH);
  float cm = time/58.2;                  // Meesafeyi zamana göre hesaplattık.
  delay(200);
  
  if(cm < 10){                           // Mesafe 10'un altına düşünce çalışmaya başlıyor.
    motor.write(90);                     // 90 derece açılıyor.
    delay(5000);                         // 5 saniye bekliyor o sırada çöpü atıyoruz.
    motor.write(0);                      // 5 saniye bekledikten sonra tekrar 0 dereceye düşüyor.
  }
}
