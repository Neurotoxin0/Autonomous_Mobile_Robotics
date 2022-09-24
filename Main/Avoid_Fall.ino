bool fall_detected()
{
  //return (front_central_fall_detection()) || (digitalRead(Left_Edge_Sensor)) || (digitalRead(Right_Edge_Sensor));
  return front_central_fall_detection();
}


void avoid_fall()
{
  //if ( digitalRead(Left_Edge_Sensor)() && digitalRead(Right_Edge_Sensor) )
  if (front_central_fall_detection())
  {
      move_back(200);
      delay(100);
      right_turn(Default_Turning_Speed, 175);
  }
  /*
  else if (digitalRead(Left_Edge_Sensor))
  {
      move_back(200);
      delay(100);
      left_turn(Default_Turning_Speed, 175);
  }
  else if (digitalRead(Right_Edge_Sensor))
  {
      move_back(200);
      delay(100);
      right_turn(Default_Turning_Speed, 175);
  }
  */
}

bool front_central_fall_detection() { return digitalRead(Left_Line_Sensor) || digitalRead(Central_Line_Sensor) || digitalRead(Right_Line_Sensor); }
