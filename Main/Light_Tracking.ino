int left_light, right_light;

bool following_light() { return (digitalRead(Left_Light_Sensor) == 0) && (digitalRead(Right_Light_Sensor) == 0); }

bool adjust_light_following()
{
  Serial.print("adjust_light_following()\n");
  tries = 0;
  
  while ( not following_light() && tries < 50 )
  {
    left_light = digitalRead(Left_Light_Sensor);
    right_light = digitalRead(Right_Light_Sensor);
    tries ++;
    Serial.print("tries: ");
    Serial.print(tries);
    Serial.print("\n");
  
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
      
    }
  }
  return 0;
}
