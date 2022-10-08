bool front_fall_detected(){ return digitalRead(Front_Left_Edge_Sensor) || digitalRead(Front_Right_Edge_Sensor); }

void avoid_fall()
{
  stop_movement();
  Serial.print("avoid_fall()\n");
  
  // both
  if ( front_fall_detected() && digitalRead(Back_Edge_Sensor) ) { random_turn(350); }

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
      right_turn(Default_Turning_Speed, random(175,350));
      
  }
  else if (digitalRead(Front_Right_Edge_Sensor))
  {
      move_back(200);
      delay(100);
      left_turn(Default_Turning_Speed, random(175,350));
  }
  
  // back
  else if (digitalRead(Back_Edge_Sensor))
  {
      move_front(100);
      delay(200);
      stop_movement();
  }
}
