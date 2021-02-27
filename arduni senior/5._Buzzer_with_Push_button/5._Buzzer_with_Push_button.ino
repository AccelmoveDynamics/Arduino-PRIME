int button=4;
int buzzer = 3;
int buttonState;
void setup() 
{
   pinMode(3, OUTPUT);                   
   pinMode(4, INPUT);                          
}
void loop() 
{
       buttonState=digitalRead(4);  
      if (buttonState == HIGH)          
         {
           digitalWrite(3, HIGH);             
         } 
      else
       {
         digitalWrite(3, LOW);  
           }         
       }
