int left_line, right_line;

bool following_line() { return digitalRead(Left_Line_Sensor) == 0 && digitalRead(Central_Line_Sensor) == 0 && digitalRead(Right_Line_Sensor) == 0; }

void adjust_line_tracking()
{
  //Serial.print("adjust_line_tracking()\n");

  left_line = digitalRead(Left_Line_Sensor);
  right_line = digitalRead(Right_Line_Sensor);
    
  while ( left_line == 1 && right_line == 1 ) 
  { 
    random_turn(100);
  }
  while ( left_line == 1 && right_line == 0 ) 
  { 
    right_turn(Slow_Turning_Speed, 100); 
  }
  
  while ( left_line == 0 && right_line == 1 ) 
  { 
    left_turn(Slow_Turning_Speed, 100); 
  }
}
