int Central, Central_Left, Central_Right, Outer_Left, Outer_Right, detection_count, rotation_count;
bool on_track()   { return digitalRead(Central_Line_Sensor) && digitalRead(Central_Left_Line_Sensor) && digitalRead(Central_Right_Line_Sensor); }
bool found_line() { return digitalRead(Central_Line_Sensor) || digitalRead(Central_Left_Line_Sensor) || digitalRead(Central_Right_Line_Sensor); }
bool on_the_line(){ return digitalRead(Central_Line_Sensor) || digitalRead(Central_Left_Line_Sensor) || digitalRead(Central_Right_Line_Sensor) || digitalRead(Left_Line_Sensor) || digitalRead(Right_Line_Sensor); };

void enter_line() // line around, rotate to find the line
{
  move_front(Base_Speed);
  delay(850);
  stop_movement();
  rotation_count = 0;
  
  while (rotation_count <= 50)  // TODO: Test suitable # for rotation_count
  { 
    turn(-1,0, 160);
    if (on_the_line()) { stop_movement(); break; }
    else { rotation_count ++; }
  }
}

void line_following()
{
  detection_count = 0;
  //timer.tick();
  
  while (true)
  {
    // Stop for detection
    if (detection_count == 5) 
    {
      //stop_movement();
      if (fall_detected()) { return ; }
      //if (fall_detected() || collision_detected()) { return ; }
      detection_count = 0;
    }
    /*timer.every(1000, detection);
    if (if_exit) return ;*/

    //Serial.print("line_following()\n");
    Central       = digitalRead(Central_Line_Sensor);
    Central_Left  = digitalRead(Central_Left_Line_Sensor);
    Central_Right = digitalRead(Central_Right_Line_Sensor);
    Outer_Left    = digitalRead(Left_Line_Sensor);
    Outer_Right   = digitalRead(Right_Line_Sensor);
    
    if (Central == 1) { move_front(Base_Speed); }
    else
    {
      if((Central_Left == 1) && (Central_Right == 0))       { left_turn(Default_Turning_Speed, 0); }
      else if((Central_Left == 0) && (Central_Right == 1))  { right_turn(Default_Turning_Speed, 0); }
      else if ((Outer_Left == 1) && (Outer_Right == 0))     { left_turn(Default_Turning_Speed, 0); }
      else if ((Outer_Left == 0) && (Outer_Right == 1))     { right_turn(Default_Turning_Speed, 0); }
      else
      {
         move_back(200, 25);                  // move back to re-adjust sensors
         if (not on_the_line()) { return ; }  // exit case
      }
    }
  detection_count ++;  
  }
}

/*
bool detection()
{
  if (fall_detected() || collision_detected()) 
  {
    if_exit = true;
    return 1;
  }
  else 
  {
    if_exit = false;
    return 0;
  }
}*/
