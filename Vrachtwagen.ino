#include <Servo.h>

Servo servo;

int motor_pin1 = 4;
int motor_pin2 = 5;
int motor_pin3 = 6;
int motor_pin4 = 11;
int motor_pin5 = 9;
int servoPin = 8;
int joyX = A0;
int joyY = A1;

int xValue = 0;
int yValue = 0;
int motorValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(motor_pin1,OUTPUT);
  pinMode(motor_pin2,OUTPUT);
  pinMode(motor_pin3,OUTPUT);
  pinMode(motor_pin4,OUTPUT);
  pinMode(motor_pin5,OUTPUT);
  pinMode(servoPin,OUTPUT);
  pinMode(joyX,INPUT);
  pinMode(joyY,INPUT);

  servo.attach(servoPin);
  digitalWrite(motor_pin1,HIGH);
}

void loop() {
  xValue = analogRead(joyX);
  yValue = analogRead(joyY);

  int Pain = map(xValue,0,1023,0,180);

  servo.write(Pain);
  
  yValue >>= 1;
  if(yValue > 255){
    digitalWrite(motor_pin3, LOW);
    digitalWrite(motor_pin5, LOW);
    analogWrite(motor_pin2, (yValue - 256));
    analogWrite(motor_pin4, (yValue - 256));
  }
  else
    if(yValue < 255){
      digitalWrite(motor_pin2, LOW);
      digitalWrite(motor_pin4, LOW);
      analogWrite(motor_pin3, (255 - yValue));
      analogWrite(motor_pin5, (255 - yValue));
    }
    else{
      digitalWrite(motor_pin2, LOW);
      digitalWrite(motor_pin3, LOW);
      digitalWrite(motor_pin4, LOW);
      digitalWrite(motor_pin5, LOW);
    }
  
  Serial.print(xValue);
  Serial.print("\t");
  Serial.println(Pain);
  
}
