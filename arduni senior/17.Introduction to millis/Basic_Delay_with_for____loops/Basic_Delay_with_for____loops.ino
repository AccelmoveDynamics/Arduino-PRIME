void setup() { 
pinMode(3,OUTPUT);
pinMode(4,INPUT);

}

void loop() {
 
if(digitalRead(4)==HIGH)
{ digitalWrite(3,HIGH);
  for (int x=0; x < 1000; x++)
      delay(1);}
else{  
  digitalWrite(3,LOW);
  for (int x=0; x < 1000; x++)
    delay(1);}
}
