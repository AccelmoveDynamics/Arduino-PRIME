int potPin =A2;         
int inputValue = 0;                
int outputValue = 0;             
int buzzer = 3; 
void setup()
{
 Serial.begin(9600);          
  } 
void loop()
{
inputValue = analogRead(potPin);                       
outputValue = map(inputValue, 0, 1023, 0, 255);            
analogWrite(buzzer, outputValue);  
delay(1000);
 } 
