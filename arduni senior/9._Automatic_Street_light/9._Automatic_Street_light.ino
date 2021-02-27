 int ledPin = 13;            
int ldrPin = A0;
int ldrStatus;
void setup ()
 { Serial.begin(9600);    
    pinMode(ledPin, OUTPUT);   
    pinMode(ldrPin, INPUT);      
   }
void loop() 
{ldrStatus = analogRead(ldrPin);  
    if (ldrStatus <= 100)  
    { digitalWrite(ledPin, HIGH);
        Serial.print("Turn on the LED : ");
        Serial.println(ldrStatus); }
 else 
   {
         digitalWrite(ledPin, LOW); 
         Serial.print("Turn off the LED : ");
         Serial.println(ldrStatus);
  }
  }
