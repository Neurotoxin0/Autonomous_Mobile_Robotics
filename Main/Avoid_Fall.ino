void avoid_fall()
{
  if (front_central_fall_detection())
  {
      move_back(80); // @params: speed; 80 < x < 255
      delay(500);
      right_turn(350);// @params: time; x ms
  }
  /*
  else if (digitalRead(Front_Left_Sensor))
  {
      move_back(80);
      delay(500);
      left_turn(350);
  }
  else if (digitalRead(Front_Right_Sensor))
  {
      move_back(80);
      delay(500);
      right_turn(350);
  }
  else if (digitalRead(Back_Left_Sensor))
  {
      move_front(80);
      delay(500);
      right_turn(350);
  }
  else if (digitalRead(Back_Right_Sensor))
  {
      move_front(80);
      delay(500);
      left_turn(350);
  }
  */
}

bool front_central_fall_detection() { return digitalRead(Front_Central_Left_Sensor) || digitalRead(Front_Central_Middle_Sensor) || digitalRead(Front_Central_Right_Sensor); }
