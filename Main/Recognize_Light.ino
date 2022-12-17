bool light_flag = false;
void light_detect()
{
  light_update_signal();
  
  if (Left_Light == 0 && !light_flag) 
  {
    light_flag = true;
    Timer3 = millis();
  }
  else if (Left_Light == 1) 
  {
    light_flag = false;
  }
  if (light_flag) 
  {
    if (millis() - Timer3 >= 200) 
    {
      // 即将切换模式前转到外道，配合pre-parking
      if (Lane == 0) 
      {
        switch_lane();
      }
      
      Mode = 1;
    }
  }
}

#define pre_parking_ratio 0
void pre_parking()
{
  bool exit1 = false;

  while (!exit1)
  {
    // Line Following
    line_update_signal();
    light_update_signal();
    
    if (Outer_Right == 1) 
    { 
      if (Left_Light == 1) 
      {
        exit1 = true;
        break;
      }
      else 
      {
        right_turn(Default_Turning_Speed, 0);
      }
    }  // exit case
    // simple line following below
    else if (Central == 1) { move_front(Base_Speed, false); }
    else
    {
       if (Outer_Left == 1 || Central_Left == 1) left_turn(Default_Turning_Speed, 0);
       else if (Central_Right == 1) right_turn(Default_Turning_Speed, 0);
    }
  }      

  stop_movement();

  //move_front(55, false);
  //delay(50);
  //move_back(55, 150 + 50 * pre_parking_ratio ,false);
  turn(0,400 + 50 * pre_parking_ratio, 150);
  Mode = 2;
}

/*
void pre_parking_old()
{ 
  bool flag1 = false, flag2 = false;

  //Serial.print("preparking\n");
  //Serial.print(flag1);
  //Serial.print(flag2);
  //Serial.print("\n");
  
  while (Mode == 1)
  {
    if (flag1 && !flag2)
    {
       //Serial.print("first if\n");
      if ((millis() - Timer1) >= 2000) 
      { 
        //Serial.print("u turn\n");
        u_turn(); 
        delay(1000);
        flag2 = true;
      }
    }
    
     //必定在内道 -> detect_light() 退出前切换了
     右转弯后延迟2秒，U turn；在想要左转时放弃，直行进入停车位
     
    // altered line_following()
    line_update_signal();
        
    if (Central == 1) { move_front(Base_Speed, false); }
    if (Outer_Left == 1 && Outer_Right == 0)
    {
      if (!flag2) left_turn(Default_Turning_Speed, 0);
      else
      {
        //Serial.print("flag2 act\n");
        move_front(60, false);
        delay(1000);
        stop_movement();
        exit(0);
        //Mode = 2;
        //return ;
      }
    }
    else if (Outer_Left == 0 && Outer_Right == 1) 
    {
      //Serial.print("right turn\n");
      right_turn(Default_Turning_Speed, 0);
      
      if (!flag1) 
      { 
        Timer1 = millis(); flag1 = true; 
        Serial.print("ouuter right\n");
      } 
    }
    else if (Central_Left == 1 && Central_Right == 0)
    {
      left_turn(Default_Turning_Speed, 0);
    }
    else if (Central_Left == 0 && Central_Right == 1)
    {
      right_turn(Default_Turning_Speed, 0);
    }
    
  }  
}
*/
