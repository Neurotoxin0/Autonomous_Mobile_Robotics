/*
Yang Xu 500890631
Ruoling Yu 500976267
Xinyu Ma 500943173
*/

#include "SR04.h" //ultrasonic sensor lib

// motor control and pwn pins
#define Left_Motor_Ctrl 4
#define Left_Motor_PWM 5
#define Right_Motor_Ctrl 2
#define Right_Motor_PWM 6

// fall & line tracking sensor
#define Front_left_sensor 11
#define Front_middle_snsor 7
#define Front_right_snsor 8

// ultrasonic sensor
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
  pinMode(Front_left_sensor,INPUT);
  pinMode(Front_middle_snsor,INPUT);
  pinMode(Front_right_snsor,INPUT);

  // ultrasonic sensor
  //pinMode(Ultrasonic_Send, INPUT);
  //pinMode(Ultrasonic_Receive, OUTPUT);
  

  // servo
  //servopulse(Servo_Pin,90);// the angle of servo is 90 degree
}

void loop()
{
  move_front(80);
  
  if (front_fall_detection())
  {
    move_back(80); delay(500);
    left_turn(350);
    //stop_movement();
  }

  
  
  
 
}
