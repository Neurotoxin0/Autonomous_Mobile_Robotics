int Central,Central_Left,Central_Right;

//bool found_line() { return digitalRead(Left_Line_Sensor) || digitalRead(Right_Line_Sensor) || on_track(); }
//bool end_of_line() { return not digitalRead(Left_Line_Sensor) && not digitalRead(Right_Line_Sensor) && not on_track(); }
bool on_track() { return digitalRead(Central_Line_Sensor) == 1 && digitalRead(Central_Left_Line_Sensor) == 1 && digitalRead(Central_Right_Line_Sensor) == 1; }
//bool all_central_line_sensor()      { return digitalRead(Central_Line_Sensor) == 1 && digitalRead(Central_Left_Line_Sensor) == 1 && digitalRead(Central_Right_Line_Sensor) == 1; }

bool found_line() { return digitalRead(Central_Line_Sensor) == 1 || digitalRead(Central_Left_Line_Sensor) == 1 || digitalRead(Central_Right_Line_Sensor) == 1; }
bool end_of_line() { return not found_line(); }
//bool on_track() { return digitalRead(Left_Line_Sensor) == 0 && digitalRead(Right_Line_Sensor) == 0; }
//bool all_central_line_sensor()      { return digitalRead(Central_Line_Sensor) == 1 && digitalRead(Central_Left_Line_Sensor) == 1 && digitalRead(Central_Right_Line_Sensor) == 1; }

void line_following()
{
  if (fall_detected() || collision_detected())
  { 
    stop_movement();
    is_following_line = false;
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
    if(Central_Left == 1 && Central_Right == 0)
    {
      turn(0,50,true);
      //Serial.print("left\n");
    }
    else if(Central_Left == 0 && Central_Right == 1)
    {
      turn(1,50,true);
      //Serial.print("right\n");
    }
    else
    {
      stop_movement();
      is_following_line = false;
      return ;
    }
  }


  /*
  // Central Sensors
  if ( digitalRead(Central_Left_Line_Sensor) == 0 && digitalRead(Central_Right_Line_Sensor) == 1 ) 
  { 
    right_turn(Default_Turning_Speed, 100, true); 
    // TODO: move front a bit until detect a line
  }
  
  if ( digitalRead(Central_Left_Line_Sensor) == 1 && digitalRead(Central_Right_Line_Sensor) == 0 ) 
  { 
    left_turn(Default_Turning_Speed, 100, true); 
    // TODO: move front a bit until detect a line
  }
  
  // Outer Sensors
  if ( digitalRead(Left_Line_Sensor) == 0 && digitalRead(Right_Line_Sensor) == 1 ) 
  { 
    right_turn(Default_Turning_Speed, 350, true); 
  }
  
  if ( digitalRead(Left_Line_Sensor) == 1 && digitalRead(Right_Line_Sensor) == 0 ) 
  { 
    left_turn(Default_Turning_Speed, 350, true); 
  }
  */
}
