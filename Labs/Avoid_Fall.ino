int Left, Right, Back;

bool fall_detected() { return front_partial_fall_detected() || back_fall_detected(); }
bool front_both_fall_detected() { return digitalRead(Front_Left_Edge_Sensor) && digitalRead(Front_Right_Edge_Sensor); }
bool front_partial_fall_detected() { return digitalRead(Front_Left_Edge_Sensor) || digitalRead(Front_Right_Edge_Sensor); }
bool back_fall_detected() { return digitalRead(Back_Edge_Sensor); }

void avoid_fall()
{
  stop_movement();
  //Serial.print("avoid_fall()\n");
  Left  = digitalRead(Front_Left_Edge_Sensor);
  Right = digitalRead(Front_Right_Edge_Sensor);
  Back  = digitalRead(Back_Edge_Sensor);

  // front and back
  if ( Left && Right && Back ) { turn(-1, 350, -1); }

  // front
  else if (Left && Right) { move_back(Base_Speed, 100); turn(-1, -1, -1); }
  else if (Left)          { turn(1, -1, -1); }
  else if (Right)         { turn(0, -1, -1); }
 
  // back
  else if (Back)
  {
      if (can_move_front())
      {
        move_front(Base_Speed);
        delay(150);
        stop_movement();
      }
      else { turn(-1, 350, -1); }
  }
}
