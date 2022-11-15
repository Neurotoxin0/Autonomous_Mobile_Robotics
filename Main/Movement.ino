bool can_move_front() { return not ( front_partial_fall_detected() || front_collision_detected() ) ; }
bool can_move_back()  { return not back_fall_detected(); }

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

void move_front_with_detection(int speed, int times) // @time: how many times
{
  for (int i = 0; i < times; i++)
  {
    if      (fall_detected()) { avoid_fall(); }
    else if (collision_detected()) { avoid_object(); }
    else           
    { 
      move_front(Base_Speed); 
      delay(400);
      stop_movement();
    }
  }
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

void left_turn(int speed, int time)   // @params: speed: 80 < x < 255; time: x ms
{
  digitalWrite(Left_Motor_Ctrl, LOW);
  analogWrite(Left_Motor_PWM, speed);
  digitalWrite(Right_Motor_Ctrl, HIGH);
  analogWrite(Right_Motor_PWM, speed);
  if (time != 0 && time != -1) { delay(time); stop_movement(); }
}

void left_forward(int speed, int time)
{
  digitalWrite(Left_Motor_Ctrl, HIGH);
  analogWrite(Left_Motor_PWM, 0);
  digitalWrite(Right_Motor_Ctrl, HIGH);
  analogWrite(Right_Motor_PWM, speed);
  if (time != 0 && time != -1) { delay(time); stop_movement(); }
}

void right_turn(int speed, int time)
{
  digitalWrite(Left_Motor_Ctrl, HIGH);
  analogWrite(Left_Motor_PWM, speed);
  digitalWrite(Right_Motor_Ctrl, LOW);
  analogWrite(Right_Motor_PWM, speed);
  if (time != 0 && time != -1) { delay(time); stop_movement(); }
}

void right_forward(int speed, int time)
{
  digitalWrite(Left_Motor_Ctrl, HIGH);
  analogWrite(Left_Motor_PWM, speed);
  digitalWrite(Right_Motor_Ctrl, HIGH);
  analogWrite(Right_Motor_PWM, 0);
  if (time != 0 && time != -1) { delay(time); stop_movement(); }
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
