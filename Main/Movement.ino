bool can_move_front() { return not ( front_fall_detected() || collision_detected() ); }
bool can_move_back() { return not digitalRead(Back_Edge_Sensor); }

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
}

void left_turn(int speed, int time)   // @params: speed: 80 < x < 255; time: x ms
{
  // detect if turn will collide with object
  stop_movement();
  servo.write(135);
  ultra_sonic_update_distance();
  
  if (not left_distance <= Minimum_Distance) 
  {
    digitalWrite(Left_Motor_Ctrl, LOW);
    analogWrite(Left_Motor_PWM, speed);
    digitalWrite(Right_Motor_Ctrl, HIGH);
    analogWrite(Right_Motor_PWM, speed);
    delay(time);
    stop_movement();
  }
  else { move_back(Base_Speed, 200); }  
}

void right_turn(int speed, int time)
{
  // detect if turn will collide with object
  stop_movement();
  servo.write(45);
  ultra_sonic_update_distance();
  
  if (not right_distance <= Minimum_Distance) 
  {
    digitalWrite(Left_Motor_Ctrl, HIGH);
    analogWrite(Left_Motor_PWM, speed);
    digitalWrite(Right_Motor_Ctrl, LOW);
    analogWrite(Right_Motor_PWM, speed);
    delay(time);
    stop_movement();
  }
  else { move_back(Base_Speed, 200); }  
}

void random_turn(int input)
{
  int turning_direction = random(2);
  int turning_time;
  
  if (input != 0) { turning_time = input; }
  else            { turning_time = random(175, 500); }
  
  if (turning_direction)  { left_turn(Default_Turning_Speed, turning_time); }
  else                    { right_turn(Default_Turning_Speed, turning_time); }
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
  
  Default_Turning_Speed = Base_Speed * 3.0;
  //Slow_Turning_Speed = Base_Speed;
  stop_movement();
  Serial.print("FINAL Base Speed & Default Turing Speed: ");
  Serial.print(Base_Speed);
  Serial.print("\t");
  Serial.print(Default_Turning_Speed);
  Serial.print("\n");
}
