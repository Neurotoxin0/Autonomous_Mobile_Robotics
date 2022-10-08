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
  
  if (not digitalRead(Back_Edge_Sensor))
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

void random_turn(int input)
{
  int turning_direction = random(2);
  int turning_time;
  
  if (input != 0) { turning_time = input; }
  else { turning_time = random(175, 700); }
  
  if (turning_direction)  { left_turn(Default_Turning_Speed, turning_time); }
  else                    { right_turn(Default_Turning_Speed, turning_time); }
}

void motor_speed_adjust()
{
  move_front(Base_Speed);
  Serial.print("\nBase Speed: ");
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
  
  Base_Speed += 2;
  Serial.print("FINAL Base Speed: ");
  Serial.print(Base_Speed);
  Serial.print("\n");
}
