#include <SPI.h>                                             // Gerekli kütüphaneleri import ettik.
#include <RFID.h>

#define redLed 5                                            // Değişkenleri tanımladık, pinleri belirledik.
#define greenLed 6

RFID rfid(7, 8);

char card[3] = {98, 567, 120};

bool pass = true;

void setup() {
  
  Serial.begin(9600);                                        // Seri haberleşme başlattık.

  
  SPI.begin();
  rfid.init();
  
  
  pinMode(redLed, OUTPUT);                                  // Çıkış pinlerimizi belirttik.
  pinMode(greenLed, OUTPUT);
  
}

void loop() {
  
  pass = 1;
  
  if(rfid.isCard()){
    if(rfid.readCardSerial()){                             // Kart okuma.
      Serial.println("Card ID: ");
      Serial.println(rfid.num[0], ", ");
      Serial.println(rfid.num[1], ", ");
      Serial.println(rfid.num[2], ", ");
      
    }

    for(int a=0; a<3; a++){
      if(rfid.num[i] != card[i]){
        
        pass = 0;
        
      }
    }
    if(pass == 1){
      
      digitalWrite(greenLed, HIGH);                         // Kart geçerli olduğunda yeşil ledi yaktık.
      delay(3000);                                          // Yeşil ledi 3 saniye yaktık. 
      Serial.println("Approved ✓ Have a nice day :)")      // Kartın geçerli olması durumunda ekranda belirecek yazı.
      digitalWrite(greenLed, LOW);                         // Yeşil ledi söndürdük.
      
    }else{

      digitalWrite(redLed, HIGH);                        // Kart geçersiz olduğunda kırmızı ledi yaktık.
      delay(3000);                                       // Kırmızı ledi 3 saniye yaktık.
      Serial.println("Denied X  The card is not defined in the system!")    // Kartın geçersiz olması durumunda ekranda belirecek yazı.
      digitalWrite(redLed, LOW);                         // Kırmızı ledi söndürdük.
      
    }

    rfid.halt();                                        // Kart yeniden okunmaya hazır.
  }
}
