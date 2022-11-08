int Central, Central_Left, Central_Right, Outer_Left, Outer_Right;

bool on_track()   { return digitalRead(Central_Line_Sensor) && digitalRead(Central_Left_Line_Sensor) && digitalRead(Central_Right_Line_Sensor); }
bool found_line() { return digitalRead(Central_Line_Sensor) || digitalRead(Central_Left_Line_Sensor) || digitalRead(Central_Right_Line_Sensor); }
//bool end_of_line() { return not found_line(); }

void line_following()
{
  while (true)
  {
    //if (fall_detected() || collision_detected()) { return ; }
    if (fall_detected()) { return ; }
    //if(central_sr04.Distance() <= Safety_Distance) { return ; }
    
    Central       = digitalRead(Central_Line_Sensor);
    Central_Left  = digitalRead(Central_Left_Line_Sensor);
    Central_Right = digitalRead(Central_Right_Line_Sensor);
    Outer_Left    = digitalRead(Left_Line_Sensor);
    Outer_Right   = digitalRead(Right_Line_Sensor);

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
      else if ((Outer_Left == 1) && (Outer_Right == 0))
      {
        left_turn(Default_Turning_Speed, 0);
      }
      else if ((Outer_Left == 0) && (Outer_Right == 1)) 
      {
        right_turn(Default_Turning_Speed, 0);
      }
      else if (Central || Central_Left || Central_Right || Outer_Left || Outer_Right)
      {
          move_back(200,50);
      }
      else
      {
        stop_movement();
        //Serial.print("Exit Line Following\n");
        return ;
      }
     }
    
    
  }
}
