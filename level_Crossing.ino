#include <Servo.h>
int trigger = 13;
int echo= 12;
Servo servo1;
Servo servo2;
int power = 5;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(power, OUTPUT);
  digitalWrite(power,HIGH);
  pinMode(trigger, OUTPUT);
  digitalWrite(trigger, LOW);
  pinMode(echo, INPUT);
  servo1.attach(8);
  servo2.attach(10); 
    servo1.write(0);
  servo2.write(0);

}

void loop() {
  // put your main code here, to run repeatedly:
  long t, d;
 servo1.write(90);
 servo2.write(90);

   digitalWrite(trigger, HIGH);
  delayMicroseconds(10);          
  digitalWrite(trigger, LOW);
   t = pulseIn(echo, HIGH); 
  d = t/59;     
   Serial.print("Distancia: ");
  Serial.print(d);     
  Serial.print("cm");
  Serial.println();
  delay(100);      
if(d <= 5){
  servo1.write(0);
  servo2.write(0);
     delay(12000);

}
     
  
 
}
