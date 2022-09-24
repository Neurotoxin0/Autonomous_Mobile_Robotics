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
const int Default_Turning_Speed = 200;  // 350 ms for ~90 degrees with speed 200

// fall & line tracking sensor
#define Front_Central_Left_Sensor 11
#define Front_Central_Middle_Sensor 7
#define Front_Central_Right_Sensor 8
//#define Front_Left_Sensor 0
//#define Front_Right_Sensor 0
//#define Back_Left__Sensor 0
//#define Back_Right_Sensor 0

// servo
#include <Servo.h>
#define Servo_Pin 10
Servo servo;

// ultrasonic sensor
#include "SR04.h" //ultrasonic sensor lib
#define Ultrasonic_Receive 12
#define Ultrasonic_Send 13
SR04 sr04 = SR04(Ultrasonic_Send,Ultrasonic_Receive);

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
  
  // servo
  servo_init();
  
}

void loop()
{
  while ( safe() /*&& on_track()*/) { move_front(80); }
  stop_movement();
  
  if (fall_detected()) { avoid_fall(); }
  if (collision_detected()) { avoid_object(); }
  //if (not on_track()) { back_on_track(); }
}

bool safe() { return not ( fall_detected() || collision_detected() ); }
