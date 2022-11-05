bool found_line() { return digitalRead(Left_Line_Sensor) || digitalRead(Right_Line_Sensor) || on_track(); }
bool end_of_line() { return not digitalRead(Left_Line_Sensor) && not digitalRead(Right_Line_Sensor) && not on_track(); }
bool on_track() { return digitalRead(Central_Line_Sensor) == 1 || digitalRead(Central_Left_Line_Sensor) == 1 || digitalRead(Central_Right_Line_Sensor) == 1; }
//bool all_central_line_sensor()      { return digitalRead(Central_Line_Sensor) == 1 && digitalRead(Central_Left_Line_Sensor) == 1 && digitalRead(Central_Right_Line_Sensor) == 1; }

void adjust_line_tracking()
{
  Serial.print("adjust_line_tracking()\n");

  // Central Sensors
  if ( digitalRead(Central_Left_Line_Sensor) == 0 && digitalRead(Central_Right_Line_Sensor) == 1 ) 
  { 
    right_turn(Slow_Turning_Speed, 100, true); 
    // TODO: move front a bit until detect a line
  }
  
  if ( digitalRead(Central_Left_Line_Sensor) == 1 && digitalRead(Central_Right_Line_Sensor) == 0 ) 
  { 
    left_turn(Slow_Turning_Speed, 100, true); 
    // TODO: move front a bit until detect a line
  }
  
  // Outer Sensors
  if ( digitalRead(Left_Line_Sensor) == 0 && digitalRead(Right_Line_Sensor) == 1 ) 
  { 
    right_turn(Slow_Turning_Speed, 350, true); 
  }
  
  if ( digitalRead(Left_Line_Sensor) == 1 && digitalRead(Right_Line_Sensor) == 0 ) 
  { 
    left_turn(Slow_Turning_Speed, 350, true); 
  }
}
