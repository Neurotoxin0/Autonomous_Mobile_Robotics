int old_forward_speed = -1, old_backward_speed = -1;

void stop_movement()
{
  analogWrite(Left_Motor_PWM, 0);
  analogWrite(Right_Motor_PWM, 0);
}

void move_front(int speed, bool boost)  // @speed: 80 < x < 255
{
  digitalWrite(Left_Motor_Ctrl, HIGH);
  digitalWrite(Right_Motor_Ctrl, HIGH);

  // check if need a start boost
  if ( (speed < 80 && speed != old_forward_speed && speed != 0) || boost )
  {
    analogWrite(Left_Motor_PWM, 100);
    analogWrite(Right_Motor_PWM, 100);
    delay(100);
  }
  
  // set to proper speed
  analogWrite(Left_Motor_PWM, speed);
  analogWrite(Right_Motor_PWM, speed);
  old_forward_speed = speed;
}

void move_back(int speed, int time, bool boost)
{
  digitalWrite(Left_Motor_Ctrl, LOW);
  digitalWrite(Right_Motor_Ctrl, LOW);
  
  if ( (speed < 80 && speed != old_backward_speed && speed != 0) || boost )
  {
    analogWrite(Left_Motor_PWM, 100);
    analogWrite(Right_Motor_PWM, 100);
    delay(200);
  }
  
  analogWrite(Left_Motor_PWM, speed);
  analogWrite(Right_Motor_PWM, speed);
  
  if (time != 0) { delay(time); stop_movement(); }
  old_backward_speed = speed;
}

void left_turn(int speed, int time)   // @params: speed: 80 < x < 255; time: x ms
{
  digitalWrite(Left_Motor_Ctrl, LOW);
  digitalWrite(Right_Motor_Ctrl, HIGH);
  analogWrite(Left_Motor_PWM, speed);
  analogWrite(Right_Motor_PWM, speed);
  if (time != 0) { delay(time); stop_movement(); }
}

void left_forward(int speed, int time)
{
  digitalWrite(Left_Motor_Ctrl, HIGH);
  digitalWrite(Right_Motor_Ctrl, HIGH);
  analogWrite(Left_Motor_PWM, 0);
  analogWrite(Right_Motor_PWM, speed);
  if (time != 0) { delay(time); stop_movement(); }
}

void right_turn(int speed, int time)
{
  digitalWrite(Left_Motor_Ctrl, HIGH);
  digitalWrite(Right_Motor_Ctrl, LOW);
  analogWrite(Left_Motor_PWM, speed);
  analogWrite(Right_Motor_PWM, speed);
  if (time != 0) { delay(time); stop_movement(); }
}

void right_forward(int speed, int time)
{
  digitalWrite(Left_Motor_Ctrl, HIGH);
  digitalWrite(Right_Motor_Ctrl, HIGH);
  analogWrite(Left_Motor_PWM, speed);
  analogWrite(Right_Motor_PWM, 0);
  if (time != 0) { delay(time); stop_movement(); }
}

void turn(int direction, int time, int speed)
{
  int turning_direction, turning_time, turning_speed;

  if (direction != -1)  { turning_direction = direction; }
  else                  { turning_direction = random(2); }
  if (time != -1)       { turning_time = time; }
  else                  { turning_time = random(175, 525); }
  if (speed == -1)       { turning_speed = Default_Turning_Speed; }
  else                  { turning_speed = speed; }
  
  if (! turning_direction)  { left_turn(turning_speed, turning_time); }
  else                      { right_turn(turning_speed, turning_time); }
}
