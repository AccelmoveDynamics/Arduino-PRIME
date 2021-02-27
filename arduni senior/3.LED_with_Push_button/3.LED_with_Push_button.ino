int buttonState;
int button = 4;
void setup() 
{
   pinMode(13, OUTPUT);                   
   pinMode(4, INPUT);                          
}
void loop() 
{
       buttonState=digitalRead(4);  
      if (buttonState == HIGH)          
         {
           digitalWrite(13, HIGH);             
         } 
      else
       {
         digitalWrite(13, LOW);  
           }         
       }
