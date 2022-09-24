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
const int Slow_Turning_Speed = 80;

// line tracking & edge sensor
#define Left_Line_Sensor 11
#define Central_Line_Sensor 7
#define Right_Line_Sensor 8
#define Left_Edge_Sensor 17  // A3
#define Right_Edge_Sensor 14 // A0

// light sensor
#define Left_Light_Sensor 15  // A1
#define Right_Light_Sensor 16 // A2

// servo
#include <Servo.h>
#define Servo_Pin 10
Servo servo;

// ultrasonic sensor
#include "SR04.h" //ultrasonic sensor lib
#define Ultrasonic_Receive 12
#define Ultrasonic_Send 13
SR04 sr04 = SR04(Ultrasonic_Send,Ultrasonic_Receive);

// other global params
int tries;

void setup() 
{
  // initialize serial communication
  Serial.begin(1200); 
  
  // motors
  pinMode(Left_Motor_Ctrl, OUTPUT);
  pinMode(Left_Motor_PWM, OUTPUT);
  pinMode(Right_Motor_Ctrl, OUTPUT);
  pinMode(Right_Motor_PWM, OUTPUT);

  // fall & line tracking sensor
  pinMode(Left_Line_Sensor, INPUT);
  pinMode(Central_Line_Sensor, INPUT);
  pinMode(Right_Line_Sensor, INPUT);
  pinMode(Left_Edge_Sensor, INPUT);
  pinMode(Right_Edge_Sensor, INPUT);

  // light sensor
  pinMode(Left_Light_Sensor, INPUT);
  pinMode(Right_Light_Sensor, INPUT);
  
  // servo
  servo_init();
  
}

void loop()
{
  Serial.print("\n");
  
  //while ( safe() && following_line() ) { move_front(80); }
  /*while (safe()) { move_front(80); }
  stop_movement();
  
  if (fall_detected()) { avoid_fall(); }
  if (collision_detected()) { avoid_object(); }
  */
  if (not following_line()) 
  { 
    if (not adjust_line_tracking()) { exit(0); };  // if failed to adjust: exit
  }
  /*
  if (not following_light()) 
  { 
    if (not adjust_light_following()) { exit(0); }; 
  }
  */
}

bool safe() 
{ 
  bool result = not ( fall_detected() || collision_detected() );
  Serial.print("Safe Sataus: ");
  Serial.print(result);
  Serial.print("\n");
  return result;
}
