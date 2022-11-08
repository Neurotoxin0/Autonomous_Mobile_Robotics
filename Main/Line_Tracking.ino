//int Central,Central_Left,Central_Right;

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
  while (true)
  {
    //if (fall_detected() || collision_detected()) { return ; }
     if (fall_detected()) { return ; }
    
    Central       = digitalRead(Central_Line_Sensor);
    Central_Left  = digitalRead(Central_Left_Line_Sensor);
    Central_Right = digitalRead(Central_Right_Line_Sensor);

    if(Central == 1)
    {
      move_front(Base_Speed);
    }
    else
    {
      if((Central_Left == 1) && (Central_Right == 0))
      {
        left_turn(Default_Turning_Speed, 0);
      }
      else if((Central_Left == 0) && (Central_Right == 1))
      {
        right_turn(Default_Turning_Speed, 0);
      }
      else
      {
        move_front(Base_Speed);
        //delay(200);
        //stop_movement();
        return ;
      }
     }
    
    
  }
}
