int left_line, right_line;

bool following_line() { return digitalRead(Central_Line_Sensor) == 0; }

bool adjust_line_tracking()
{
  Serial.print("adjust_line_tracking()\n");
  tries = 0;

  while ( not following_line() && tries < 150 )
  {
    left_line = digitalRead(Left_Line_Sensor);
    right_line = digitalRead(Right_Line_Sensor);
    tries++;
    Serial.print("tries: ");
    Serial.print(tries);
    Serial.print("\n");
    
    if (following_line())  // exit case
    {
      stop_movement();
      Serial.print("Adjusted\n"); 
      return 1;
    }
    else if ( left_line == 1 && right_line == 0 ) { left_turn(Slow_Turning_Speed, 100); }
    else if ( left_line == 0 && right_line == 1 ) { right_turn(Slow_Turning_Speed, 100); }
    else  // random tries
    { 
      left_turn(Slow_Turning_Speed, 100);
    }
  }
  return 0;
}
