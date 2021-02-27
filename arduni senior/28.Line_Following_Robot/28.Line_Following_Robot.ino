int right_sensor = 0;
int left_sensor = 0;
int middle_sensor = 0;
int turnSpeed = 150;
int Speed = 100;
const int mL1 = 13;
const int mL2 = 11;
const int mR1 = 10;
const int mR2 = 2;
const int enA = 5;
const int enB = 6;

int sense_value = 300;

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
    left_sensor = analogRead(A1);
    right_sensor = analogRead(A0);
    middle_sensor = analogRead(A3);
    Serial.print("right sensor = ");
    Serial.print(right_sensor);
    Serial.print(" ; ");
    Serial.print("left sensor = ");
    Serial.print(left_sensor);
    Serial.print(" ; ");
    Serial.print("middle sensor = ");
    Serial.print(middle_sensor);
    Serial.print(" ; ");
    Serial.print("\n");
    if ((middle_sensor <= sense_value) && (left_sensor >= sense_value) &&  (right_sensor >= sense_value)){
      forward();
    } else if ((middle_sensor >= sense_value) && (left_sensor <= sense_value) &&  (right_sensor >= sense_value)) {
      left();
    } else if ((middle_sensor >= sense_value) && (left_sensor >= sense_value) &&  (right_sensor <= sense_value)){
      right();
    } else if ((left_sensor <= sense_value) && (right_sensor <= sense_value) && (middle_sensor <=sense_value)) {
      stop_now();
    }else if ((middle_sensor <= sense_value) && (left_sensor <= sense_value) && (right_sensor >= sense_value)){
      left();
    }else if ((middle_sensor <= sense_value) && (right_sensor <= sense_value) && (left_sensor >= sense_value)){
      right();
    }else {
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
}

void left() {
  digitalWrite(mL1,HIGH);
digitalWrite(mL2,LOW);
digitalWrite(mR1,LOW);
digitalWrite(mR2,HIGH);
analogWrite(enA, turnSpeed);
analogWrite(enB, turnSpeed);
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
analogWrite(enB, Speed);}
