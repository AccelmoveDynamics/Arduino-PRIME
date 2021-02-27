#include <IRremote.h>
int IR_RECEIVE_PIN = 12;

int mL1= 13; 
int mL2= 11; 
int mR1= 10; 
int mR2= 2;
int enA= 5;
int enB= 6;
int Speed = 150;
int turnSpeed = 150;

void setup() {
pinMode(mL1, OUTPUT);
pinMode(mL2, OUTPUT); 
pinMode(mR1, OUTPUT);
pinMode(mR2, OUTPUT);
pinMode(enA, OUTPUT);
pinMode(enB, OUTPUT);


Serial.begin(115200);
IrReceiver.begin(IR_RECEIVE_PIN, DISABLE_LED_FEEDBACK); //have to disable feedback because motor is connected in pin 13
//pinMode(led,OUTPUT);
}
// 0x18 forward, 0x52 back, 0x8 left, 0x5A right, 0x1C stop
void loop() {


    if (IrReceiver.decode()) {
        IrReceiver.printIRResultShort(&Serial);
        Serial.println();
        IrReceiver.resume(); 
         if (IrReceiver.decodedIRData.command == 0x18) // button up in the remote
         { 
            forward();
         }
        if (IrReceiver.decodedIRData.command == 0x52)  // button down in the remote
          {
            backward();
          }
         if (IrReceiver.decodedIRData.command == 0x8)  // button left in the remote 
         {
          left();
         }
         if (IrReceiver.decodedIRData.command == 0x5A)  // button right in the remote 
         {
          right();
         }
         if (IrReceiver.decodedIRData.command == 0x1C)  // button ok in the remote 
         {
          stop_now();
         }
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
 
