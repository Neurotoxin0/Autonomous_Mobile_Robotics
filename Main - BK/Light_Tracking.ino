int left_light, right_light;

bool following_light() { return (digitalRead(Left_Light_Sensor) == 0) && (digitalRead(Right_Light_Sensor) == 0); }

bool adjust_light_following()
{
  Serial.print("adjust_light_following()\n");
  
  while (not following_light())
  {
    left_light = digitalRead(Left_Light_Sensor);
    right_light = digitalRead(Right_Light_Sensor);
  
    if (following_light())  // exit case
    {
      stop_movement(); 
      Serial.print("Adjusted\n"); 
      return 1;
    }
    else if ( left_light == 1 && right_light == 0 ) { left_turn(Slow_Turning_Speed, 100); }
    else if ( left_light == 0 && right_light == 1 ) { right_turn(Slow_Turning_Speed, 100); }
    else  // random tries
    { 
      random_turn(300);
    }
  }
  return 0;
}
