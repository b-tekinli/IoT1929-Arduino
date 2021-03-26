void setup()
{
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop()
{
  for(int a=3; a<=7; a++)   // ledleri sırayla yakmak için for döngüsü kullanıyoruz.
  {
    digitalWrite(a, HIGH);
    delay(500);          // 0,5 saniye bekletiyoruz.
    digitalWrite(a, LOW);
  }
  
  for(int a=7; a>=3; a--)
  {
    digitalWrite(a, HIGH);
    delay(500);
    digitalWrite(a, LOW);
  }
}
