/*
Yang Xu 500890631
Ruoling Yu 500976267
Xinyu Ma 500943173
*/

#define Safety_Distance 10

// 350 ms for ~90 degrees with speed 200, new batt
int Base_Speed = 70;
int Default_Turning_Speed = 200;
int Slow_Turning_Speed = 85;
long left_distance, right_distance;
int tries;

// motor control and pwn pins
#define Left_Motor_Ctrl 4
#define Left_Motor_PWM 5
#define Right_Motor_Ctrl 2
#define Right_Motor_PWM 6

// edge sensor
#define Front_Left_Edge_Sensor 10
#define Front_Right_Edge_Sensor 9
#define Back_Edge_Sensor 14  // A0

// line tracking
#define Left_Line_Sensor 11
#define Central_Line_Sensor 7
#define Right_Line_Sensor 8

// light sensor
#define Left_Light_Sensor 15  // A1
#define Right_Light_Sensor 16 // A2

// servo
#include <Servo.h>
#define Servo_Pin 17 // A3
Servo servo;

// ultrasonic sensor
#include "SR04.h"
#define Ultrasonic_Receive 12
#define Left_Ultrasonic_Receive 12
#define Left_Ultrasonic_Send 13
#define Right_Ultrasonic_Receive 18  // A4
#define Right_Ultrasonic_Send 19     // A5
SR04 left_sr04 = SR04(Left_Ultrasonic_Send, Left_Ultrasonic_Receive);
SR04 right_sr04 = SR04(Right_Ultrasonic_Send, Right_Ultrasonic_Receive);

void setup() 
{
  // initialize serial communication
  Serial.begin(1200); 
  
  // motors
  pinMode(Left_Motor_Ctrl, OUTPUT);
  pinMode(Left_Motor_PWM, OUTPUT);
  pinMode(Right_Motor_Ctrl, OUTPUT);
  pinMode(Right_Motor_PWM, OUTPUT);

  // edge sensor
  //pinMode(Front_Central_Edge_Sensor, INPUT);
  pinMode(Front_Left_Edge_Sensor, INPUT);
  pinMode(Front_Right_Edge_Sensor, INPUT);
  pinMode(Back_Edge_Sensor, INPUT);
  
  // line tracking sensor
  pinMode(Left_Line_Sensor, INPUT);
  pinMode(Central_Line_Sensor, INPUT);
  pinMode(Right_Line_Sensor, INPUT);
  
  // light sensor
  pinMode(Left_Light_Sensor, INPUT);
  pinMode(Right_Light_Sensor, INPUT);
  
  // servo
  //servo_init();

  // motor
  motor_speed_adjust();
}

void loop()
{
  //Serial.print("\n");

  //ultra_sonic_update_distance();  // debug
  fall_and_collision_detection();

  /*
  if (not following_line()) 
  { 
    if (not adjust_line_tracking()) { exit(0); };  // if failed to adjust: exit
  }
  */
  /*
  if (not following_light()) 
  { 
    if (not adjust_light_following()) { exit(0); }; 
  }
  */
}

void fall_and_collision_detection()
{
  if (front_fall_detected())      { avoid_fall(); }
  else if (collision_detected())  { avoid_object(); }
  else                            { move_front(Base_Speed); }
}
