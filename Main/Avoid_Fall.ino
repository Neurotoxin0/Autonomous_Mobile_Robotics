int Left, Right;

bool fall_detected() { return front_partial_fall_detected() || back_fall_detected(); }
bool front_both_fall_detected() { return digitalRead(Front_Left_Edge_Sensor) && digitalRead(Front_Right_Edge_Sensor); }
bool front_partial_fall_detected() { return digitalRead(Front_Left_Edge_Sensor) || digitalRead(Front_Right_Edge_Sensor); }
bool back_fall_detected() { return digitalRead(Back_Edge_Sensor); }

void avoid_fall()
{
  stop_movement();
  Serial.print("avoid_fall()\n");
  Left  = digitalRead(Front_Left_Edge_Sensor);
  Right = digitalRead(Front_Right_Edge_Sensor);

  /*
  function turn(direction, time) usage: 
    @direction:
      -1: random direction
      0: left
      1: right
    @time:
      -1：random degree
      0: continous turning
      int: turning time
  */
  
  // front and back
  if ( front_both_fall_detected() && back_fall_detected() ) { turn(-1, 350, true); }

  // front
  else if (front_both_fall_detected())            { move_back(Base_Speed, 100); turn(-1, -1, false); }
  else if (Left)   { turn(1, -1, false); }
  else if (Right)  { turn(0, -1, false); }
 
  // back
  else if (back_fall_detected())
  {
      if (can_move_front())
      {
        move_front(Base_Speed);
        delay(150);
        stop_movement();
      }
      else { turn(-1, 350, true); }
  }
}
