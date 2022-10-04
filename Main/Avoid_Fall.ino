bool front_fall_detected(){ return digitalRead(Front_Left_Edge_Sensor) || digitalRead(Front_Right_Edge_Sensor); }

bool back_fall_detected() { return digitalRead(Back_Left_Edge_Sensor) || digitalRead(Back_Right_Edge_Sensor); }


void avoid_fall()
{
  stop_movement();
  Serial.print("avoid_fall()\n");
  
  // both
  if ( front_fall_detected() && back_fall_detected() ) { random_turn(350); }

  // front
  else if ( digitalRead(Front_Left_Edge_Sensor) && digitalRead(Front_Right_Edge_Sensor) )
  //else if (front_central_fall_detection())
  {
      move_back(200);
      delay(100);
      random_turn(0);
  }
  else if (digitalRead(Front_Left_Edge_Sensor))
  {
      move_back(200);
      delay(100);
      right_turn(Default_Turning_Speed, 175);
      
  }
  else if (digitalRead(Front_Right_Edge_Sensor))
  {
      move_back(200);
      delay(100);
      left_turn(Default_Turning_Speed, 175);
  }
  
  /*
  // back
  else if ( digitalRead(Back_Left_Edge_Sensor) && digitalRead(Back_Right_Edge_Sensor) )
  {
      move_front(100);
      delay(200);
      stop_movement();
  }
  */
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

// use line tracking sensor as edge sensors
bool front_central_fall_detection() { return digitalRead(Left_Line_Sensor) || digitalRead(Central_Line_Sensor) || digitalRead(Right_Line_Sensor); }
