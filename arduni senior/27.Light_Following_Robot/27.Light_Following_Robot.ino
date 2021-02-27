int leftSensor;
int rightSensor;
int ldr_1 = A0;
int ldr_2 = A1;
int mL1= 13; 
int mL2= 11; 
int mR1= 10; 
int mR2= 2;
int enA= 5;
int enB= 6;
int Speed = 130;
int turnSpeed = 150;
void setup() {
Serial.begin(9600);
pinMode(ldr_1, INPUT);
pinMode(ldr_2, INPUT);
pinMode(mL1, OUTPUT);
pinMode(mL2, OUTPUT); 
pinMode(mR1, OUTPUT);
pinMode(mR2, OUTPUT);
pinMode(enA, OUTPUT);
pinMode(enB, OUTPUT);
}
void loop() {
    leftSensor= analogRead(ldr_1);
    rightSensor= analogRead(ldr_2);
    Serial.print("Left");
    Serial.print(leftSensor);
    Serial.print("        ");
    Serial.print("Right");
    Serial.print(rightSensor);
    Serial.print("        ");
    Serial.print("\n");
    if (rightSensor >= 400 & leftSensor >= 400) {
      forward();
    } else if (rightSensor <= 400 & leftSensor >= 400) {
      left();
    } else if (rightSensor >= 400 & leftSensor <= 400) {
      right();
    } else {
      stop_now();
    }

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
void right() 
{
digitalWrite(mL1,HIGH);
digitalWrite(mL2,LOW);
digitalWrite(mR1,LOW);
digitalWrite(mR2,HIGH);
analogWrite(enA, turnSpeed);
analogWrite(enB, turnSpeed);
Serial.println("right");
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
void stop_now() 
{
digitalWrite(mL1,LOW);
digitalWrite(mL2,LOW);
digitalWrite(mR1,LOW);
digitalWrite(mR2,LOW);
Serial.println("stop");
}
