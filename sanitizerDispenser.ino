#include <Servo.h>
#include <SimpleUltraSonic.h>

Servo servo1;
SimpleUltrasonic sonicSensor(9,10);

void setup(){
  Serial.begin(9600)
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);

  servo1.attach(11);
  servo1.write(180);
  sonicSensor.begin();
}

void loop(){
  float distance = sonicSensor.measureDistanceInCM()
  Serial.print("Distance: " + distance + " cm");
  delay(500);
  if(distance < 20.0){
    delay(500)
    if(distance < 5.0){
      servo1.write(0);
      delay(250);
      servo1.write(180);
      delay(250);
      servo1.write(0);
      delay(250);
      servo1.write(180);
    }
    else if(distance < 10.0){
      servo1.write(0);
      delay(250);
      servo1.write(180);
    }
  }
}