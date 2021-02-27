int trigPin = 8;    
int echoPin = 7;  
float duration, distance;   
void setup()
{
Serial.begin (9600);
pinMode(trigPin, OUTPUT);  
pinMode(echoPin, INPUT);  }
void loop() {
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
delay(400);
}     
