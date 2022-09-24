bool fall_detected()
{
  //return front_central_fall_detection() || digitalRead(Front_Left_Sensor) || digitalRead(Front_Right_Sensor) || digitalRead(Back_Left_Sensor) || digitalRead(Back_Right_Sensor);
  return front_central_fall_detection();
}


void avoid_fall()
{
  if (front_central_fall_detection())
  {
      move_back(200);
      delay(100);
      right_turn(Default_Turning_Speed, 350);
  }
  /*
  else if (digitalRead(Front_Left_Sensor))
  {
      move_back(200);
      delay(100);
      left_turn(Default_Turning_Speed, 350);
  }
  else if (digitalRead(Front_Right_Sensor))
  {
      move_back(200);
      delay(100);
      right_turn(Default_Turning_Speed, 350);
  }
  else if (digitalRead(Back_Left_Sensor))
  {
      move_back(200);
      delay(100);
      right_turn(Default_Turning_Speed, 350);
  }
  else if (digitalRead(Back_Right_Sensor))
  {
      move_back(200);
      delay(100);
      left_turn(Default_Turning_Speed, 350);
  }
  */
}

bool front_central_fall_detection() { return digitalRead(Front_Central_Left_Sensor) || digitalRead(Front_Central_Middle_Sensor) || digitalRead(Front_Central_Right_Sensor); }
