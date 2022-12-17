bool light_flag1 = false, light_flag2 = false;

void light_detect()
{
  light_update_signal();

  if (Left_Light == 0)
  {
    if (!light_flag1) 
    {
      light_flag1 = true;
      Timer3 = millis();
    }
    if (light_flag1 && millis() - Timer3 >= 300) light_flag2 = true;
    if (light_flag2 && Left_Light == 1) Mode = 1;
  }
  else light_flag1 = false;
}

void light_following()
{ 
  bool exit1 = false;

    while (!exit1)
    {
      // Line Following
      line_update_signal();
      
      if (Outer_Right == 1) { exit1 = true; break; }
      // simple line following below
      else if (Central == 1) { move_front(Base_Speed, false); }
      else
      {
         if (Outer_Left == 1 || Central_Left == 1) left_turn(Default_Turning_Speed, 0);
         else if (Outer_Right == 1 || Central_Right == 1) right_turn(Default_Turning_Speed, 0);
      }
    }      

  stop_movement();
  
  if (Lane == 0)
  {
    move_front(55, false);
    delay(1000);
    stop_movement();
  }
  else
  {
    move_back(55, 125, false);
  }
  
  turn(0, 800 + 200 * Battery_Ratio, 120);
  Mode = 2;

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
