const int Turning_Speed = 200;
// 350~400 ms for ~45 degrees with speed 200

void stop_movement()
{
  analogWrite(Left_Motor_PWM, 0);
  analogWrite(Right_Motor_PWM, 0);
}

void move_front(int speed)
{
  digitalWrite(Left_Motor_Ctrl, HIGH);
  analogWrite(Left_Motor_PWM, speed);
  digitalWrite(Right_Motor_Ctrl, HIGH);
  analogWrite(Right_Motor_PWM, speed);
}

void move_back(int speed)
{
  digitalWrite(Left_Motor_Ctrl, LOW);
  analogWrite(Left_Motor_PWM, speed);
  digitalWrite(Right_Motor_Ctrl, LOW);
  analogWrite(Right_Motor_PWM, speed);
}

void left_turn(int time)
{
  digitalWrite(Left_Motor_Ctrl,LOW);
  analogWrite(Left_Motor_PWM,Turning_Speed);
  digitalWrite(Right_Motor_Ctrl,HIGH);
  analogWrite(Right_Motor_PWM,Turning_Speed);
  delay(time);
  stop_movement();
}

void right_turn(int time)
{
  digitalWrite(Left_Motor_Ctrl,HIGH);
  analogWrite(Left_Motor_PWM,Turning_Speed);
  digitalWrite(Right_Motor_Ctrl,LOW);
  analogWrite(Right_Motor_PWM,Turning_Speed);
  delay(time);
  stop_movement();
}
