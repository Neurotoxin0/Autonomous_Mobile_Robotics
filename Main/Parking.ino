
void parking()
{
  bool flag  = false;
  bool found_space = false;
  
  servo_to_angle(15);
  
  while (Mode == 2 && !found_space)
  {
    ultra_sonic_update_distance();
    if (Front_Distance >= 15 && !flag) flag = true;
    
    move_front(40 + 5 * Battery_Ratio, true);
    delay(100 + 25 * Battery_Ratio);
    stop_movement();
    
    front_update_signal();
    if (flag && (Front_Distance <= 15 || Outer_Left == 1 || Outer_Right == 1) )
    {
        stop_movement();
        found_space = true;
        
        if (Front_Distance <= 15 ) parking_process1(1);
        else if (Outer_Left == 1 || Outer_Right == 1) parking_process1(2);
    }
  }
}


// go forward / backward a bit, left turn 45 degree
void parking_process1(int mode)
{
  delay(500);// 方便观察

  if (mode == 1)  // go forward a bit
  {
    //move_front(50 + 5 * Battery_Ratio, true);
    //delay(200 + 100 * Battery_Ratio);
    //stop_movement();
  }
  else move_back(80, 250 + 25 * Battery_Ratio, false); // backward a bit
  
  delay(500); // 方便观察
  
  turn(0, 275 + 25 * Battery_Ratio, 120);
  parking_process2(mode);
}


// go backward until detect obj behind
void parking_process2(int mode)
{ 
  bool exit1 = false, exit2 = false;

  // backward -> into the space
  while (!exit1)  
  {
    back_update_signal();

    if (Back_Collision == 1 || Back_Right_Collision == 1) { stop_movement(); exit1 = true; }
    else { move_back(40 + 5 * Battery_Ratio, 0, false); }
  }

  // 回正
  turn(1, 225 + 5 * Battery_Ratio, 120);
  servo_to_angle(90);

  // forward -> to central of the space
  while (!exit2)  
  {
    if (mode == 1) // ultra sonic + IR
    {
      ultra_sonic_update_distance();
      front_update_signal();
    
      if (Front_Distance >= 10 + 2 * Battery_Ratio && Outer_Left == 0 && Outer_Right == 0) 
      {
         move_front(40 + 5 * Battery_Ratio - 1, true);
         delay(100 + 25 * Battery_Ratio);
         stop_movement();
      }
      else
      { 
        if (Outer_Left == 1 || Outer_Right == 1) move_back(80, 250 + 25 * Battery_Ratio, false);
        else  stop_movement();
        exit2 = true;
      }
    }
    else  // IR only
    {
       front_update_signal();
       
       if (Outer_Left == 0 && Outer_Right == 0) 
       {
          move_front(40 + 5 * Battery_Ratio - 1, true);
       }
      else
      { 
        move_back(80, 250 + 25 * Battery_Ratio, false);
        exit2 = true;
      }
    }
  }
  
  Mode = 3;
}
