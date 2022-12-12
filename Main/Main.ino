/*
Yang Xu 500890631
Ruoling Yu 500976267
Xinyu Ma 500943173
*/

#define Safety_Distance 40
#define Minimum_Distance 25
// 350 ms for ~90 degrees with speed 200, new batt
int Base_Speed = 65;
int Default_Turning_Speed = 200;
long timer1, timer2;

int lane = 0; // 0: inner, default; 1: outter; -1: exit line following 
int mode = 0; // 0: line-following, default; 1: parking
long central_distance;

//18 A4
//19 A5
//15 A1
//16 A2   
// motor control and pwn pins
#define Left_Motor_Ctrl 4
#define Left_Motor_PWM 5
#define Right_Motor_Ctrl 2
#define Right_Motor_PWM 6

// edge sensor
#define Front_Left_Edge_Sensor 10
#define Front_Right_Edge_Sensor 9
#define Back_Edge_Sensor 3 

// line tracking
#define Central_Line_Sensor 7
#define Central_Left_Line_Sensor 11
#define Central_Right_Line_Sensor 8
#define Left_Line_Sensor 17           // A3
#define Right_Line_Sensor 14          // A0

// ultrasonic sensor
#include "SR04.h"
#define Central_Ultrasonic_Receive 12
#define Central_Ultrasonic_Send 13
SR04 central_sr04 = SR04(Central_Ultrasonic_Send, Central_Ultrasonic_Receive);

// light sensor
//#define Left_Light_Sensor 15  // A1
//#define Right_Light_Sensor 16 // A2

// servo
#include <Servo.h>
#define Servo_Pin 18
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

  // edge sensor
  pinMode(Front_Left_Edge_Sensor, INPUT);
  pinMode(Front_Right_Edge_Sensor, INPUT);
  pinMode(Back_Edge_Sensor, INPUT);
  
  // line tracking sensor
  pinMode(Central_Left_Line_Sensor, INPUT);
  pinMode(Central_Line_Sensor, INPUT);
  pinMode(Central_Right_Line_Sensor, INPUT);
  pinMode(Left_Line_Sensor, INPUT);
  pinMode(Right_Line_Sensor, INPUT);
  
  // light sensor
  //pinMode(Left_Light_Sensor, INPUT);
  //pinMode(Right_Light_Sensor, INPUT);
  
  // servo
  servo_init();

  // motor
  //motor_speed_adjust();
}

void loop()
{
  if (!mode) line_following();
  else parking();
  
}


void enter_line() // perpendicular to the line
{
  move_front_with_detection(Base_Speed, 2);  // 400 ms * 2

  int dir = random(2);
  
  while (true) 
  { 
    turn(dir,0, 160); // rotate 360 degree at speed 120
    if (on_the_line()) 
    { 
      stop_movement(); 
      break; 
    }
  }
  
}
