bool fall_detected()
{ 
  //return (digitalRead(Left_Edge_Sensor)) || (digitalRead(Right_Edge_Sensor));
  return front_central_fall_detection(); 
}

void avoid_fall()
{
  Serial.print("avoid_fall()\n");
  
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

// use line following sensor as edge sensors
bool front_central_fall_detection() { return digitalRead(Left_Line_Sensor) || digitalRead(Central_Line_Sensor) || digitalRead(Right_Line_Sensor); )
