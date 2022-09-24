/*
Yang Xu 500890631
Ruoling Yu 500976267
Xinyu Ma 500943173
*/

// motor control and pwn pins
#define Left_Motor_Ctrl 4
#define Left_Motor_PWM 5
#define Right_Motor_Ctrl 2
#define Right_Motor_PWM 6

// fall & line tracking sensor
#define Front_Left_Sensor 11
#define Front_Middle_Sensor 7
#define Front_Right_Sensor 8

// ultrasonic sensor
#include "SR04.h" //ultrasonic sensor lib
#define Ultrasonic_Receive 12
#define Ultrasonic_Send 13

// servo
#define Servo_Pin 10
//SR04 sr04 = SR04(Ultrasonic_Send,Ultrasonic_Receive);

void setup() 
{
  Serial.begin(9600); // initialize serial communication at 9600 bits per second
  
  // motors
  pinMode(Left_Motor_Ctrl, OUTPUT);
  pinMode(Left_Motor_PWM, OUTPUT);
  pinMode(Right_Motor_Ctrl, OUTPUT);
  pinMode(Right_Motor_PWM, OUTPUT);

  // fall & line tracking sensor
  pinMode(Front_Left_Sensor, INPUT);
  pinMode(Front_Middle_Sensor, INPUT);
  pinMode(Front_Right_Sensor, INPUT);

  // ultrasonic sensor
  //pinMode(Ultrasonic_Send, INPUT);
  //pinMode(Ultrasonic_Receive, OUTPUT);
  
  // servo
  //servopulse(Servo_Pin, 90);// the angle of servo is 90 degree
}

void loop()
{
  move_front(80); // @params: speed; 80 < x < 255
  
  if (front_fall_detection())
  {
    move_back(80); // @params: speed; 80 < x < 255
    delay(500);
    left_turn(350);// @params: time; x ms
  }

  
  
  
 
}
