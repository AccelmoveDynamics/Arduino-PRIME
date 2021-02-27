int ledpin =13;   
char c; 
int state_led=0;       
void setup() 
{
Serial.begin(9600);   
pinMode(ledpin, OUTPUT); }
void loop() {
if(Serial.available()>0) 
{
c = Serial.read();  Serial.println(c); 
delay(15);
}
if(c == 'a')     {
  state_led=1;
}
if(c=='b')
{
state_led=0;
}  
if(state_led==1)
{
  digitalWrite(ledpin,HIGH);  
  }
  else
  {
    digitalWrite(ledpin,LOW);  
 }
 }
