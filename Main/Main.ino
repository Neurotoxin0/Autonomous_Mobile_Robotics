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
#define Front_Central_Left_Sensor 11
#define Front_Central_Middle_Sensor 7
#define Front_Central_Right_Sensor 8
//#define Front_Left_Sensor 0
//#define Front_Right_Sensor 0
//#define Back_Left__Sensor 0
//#define Back_Right_Sensor 0

// ultrasonic sensor
#include "SR04.h" //ultrasonic sensor lib
#define Ultrasonic_Receive 12
#define Ultrasonic_Send 13

// servo
#include <Servo.h>
#define Servo_Pin 10
Servo servo;
int Servo_Position, Servo_Angle;

//SR04 sr04 = SR04(Ultrasonic_Send,Ultrasonic_Receive);

void setup() 
{
  // initialize serial communication
  Serial.begin(9600); 
  
  // motors
  pinMode(Left_Motor_Ctrl, OUTPUT);
  pinMode(Left_Motor_PWM, OUTPUT);
  pinMode(Right_Motor_Ctrl, OUTPUT);
  pinMode(Right_Motor_PWM, OUTPUT);

  // fall & line tracking sensor
  pinMode(Front_Central_Left_Sensor, INPUT);
  pinMode(Front_Central_Middle_Sensor, INPUT);
  pinMode(Front_Central_Right_Sensor, INPUT);
  //pinMode(Front_Left_Sensor, INPUT);
  //pinMode(Front_Right_Sensor, INPUT);
  //pinMode(Back_Left__Sensor, INPUT);
  //pinMode(Back_Right_Sensor, INPUT);
  
  // ultrasonic sensor
  //pinMode(Ultrasonic_Send, INPUT);
  //pinMode(Ultrasonic_Receive, OUTPUT);
  
  // servo
  servo.attach(Servo_Pin);
}

void loop()
{
  move_front(80); // @params: speed; 80 < x < 255
  
  int fall_direction = fall_detection();
  if (fall_direction)
  {
    if (fall_direction == 2)  // front central
    {
      move_back(80); // @params: speed; 80 < x < 255
      delay(500);
      right_turn(350);// @params: time; x ms
    }
    else if (fall_direction == 1) // front left
    {
      move_back(80);
      delay(500);
      left_turn(350);
    }
    else if (fall_direction == 3) // front right
    {
      move_back(80);
      delay(500);
      right_turn(350);
    }
    else if (fall_direction == 4) // back left
    {
      move_front(80);
      delay(500);
      right_turn(350);
    }
    else if (fall_direction == 5) // back right
    {
      move_front(80);
      delay(500);
      left_turn(350);
    }
  }
 
}
