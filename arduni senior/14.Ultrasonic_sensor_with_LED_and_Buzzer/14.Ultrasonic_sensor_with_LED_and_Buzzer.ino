int trigPin = 8; 
int echoPin =7; 
int ledpin =13;  
int buzzer = 3;
float duration, distance;
void setup() 
{
  Serial.begin(9600); 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);  
  pinMode(ledpin,OUTPUT); 
  pinMode(buzzer,OUTPUT); 

}
void loop() 
{
    sensor();
    if(distance>=10)                       
     {
       digitalWrite(ledpin,HIGH);  
       digitalWrite(buzzer,HIGH);  

     }
else
  {
     digitalWrite(ledpin,LOW); 
       digitalWrite(buzzer,LOW);  
  
  }
          }
void sensor()
{
  digitalWrite(trigPin, LOW);   
  delayMicroseconds(5);           
  digitalWrite(trigPin, HIGH);  
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);    
 duration = pulseIn(echoPin, HIGH); 
 distance = (duration*0.034)/2;  
Serial.print(distance);
 Serial.print("cm");
Serial.println();
delay(100);
}
