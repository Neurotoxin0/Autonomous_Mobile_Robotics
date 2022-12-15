bool light_flag = false;

void light_detect()
{
  light_update_signal();
  
  if (Left_Light == 0 && !light_flag) 
  {
    light_flag = true;
  }

  if (light_flag && Left_Light == 1)
  {
    Mode = 1;
  }
}

void light_following()
{
  if (Lane == 0)
  {
    move_front(60, false);
    delay(850 + 500 * Battery_Ratio);
  }
  else
  {
    bool exit1 = false;
    Timer1 = millis();

    while (!exit1)
    {
      // Line Following
      line_update_signal();
      
      if (Central == 1) { move_front(Base_Speed, false); }
      else
      {
         if (Outer_Left == 1 || Central_Left == 1)
         {
          left_turn(Default_Turning_Speed, 0);
         }
         else if (Outer_Right == 1 || Central_Right == 1)
         {
          right_turn(Default_Turning_Speed, 0);
         }     
      }
      if ((millis() - Timer1) >= 2200 + 500 * Battery_Ratio)
      {
        exit1 = true;
        break;
      }  
    }      
  }
  
  stop_movement();
  turn(0, 750 + 100 * Battery_Ratio, 120);
  exit(0);
  //Mode = 2;

}

/*
 * follow the light
void light_following()
{
  light_update_signal();
  
  if (Left_Light == 1 && Right_Light == 0)
  {
    turn(1,0,120);
  }
  else if (Left_Light == 0 && Right_Light == 1)
  {
   turn(0,0,120);
  }
  else
  {
    adjust_speed();
    move_front(Base_Speed, false);
  }
}
*/
