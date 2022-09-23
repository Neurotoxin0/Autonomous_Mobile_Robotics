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

void setup() 
{
  // motors
  pinMode(Left_Motor_Ctrl, OUTPUT);
  pinMode(Left_Motor_PWM, OUTPUT);
  pinMode(Right_Motor_Ctrl, OUTPUT);
  pinMode(Right_Motor_PWM, OUTPUT);
}

void loop() 
{
  move_front(100);
  delay(2000);
  stop_movement();
  delay(2000);
}
