void lane_following()
{
    Timer1 = millis();
    Timer2 = millis();
    //Timer3 = millis();
    int stop_count = 0;

    while (Mode == 1)
    { 
      // Light detection
      //light_detect();
      
      // Obj detection
      if ((millis() - Timer1) >= 1200)
      {
        stop_movement();
        adjust_speed();
        move_front(Base_Speed, false);
        Timer1 = millis();
      }

      // Switch Lane
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
        
        Timer2 = millis();
      }

      // Line Following
      line_following();
    }
}

void line_following()
{
  line_update_signal();
      
  if (Central == 1) { move_front(Base_Speed, false); }
  else if(Central_Left == 1 && Central_Right == 0)
  {
    left_turn(Default_Turning_Speed, 0);
  }
  else if(Central_Left == 0 && Central_Right == 1)
  {
    right_turn(Default_Turning_Speed, 0);
  }
  else if (Outer_Left == 1 && Outer_Right == 0)
  {
    left_turn(Default_Turning_Speed, 0);
  }
  else if (Outer_Left == 0 && Outer_Right == 1) 
  {
    right_turn(Default_Turning_Speed, 0);
  }
}

bool flag = false;
void switch_lane()
{
   move_back(80, 250, false);
   
   while (true)
   {
    if (Lane == 1) 
    {
      // use front ultra sonic sensor + servo to 180 degree
      servo_to_angle(180);
      front_ultra_sonic_update_distance();
      
      if (Front_Distance > Minimum_Distance)
      {
        turn(0, 250, -1);
        front_ultra_sonic_update_distance();
        if (Front_Distance > Minimum_Distance)
        {
          flag = true;
          Lane = 1;
        }
      }
    }
    else 
    {
      // use right ultra sonic sensor
      right_ultra_sonic_update_distance();

      if (Right_Distance > Minimum_Distance)
      {
        turn(1, 200 + 15 * Battery_Ratio, -1);
        front_ultra_sonic_update_distance();
        if (Right_Distance > Minimum_Distance)
        {
          flag = true;
          Lane = 0;
        }
      }
    }
    
    while (flag)
    {
      front_update_signal();
      
      if (Outer_Left || Outer_Right ) 
      {
        servo_to_angle(90);
        delay(250);
        stop_movement();
        return;
      }
      else move_front(47, false);
    }
  }
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
