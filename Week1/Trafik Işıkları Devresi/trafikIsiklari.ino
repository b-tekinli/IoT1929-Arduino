void setup()
{
  pinMode(7, OUTPUT);       // pinlerin modunu belirledik.
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  digitalWrite(7, HIGH);     // kırmızı ışığı yakıyoruz.
  delay(10000);              // 10 saniye bekletiyoruz.
  digitalWrite(6, HIGH);     // sarı ışığı yakıyoruz.
  delay(2000);               // 2 saniye bekletiyoruz.
  digitalWrite(7, LOW);      // kırmızı ışığı söndürüyoruz.
  digitalWrite(6, LOW);      // sarı ışığı söndürüyoruz.
  digitalWrite(5, HIGH);     // yeşil ışığı yakıyoruz.
  delay(5000);               // 5 saniye bekletiyoruz.
  digitalWrite(5, LOW);      // yeşil ışığı söndürüyoruz.
}
