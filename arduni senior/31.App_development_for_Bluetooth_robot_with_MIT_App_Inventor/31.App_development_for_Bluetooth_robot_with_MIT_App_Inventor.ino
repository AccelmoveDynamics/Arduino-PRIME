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
  // put your main code here, to run repeatedly:
if(Serial.available()>0) // data available in serial monitor is greater than 0
var= Serial.read(); // read the data in the serial monitor and store in var
Serial.println(var); // print the value in var
if(var=='F') // if the val is F
{
 forward(); // calling forward function
 }
 else if(var=='B') // if it is B


 {
 backward(); // calling backward function
 }
 else if(var=='L') // if it is L
 {
 left(); // calling left function
 }
 else if(var=='R') // if it is R
 {
 right(); // calling Right function
 }
 else{
 stop_now(); // calling stop function
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
