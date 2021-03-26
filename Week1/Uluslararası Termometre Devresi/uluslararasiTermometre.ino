void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.print("Nem: ");
  Serial.println(map(analogRead(A0), 20, 358, -40, 125));
  
  Serial.print("Kelvin: ");
  Serial.println(map(analogRead(A0), 20, 358, 233, 398));
  
  Serial.print("Fahrenheit: ");
  Serial.println(map(analogRead(A0), 20, 358, -40, 257));
  Serial.println();
  delay(1000);
}
