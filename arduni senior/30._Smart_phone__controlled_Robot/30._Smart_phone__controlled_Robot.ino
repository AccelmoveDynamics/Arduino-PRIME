int turnSpeed = 150;
int Speed = 100;
const int mL1 = 13;
const int mL2 = 11;
const int mR1 = 10;
const int mR2 = 2;
const int enA = 5;
const int enB = 6;
char var;
void setup() {
  pinMode(mL1, OUTPUT);
  pinMode(mL2, OUTPUT);
  pinMode(mR1, OUTPUT);
  pinMode(mR2, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  
if(Serial.available()>0) 
var= Serial.read(); 
Serial.println(var); 
if(var=='F') 
{
 forward(); 
 }
 else if(var=='B') 


 {
 backward(); 
 }
 else if(var=='L') 
 {
 left(); 
 }
 else if(var=='R') 
 {
 right(); 
 }
 else{
 stop_now(); 
}
}
void right() {
  digitalWrite(mL1,LOW);
digitalWrite(mL2,HIGH);
digitalWrite(mR1,HIGH);
digitalWrite(mR2,LOW);
analogWrite(enA, turnSpeed);
analogWrite(enB, turnSpeed);
Serial.println("right");
}

void left() {
  digitalWrite(mL1,HIGH);
digitalWrite(mL2,LOW);
digitalWrite(mR1,LOW);
digitalWrite(mR2,HIGH);
analogWrite(enA, turnSpeed);
analogWrite(enB, turnSpeed);
Serial.println("left");
}

void stop_now() {
  digitalWrite(mL1, LOW);
  digitalWrite(mL2, LOW);
  digitalWrite(mR1, LOW);
  digitalWrite(mR2, LOW);
  analogWrite(enA, 0);
  analogWrite(enB, 0);
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
