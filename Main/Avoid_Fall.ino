bool fall_detected()
{
  return front_fall_detected() || back_fall_detected();
}

bool front_fall_detected()
{ 
  return digitalRead(Front_Central_Edge_Sensor) || digitalRead(Front_Left_Edge_Sensor) || digitalRead(Front_Right_Edge_Sensor);
}

bool back_fall_detected()
{ 
  return digitalRead(Back_Left_Edge_Sensor) || digitalRead(Back_Right_Edge_Sensor);
}


void avoid_fall()
{
  Serial.print("avoid_fall()\n");
  
  // both
  //if ( front_fall_detected() && back_fall_detected() ) { right_turn(Default_Turning_Speed, 300); }

  // front
  if ( digitalRead(Front_Left_Edge_Sensor) && digitalRead(Front_Right_Edge_Sensor) )
  //else if (digitalRead(Front_Central_Edge_Sensor))
  {
      move_back(200);
      delay(100);
      right_turn(Default_Turning_Speed, 300);
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
  else if (digitalRead(Back_Left_Edge_Sensor) && digitalRead(Back_Right_Edge_Sensor)) 
  {
      move_front(200);
      delay(200);
      stop_movement();
  }
  else if (digitalRead(Back_Left_Edge_Sensor)) 
  {
      move_front(150);
      delay(200);
      left_turn(Default_Turning_Speed, 175);
  }
  else if (digitalRead(Back_Right_Edge_Sensor))
  {
      move_front(150);
      delay(200);
      right_turn(Default_Turning_Speed, 175);
  }
  */
}

// use line following sensor as edge sensors
bool front_central_fall_detection() { return digitalRead(Left_Line_Sensor) || digitalRead(Central_Line_Sensor) || digitalRead(Right_Line_Sensor); }
