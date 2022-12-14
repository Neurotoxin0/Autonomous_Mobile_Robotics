void line_following()
{
    Timer1 = millis();
    Timer2 = millis();
    //Timer3 = millis();
    int stop_count = 0;

    while (Mode == 0)
    { 
      // Obj detection
      if ((millis() - Timer1) >= 1200)
      {
        stop_movement();
        adjust_speed();
        move_front(Base_Speed, false);
        Timer1 = millis();
      }

      // Switch Lane & Detect Light
      if ((millis() - Timer2) >= 800)
      {
        // Switch lane
        if (Base_Speed == 0)
        {
          if (stop_count < 2) stop_count ++;
          else 
          {
            switch_lane(); 
            stop_count = 0;
          }
        }
        else stop_count = 0; // reset stop counter

        // Detect Light
        light_update_signal();
        if (Left_Light == 0 || Right_Light == 0) 
        {
          stop_movement();
          Mode = 1;
          return ;
        }
        
        Timer2 = millis();
      }

      // Line Following
      line_update_signal();
      
      if (Central == 1) { move_front(Base_Speed, false); }
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
      }
    }
}

void switch_lane()
{
  if (Lane == 0)  // inner
  {
    turn(0, 275, -1);
    Lane = 1;
  }
  else // outter
  {
    turn(1, 275, -1);
    Lane = 0;
  }
   
   move_front(Base_Speed, false);
   delay(150);
}

/*
 * enter case: both ouuter left and right
void enter_line() // perpendicular to the line
{
  move_front_with_detection(Base_Speed, 2);  // 400 ms * 2

  int dir = random(2);
  
  while (true) 
  { 
    turn(dir,0, 160); // rotate 360 degree at speed 120
    if (on_the_line()) 
    { 
      stop_movement(); 
      break; 
    }
  }
}
*/
