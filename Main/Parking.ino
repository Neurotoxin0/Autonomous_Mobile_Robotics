void parking()
{
  bool flag  = false;
  bool found_space = false;
  
  servo_to_angle(15);
  move_front(60, true);
  
  while (Mode == 2 && !found_space)
  {
    //Base_Speed = 60;
    //delay(1000);
    //Base_Speed = 0;
    ultra_sonic_update_distance();

    /*
    Serial.print("\nflag: ");
    Serial.print(flag);
    Serial.print(" found: ");
    Serial.print(found_space);
    Serial.print(" distance: ");
    Serial.print(Front_Distance);
    */

    if (Front_Distance >= 15 && !flag)
    {
      flag = true;
    }

    if (flag && Front_Distance <= 15 )
    {
      stop_movement();
      found_space = true;
      
      parking_process1();
    }
  }
}

// go forward a bit, left turn 45 degree
void parking_process1()
{
  delay(500);// 方便观察
  move_front(60, true);
  delay(500);
  stop_movement();
  delay(500); // 方便观察
  turn(0,400,120);
  parking_process2();
}

// go backward until detect obj behind
void parking_process2()
{ 
  bool exit1 = false, exit2 = false;
  
  while (!exit1)
  {
    back_update_signal();

    if (Back_Collision == 1 || Back_Right_Collision == 1) { stop_movement(); exit1 = true; }
    else { move_back(47, 0, false); }
  }
  
  turn(1,300,120);
  servo_to_angle(90);
  
  while (!exit2)
  {
    ultra_sonic_update_distance();
    if (Front_Distance >= 10) 
    {
       move_front(50, true);
       delay(150);
       stop_movement();
    }
    else { stop_movement(); exit2 = true; }
  }
  
  Mode = 3;
}
