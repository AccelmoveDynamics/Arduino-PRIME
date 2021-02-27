int mL1= 13; 
int mL2= 11; 
int mR1= 10; 
int mR2= 2;
int enA= 5;
int enB= 6;
int Speed = 120;
int turnSpeed = 150;
void setup() {
pinMode(mL1, OUTPUT);
pinMode(mL2, OUTPUT); 
pinMode(mR1, OUTPUT);
pinMode(mR2, OUTPUT);
pinMode(enA, OUTPUT);
pinMode(enB, OUTPUT);
}
void loop()
{
 forward(); 
 delay(1000);  
 stop_now();
 delay(1000);
 backward(); 
 delay(1000);  
 stop_now(); 
 delay(1000); 
 right(); 
 delay(1000); 
 stop_now(); 
 delay(1000); 
 left(); 
 delay(1000);
 stop_now(); 
 delay(1000); 
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
analogWrite(enA, 0);
analogWrite(enB, 0);
}
