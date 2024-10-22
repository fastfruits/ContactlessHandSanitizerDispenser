#include <Servo.h>
#include <SimpleUltrasonic.h>

Servo servo1;
SimpleUltrasonic sonicSensor(24,26);

void setup(){
  Serial.begin(9600);
  digitalWrite(22, HIGH);
  digitalWrite(24, HIGH);
  digitalWrite(26, HIGH);

  servo1.attach(22);
  servo1.write(90);
  sonicSensor.begin();
}

void loop(){
  float distance = sonicSensor.measureDistanceInCM();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm");
  Serial.println();
  delay(500);
  if(distance < 10.0 && distance != -1){
    delay(500);
    if(distance < 5.0){
      servo1.write(90);
      delay(1000);
      servo1.write(25);
      delay(1000);
      servo1.write(90);
      delay(1000);
      servo1.write(25);
    }
    else{
      servo1.write(90);
      delay(1000);
      servo1.write(25);
    }
    delay(2000);
  }
}