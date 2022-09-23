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
  //left
  digitalWrite(ML_Ctrl,LOW);//set the direction control pin of B motor to LOW
  analogWrite(ML_PWM,200);//set the PWM control speed of B motor to 200
  digitalWrite(MR_Ctrl,HIGH);//set the direction control pin of A motor to HIGH
  analogWrite(MR_PWM,200);// set the PWM control speed of A motor to 200
  //stop
  delay(5000);//delay in 2s
  analogWrite(ML_PWM,0);//set the PWM control speed of B motor to 0
  analogWrite(MR_PWM,0);//set the PWM control speed of A motor to 0
  
  delay(5000);
}
