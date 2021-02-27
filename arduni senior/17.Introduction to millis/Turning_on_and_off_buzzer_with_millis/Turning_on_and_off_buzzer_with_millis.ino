unsigned long previousTime = 0;
void setup() {
  // put your setup code here, to run once:
pinMode(3,OUTPUT);
pinMode(4,INPUT);
}
void loop() {
if(digitalRead(4)==HIGH)
{
  unsigned long current_time = millis();
  if(current_time >= previousTime + 1000)
  {
    previousTime += 1000;
    digitalWrite(3,!digitalRead(3));
  }
}
else
{
  digitalWrite(3,LOW);
}
}
