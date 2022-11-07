bool can_move_front() { return not ( front_partial_fall_detected() || front_collision_detected() ) ; }
bool can_move_back()  { return not back_fall_detected(); }
bool can_turn_left()  { return not left_distance  <= Minimum_Distance; }
bool can_turn_right() { return not right_distance <= Minimum_Distance; }

void stop_movement()
{
  analogWrite(Left_Motor_PWM, 0);
  analogWrite(Right_Motor_PWM, 0);
}

void move_front(int speed)  // @speed: 80 < x < 255
{
  digitalWrite(Left_Motor_Ctrl, HIGH);
  analogWrite(Left_Motor_PWM, speed);
  digitalWrite(Right_Motor_Ctrl, HIGH);
  analogWrite(Right_Motor_PWM, speed);
}

void move_back(int speed, int time)
{
  stop_movement();
  
  if (can_move_back())
  { 
    digitalWrite(Left_Motor_Ctrl, LOW);
    analogWrite(Left_Motor_PWM, speed);
    digitalWrite(Right_Motor_Ctrl, LOW);
    analogWrite(Right_Motor_PWM, speed);
    delay(time);
    stop_movement();
  }
  //else { random_turn(350); }
}

void left_turn(int speed, int time, bool force)   // @params: speed: 80 < x < 255; time: x ms
{
  if (can_turn_left() || force)
  {
    digitalWrite(Left_Motor_Ctrl, LOW);
    analogWrite(Left_Motor_PWM, speed);
    digitalWrite(Right_Motor_Ctrl, HIGH);
    analogWrite(Right_Motor_PWM, speed);
    if (time != 0) { delay(time); stop_movement(); }
  }
}

void right_turn(int speed, int time, bool force)
{
  if (can_turn_right() || force)
  {
    digitalWrite(Left_Motor_Ctrl, HIGH);
    analogWrite(Left_Motor_PWM, speed);
    digitalWrite(Right_Motor_Ctrl, LOW);
    analogWrite(Right_Motor_PWM, speed);
    if (time != 0) { delay(time); stop_movement(); }
  }
}

void turn(int direction, int time, bool force)
{
  int turning_direction, turning_time;

  if (direction != -1)  { turning_direction = direction; }
  else                  { turning_direction = random(2); }
  if (time != -1)        { turning_time = time; }
  else                  { turning_time = random(175, 525); }
  
  if (! turning_direction)  { left_turn(Default_Turning_Speed, turning_time, force); }
  else                      { right_turn(Default_Turning_Speed, turning_time, force); }
}

void motor_speed_adjust()
{
  move_front(Base_Speed);
  Serial.print("\nCurrent Base Speed: ");
  Serial.print(Base_Speed);
  Serial.print("\n");
  
  while ( digitalRead(Back_Edge_Sensor) && Base_Speed < 120)
  {
    Base_Speed += 5;
    Serial.print("Adjust Base Speed to: ");
    Serial.print(Base_Speed);
    Serial.print("\n");
    move_front(Base_Speed);
    delay(750);
  }
  
  stop_movement();
  Serial.print("FINAL Base Speed & Default Turing Speed: ");
  Serial.print(Base_Speed);
  Serial.print("\n");
}
