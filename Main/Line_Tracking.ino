int Central, Central_Left, Central_Right, Outer_Left, Outer_Right;
bool exit_function = false;
bool on_track()   { return digitalRead(Central_Line_Sensor) && digitalRead(Central_Left_Line_Sensor) && digitalRead(Central_Right_Line_Sensor); }
bool found_line() { return digitalRead(Central_Line_Sensor) || digitalRead(Central_Left_Line_Sensor) || digitalRead(Central_Right_Line_Sensor); }
bool on_the_line(){ return digitalRead(Central_Line_Sensor) || digitalRead(Central_Left_Line_Sensor) || digitalRead(Central_Right_Line_Sensor) || digitalRead(Left_Line_Sensor) || digitalRead(Right_Line_Sensor); };


void line_following()
{
    timer1 = millis();
    //timer2 = millis();

    while (!exit_function)
    { 
      if ((millis() - timer1) >= 1200)
      {
        stop_movement();
        ultra_sonic_update_distance();

        if (central_distance <= Safety_Distance)
        {
          if (central_distance > Minimum_Distance)
          {
            Base_Speed = 57;
            //Serial.print("Slow Down\n");
          }
          else
          {
            Base_Speed = 0;
            //Serial.print("Stop\n");
          }
        }
        else if (central_distance <= 1000)
        {
          Base_Speed = 67;
          //Serial.print("Normal\n");
        }
        
        timer1 = millis();
        move_front(Base_Speed);
      }

      /*
      if ((millis() - timer3) >= 1000)
      {
        exit_function = true;
        ...
      }
      */
      
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
          //move_back(Default_Turning_Speed, 30); 
          //turn(1, 45, -1);
          
          /*
          Serial.print("CL: ");
          Serial.print(Central_Left);
          Serial.print(" CC: ");
          Serial.print(Central);
          Serial.print("CR: ");
          Serial.print(Central_Right);
          Serial.print("L: ");
          Serial.print(Outer_Left);
          Serial.print("R: ");
          Serial.print(Outer_Right);
          Serial.print("\n");
          */
        }
      }
    }
}

void switch_lane()
{
  if (lane == 0)  // inner
  {
    turn(0, 175, -1);
    lane = 1;
  }
  else if (lane == 1) // outter
  {
    turn(1, 175, -1);
    lane = 0;
  }
   
   move_front(Base_Speed);
   delay(150);
}
