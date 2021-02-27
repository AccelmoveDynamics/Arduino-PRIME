int trigPin = 8;          
int echoPin = 7;     
float duration, distance;
#include<Servo.h> 
 Servo myservo;       
void setup() 
{
 Serial.begin (9600);  
 pinMode(trigPin, OUTPUT); 
 pinMode(echoPin, INPUT);
myservo.attach(9);
 myservo.write(0);
 }
void loop() 
{
sensor();
myservo.write(0);  
if(distance>= 10)    
 

{
myservo.write(90); 
 }

else
{
myservo.write(0);  
 }
}
void sensor()
{
digitalWrite(trigPin, LOW);
 delayMicroseconds(5); 
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW); 
 duration = pulseIn(echoPin, HIGH); 
 distance = (duration*0.034)/2;  
Serial.print(distance);
Serial.print("cm");
Serial.println();
delay(400);
}
