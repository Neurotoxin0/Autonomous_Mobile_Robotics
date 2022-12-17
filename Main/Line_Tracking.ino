void lane_following()
{
    Timer1 = millis();
    Timer2 = millis();
    //Timer3 = millis();
    int stop_count = 0;

    while (Mode == 0)
    { 
      // Light detection
      light_detect();
      if (Mode != 0) { stop_movement(); return ; }
      
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

#define switch_lane_ratio 0
void switch_lane()
{
   bool flag = false;
   
   move_back(80, 250, false);
   
   while (true)
   {
    if (Lane == 0) 
    {
      // use left ultra sonic sensor
      left_ultra_sonic_update_distance();
      
      if (Left_Distance > Minimum_Distance)
      {
        turn(0, 200 + 50 * switch_lane_ratio, -1);
        left_ultra_sonic_update_distance();
        if (Left_Distance > Minimum_Distance)
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
        turn(1, 200 + 50 * switch_lane_ratio, -1);
        right_ultra_sonic_update_distance();
        if (Right_Distance > Minimum_Distance)
        {
          flag = true;
          Lane = 0;
        }
      }
    }
    
    while (flag)
    {
      bottom_update_signal();
      
      if (Central == 1 || Central_Right == 1 || Central_Right == 1) 
      {
        delay(50);
        stop_movement();
        return;
      }
      else move_front(47, false);
    }
  }
}
