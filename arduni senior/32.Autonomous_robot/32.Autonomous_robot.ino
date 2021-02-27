#include <Servo.h>      // include library file of servo
#include<NewPing.h> // include library file of ultrasonic sensor
int mL1= 13; 
int mL2= 11; 
int mR1= 10; 
int mR2= 2;
int enA= 5;
int enB= 6;
int Speed = 120;
int turnSpeed = 150;
#define TRIGGER_PIN  8    // Assign the ultrasonic sensor  trigpin  
#define ECHO_PIN     7     // Assign the ultrasonic sensor echopin
#define MAX_DISTANCE 250 

Servo servo_motor;  
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

 
int distance = 100;
 
void setup()
{
  Serial.begin(9600);
pinMode(mL1, OUTPUT);
pinMode(mL2, OUTPUT); 
pinMode(mR1, OUTPUT);
pinMode(mR2, OUTPUT);
pinMode(enA, OUTPUT);
pinMode(enB, OUTPUT);
servo_motor.attach(9);   // attach the servo motor to digital pin 9
servo_motor.write(90);    // rotate servo in 90 degree
delay(2000);              
distance = readPing();    
delay(100);              
distance = readPing();
delay(100);
distance = readPing();
delay(100);
distance = readPing();
delay(100);
}
void loop()
{  
int distanceRight = 0;
int distanceLeft = 0;
delay(50);
Serial.println(distance);
if (distance <= 20)
{
stop_now();
delay(300);
backward();
delay(300);
stop_now();
delay(300);
distanceRight = lookRight();
delay(300);
distanceLeft = lookLeft();
delay(300);
if (distanceRight > distanceLeft) // if right distance is greater than left distance
{
right();   // calling right function
delay(300);
stop_now();  // calling stop function
}
else
{
left();   // calling left function
delay(300);
stop_now();  // calling stop function
}
}
else{
forward(); // calling forward function
}




distance = readPing(); 
}

int lookRight()   
{  
servo_motor.write(30);  // rotate the servo in 30 degree
delay(500);
int distance = readPing();
delay(100);
servo_motor.write(90);  // rotate the servo in 90 degree
return distance;
}
int lookLeft()    
{
servo_motor.write(150);
delay(500);
int distance = readPing();
delay(100);
servo_motor.write(90);
return distance;
}

int readPing()      
{
delay(100);            
int cm = sonar.ping_cm(); 
if (cm==0)
{
cm=250;
}
return cm;
}


void forward() 
{
digitalWrite(mL1,HIGH);
digitalWrite(mL2,LOW);
digitalWrite(mR1,HIGH);
digitalWrite(mR2,LOW);
analogWrite(enA, Speed);
analogWrite(enB, Speed);
}
void backward() 
{
digitalWrite(mL1,LOW);
digitalWrite(mL2,HIGH);
digitalWrite(mR1,LOW);
digitalWrite(mR2,HIGH);
analogWrite(enA, Speed);
analogWrite(enB, Speed);
}
void right() 
{
digitalWrite(mL1,LOW);
digitalWrite(mL2,HIGH);
digitalWrite(mR1,HIGH);
digitalWrite(mR2,LOW);
analogWrite(enA, turnSpeed);
analogWrite(enB, turnSpeed);
}

void left() { 
digitalWrite(mL1,HIGH);
digitalWrite(mL2,LOW);
digitalWrite(mR1,LOW);
digitalWrite(mR2,HIGH);
analogWrite(enA, turnSpeed);
analogWrite(enB, turnSpeed);
}
void stop_now() 
{
digitalWrite(mL1,LOW);
digitalWrite(mL2,LOW);
digitalWrite(mR1,LOW);
digitalWrite(mR2,LOW);
analogWrite(enA,0);
analogWrite(enB,0);
}
