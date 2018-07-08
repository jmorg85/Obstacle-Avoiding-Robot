#include <AFMotor.h>

int trig_pin = 9;
int echo_pin = 10;
AF_DCMotor motor1(3);
AF_DCMotor motor2(4);

void setup() {
  Serial.begin(9600);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);

}

void loop() {
 motor1.setSpeed(200);
 motor2.setSpeed(200);
 motor1.run(FORWARD);
 motor2.run(FORWARD);
 long distance, duration, left_distance, right_distance;
 digitalWrite(trig_pin, HIGH);
 delayMicroseconds(1000);
 digitalWrite(trig_pin, LOW);
 duration = pulseIn(echo_pin, HIGH);
 distance = (duration/2)/29.1;
 Serial.print(distance);
 Serial.println("cm");

 if (distance <=15)
 {
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  delay(1000);
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  delay(500);
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  delay(500);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig_pin, LOW);
  duration = pulseIn(echo_pin, HIGH);
  left_distance = (duration/2)/29.1;
  Serial.print("The left distance is ");
  Serial.print(left_distance);
  Serial.println("cm");
  delay(1000);
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  delay(1000);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig_pin, LOW);
  duration = pulseIn(echo_pin, HIGH);
  right_distance = (duration/2)/29.1;
  Serial.print("The right distance is ");
  Serial.print(right_distance);
  Serial.println("cm");
  delay(1000);
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  delay(500);

  if (right_distance >= left_distance)
  {
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
    delay(500);
  }

  else if(left_distance > right_distance)
  {
    motor1.run(BACKWARD);
    motor2.run(FORWARD);
    delay(500);
  }
  
 }

}
