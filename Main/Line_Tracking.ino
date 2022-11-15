int Central, Central_Left, Central_Right, Outer_Left, Outer_Right, fall_detection_count;
bool on_track()   { return digitalRead(Central_Line_Sensor) && digitalRead(Central_Left_Line_Sensor) && digitalRead(Central_Right_Line_Sensor); }
bool found_line() { return digitalRead(Central_Line_Sensor) || digitalRead(Central_Left_Line_Sensor) || digitalRead(Central_Right_Line_Sensor); }
bool on_the_line(){ return digitalRead(Central_Line_Sensor) || digitalRead(Central_Left_Line_Sensor) || digitalRead(Central_Right_Line_Sensor) || digitalRead(Left_Line_Sensor) || digitalRead(Right_Line_Sensor); };


//bool if_exit;
void line_following()
{
  fall_detection_count = 0;
  //obj_detection_count = 0;
  timer = millis();
  //move_front(Base_Speed);
  
  while (true)
  {
    if (fall_detection_count == 5)
    {
      if (fall_detected()) { return ; }
      fall_detection_count = 0;
    }
    
    //if (obj_detection_count == 15000)
    if ((millis() - timer) >= 1200)
    {
      stop_movement();
      
      if (central_sr04.Distance() <= Safety_Distance) { return ; }
      //obj_detection_count = 0;
      move_front(Base_Speed);
      timer = millis();
    }
  
    //Serial.print("\tdetection\t");
    Central       = digitalRead(Central_Line_Sensor);
    Central_Left  = digitalRead(Central_Left_Line_Sensor);
    Central_Right = digitalRead(Central_Right_Line_Sensor);
    Outer_Left    = digitalRead(Left_Line_Sensor);
    Outer_Right   = digitalRead(Right_Line_Sensor);
    
    if(Central == 1) { move_front(Base_Speed); }
    else
    {
      if ((Outer_Left == 1) && (Outer_Right == 0))
      {
        left_turn(Default_Turning_Speed, 0);
        //left_forward(Default_Turning_Speed,0);
      }
      else if ((Outer_Left == 0) && (Outer_Right == 1)) 
      {
        right_turn(Default_Turning_Speed, 0);
        //right_forward(Default_Turning_Speed,0);
      }
      else if((Central_Left == 1) && (Central_Right == 0))
      {
        left_turn(Default_Turning_Speed, 0);
        //left_forward(Default_Turning_Speed,0);
      }
      else if((Central_Left == 0) && (Central_Right == 1))
      {
        right_turn(Default_Turning_Speed, 0);
        //right_forward(Default_Turning_Speed,0);
      }
      else
      {   
         move_back(200, 25);
         turn(1, 75, -1);
         if (not on_the_line()) { return ; }
      }
    }
  fall_detection_count ++;  
  //obj_detection_count ++;
  }
}
