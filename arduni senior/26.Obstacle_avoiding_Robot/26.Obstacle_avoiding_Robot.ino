int trigPin = 8; 
int echoPin =7; 
int mL1= 13; 
int mL2= 11; 
int mR1= 10; 
int mR2= 2;
int enA= 5;
int enB= 6;
int Speed = 130;
int turnSpeed = 150;
 
float duration, distance;
void setup() 
{
  Serial.begin(9600); 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);  
  pinMode(mL1, OUTPUT);
  pinMode(mL2, OUTPUT); 
  pinMode(mR1, OUTPUT);
  pinMode(mR2, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT); 
}
void loop() 
{
    sensor();
    if(distance<20)                       
     {
       stop_now();
       delay(1000);
       backward();
       delay(1000); 
       stop_now();
       delay(1000); 
       left();
       delay(1000); 
     }
else
  {
     forward();    
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
  void forward() 
{
digitalWrite(mL1,HIGH);
digitalWrite(mL2,LOW);
digitalWrite(mR1,HIGH);
digitalWrite(mR2,LOW);
analogWrite(enA, Speed);
analogWrite(enB, Speed);
Serial.println("forward");
}
void backward() 
{
digitalWrite(mL1,LOW);
digitalWrite(mL2,HIGH);
digitalWrite(mR1,LOW);
digitalWrite(mR2,HIGH);
analogWrite(enA, Speed);
analogWrite(enB, Speed);
Serial.println("backward");
}
void left() { 
digitalWrite(mL1,LOW);
digitalWrite(mL2,HIGH);
digitalWrite(mR1,HIGH);
digitalWrite(mR2,LOW); 
analogWrite(enA, turnSpeed);
analogWrite(enB, turnSpeed);
Serial.println("left");
}
void stop_now() {
digitalWrite(mL1,LOW);
digitalWrite(mL2,LOW);
digitalWrite(mR1,LOW);
digitalWrite(mR2,LOW);
Serial.println("stop");}
