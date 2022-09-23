// motor control and pwn pins
#define Left_Motor_Ctrl 4
#define Left_Motor_PWM 5
#define Right_Motor_Ctrl 2
#define Right_Motor_PWM 6
#define turning_speed 150 // will turn how many angle in a sec, with speed 200
#define turning_time 2.4  // will cost how many time to turn 360 degrees, with speed 200

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
  //left
  digitalWrite(Left_Motor_Ctrl,LOW);
  analogWrite(Left_Motor_PWM,200);
  digitalWrite(Right_Motor_Ctrl,HIGH);
  analogWrite(Right_Motor_PWM,200);
  //stop
  delay(300);//delay in 2s  
  analogWrite(Left_Motor_PWM,0);
  analogWrite(Right_Motor_PWM,0);
  
  delay(5000);
}
