void stop_movement()
{
  analogWrite(Left_Motor_PWM, 0);
  analogWrite(Right_Motor_PWM, 0);
}

void move_front(int speed)  // @params: speed: 80 < x < 255
{
  digitalWrite(Left_Motor_Ctrl, HIGH);
  analogWrite(Left_Motor_PWM, speed);
  digitalWrite(Right_Motor_Ctrl, HIGH);
  analogWrite(Right_Motor_PWM, speed);
}

void move_back(int speed)
{
  stop_movement();
  
  if (can_move_back())
  {
    digitalWrite(Left_Motor_Ctrl, LOW);
    analogWrite(Left_Motor_PWM, speed);
    digitalWrite(Right_Motor_Ctrl, LOW);
    analogWrite(Right_Motor_PWM, speed);
  }
}

void left_turn(int speed, int time)   // @params: speed: 80 < x < 255; time: x ms
{
  digitalWrite(Left_Motor_Ctrl, LOW);
  analogWrite(Left_Motor_PWM, speed);
  digitalWrite(Right_Motor_Ctrl, HIGH);
  analogWrite(Right_Motor_PWM, speed);
  delay(time);
  stop_movement();
}

void right_turn(int speed, int time)
{
  digitalWrite(Left_Motor_Ctrl, HIGH);
  analogWrite(Left_Motor_PWM, speed);
  digitalWrite(Right_Motor_Ctrl, LOW);
  analogWrite(Right_Motor_PWM, speed);
  delay(time);
  stop_movement();
}

bool can_move_back() { return not ( digitalRead(Back_Left_Edge_Sensor) || digitalRead(Back_Right_Edge_Sensor) ); }
