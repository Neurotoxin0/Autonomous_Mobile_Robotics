void move_front(int speed)
{
  digitalWrite(Left_Motor_Ctrl,HIGH);
  analogWrite(Left_Motor_PWM,speed);
  digitalWrite(Right_Motor_Ctrl,HIGH);
  analogWrite(Right_Motor_PWM,speed);
}

void stop_movement()
{
  analogWrite(Left_Motor_PWM,0);
  analogWrite(Right_Motor_PWM,0);
}
