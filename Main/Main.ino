/*
Yang Xu 500890631
Ruoling Yu 500976267
Xinyu Ma 500943173
*/

// 350 ms for ~90 degrees with speed 200, new batt
#define Safety_Distance 50
#define Minimum_Distance 20
#define Default_Speed 60
#define Slow_Speed 50

int Base_Speed = Default_Speed;
int Default_Turning_Speed = 150;
long Timer1, Timer2, Timer3;

int Lane = 0; // 0: inner, default; 1: outter; -1: exit line following 
int Mode = 0; // 0: line-following, default; 1: follow the light; 2: parking; 3: done parking
int Central, Central_Left, Central_Right, Outer_Left, Outer_Right, Front_Distance, Back_Collision, Back_Right_Collision, Left_Light, Right_Light;



//18 A4
//19 A5
// motor control and pwn pins
#define Left_Motor_Ctrl 4
#define Left_Motor_PWM 5
#define Right_Motor_Ctrl 2
#define Right_Motor_PWM 6

// IR sensor
#define Back_IR_Sensor 3 
#define Back_Right_IR_Sensor 17 // A3

// line tracking
#define Central_Line_Sensor 7
#define Central_Left_Line_Sensor 11
#define Central_Right_Line_Sensor 8
#define Left_Line_Sensor 14 // A0
#define Right_Line_Sensor 10

// ultrasonic sensor
#include "SR04.h"
#define Central_Ultrasonic_Receive 12
#define Central_Ultrasonic_Send 13
SR04 central_sr04 = SR04(Central_Ultrasonic_Send, Central_Ultrasonic_Receive);

// light sensor
#define Left_Light_Sensor 15  // A1
#define Right_Light_Sensor 16 // A2

// servo
#include <Servo.h>
#define Servo_Pin 9
Servo servo;


void setup() 
{
  // initialize serial communication
  Serial.begin(1200); 
  
  // motors
  pinMode(Left_Motor_Ctrl, OUTPUT);
  pinMode(Left_Motor_PWM, OUTPUT);
  pinMode(Right_Motor_Ctrl, OUTPUT);
  pinMode(Right_Motor_PWM, OUTPUT);

  // IR sensor
  pinMode(Back_IR_Sensor, INPUT);
  pinMode(Back_Right_IR_Sensor, INPUT);
  
  // line tracking sensor
  pinMode(Central_Left_Line_Sensor, INPUT);
  pinMode(Central_Line_Sensor, INPUT);
  pinMode(Central_Right_Line_Sensor, INPUT);
  pinMode(Left_Line_Sensor, INPUT);
  pinMode(Right_Line_Sensor, INPUT);
  
  // light sensor
  pinMode(Left_Light_Sensor, INPUT);
  pinMode(Right_Light_Sensor, INPUT);
  
  // servo
  servo_init();

  // Debug
  set_mode(2);
}


void loop()
{
  if (Mode == 0) line_following();
  else if (Mode == 1) light_following();
  else if (Mode == 2) parking();
  else exit(0);  
}

void set_mode(int mode) { Mode = mode; }
