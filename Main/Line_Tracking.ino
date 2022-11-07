int Central,Central_Left,Central_Right;

//bool found_line() { return digitalRead(Left_Line_Sensor) || digitalRead(Right_Line_Sensor) || on_track(); }
//bool end_of_line() { return not digitalRead(Left_Line_Sensor) && not digitalRead(Right_Line_Sensor) && not on_track(); }
//bool all_central_line_sensor()      { return digitalRead(Central_Line_Sensor) == 1 && digitalRead(Central_Left_Line_Sensor) == 1 && digitalRead(Central_Right_Line_Sensor) == 1; }
//bool on_track() { return digitalRead(Left_Line_Sensor) == 0 && digitalRead(Right_Line_Sensor) == 0; }
//bool all_central_line_sensor()      { return digitalRead(Central_Line_Sensor) == 1 && digitalRead(Central_Left_Line_Sensor) == 1 && digitalRead(Central_Right_Line_Sensor) == 1; }

bool on_track()   { return digitalRead(Central_Line_Sensor) && digitalRead(Central_Left_Line_Sensor) && digitalRead(Central_Right_Line_Sensor); }
bool found_line() { return digitalRead(Central_Line_Sensor) || digitalRead(Central_Left_Line_Sensor) || digitalRead(Central_Right_Line_Sensor); }
bool end_of_line() { return not found_line(); }

void line_following()
{
  Serial.print("Following Line\n");

  if (fall_detected() || collision_detected())
  { 
    stop_movement();
    //is_following_line = false;
    return ;
  }
    
  Central       = digitalRead(Central_Line_Sensor);
  Central_Left  = digitalRead(Central_Left_Line_Sensor);
  Central_Right = digitalRead(Central_Right_Line_Sensor);

  if(Central == 1)
  {
    move_front(Base_Speed);
    //Serial.print("front\n");
  }
  else
  {
    if(Central_Left && not Central_Right)
    {
      turn(0,50,true);
      //Serial.print("left\n");
    }
    else if(not Central_Left && Central_Right)
    {
      turn(1,50,true);
      //Serial.print("right\n");
    }
    else
    {
      stop_movement();
      //is_following_line = false;
      return ;
    }
  }
}
