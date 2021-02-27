void setup() { 
pinMode(3,OUTPUT);
pinMode(4,INPUT);

}

void loop() {
 
if(digitalRead(4)==HIGH)
{
  digitalWrite(3,HIGH);
  delay(3000);
  digitalWrite(3,LOW);
  delay(3000);
}
else
{
  digitalWrite(3,LOW);
}
}
