#include <IRremote.h>
const int buzzer = 3;
int IR_RECEIVE_PIN = 12;

void setup() {

Serial.begin(115200);
IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); 
pinMode(buzzer,OUTPUT);
}

void loop() {

    if (IrReceiver.decode()) {
        IrReceiver.printIRResultShort(&Serial);
        Serial.println();
        IrReceiver.resume(); 
         if (IrReceiver.decodedIRData.command == 0x45) // button 1 in the remote
         { 
            digitalWrite(buzzer,HIGH);
         }
        if (IrReceiver.decodedIRData.command == 0x46)  // button 2 in the remote
          {
            digitalWrite(buzzer,LOW);
          }
        }
    }
