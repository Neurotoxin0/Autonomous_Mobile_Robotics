bool found_line() { return digitalRead(Left_Line_Sensor) || digitalRead(Right_Line_Sensor) || partial_central_line_sensor(); }
bool end_of_line() { return digitalRead(Left_Line_Sensor) == 0 && digitalRead(Right_Line_Sensor) == 0 && not partial_central_line_sensor(); }
bool on_track() { return digitalRead(Left_Line_Sensor) == 0 && digitalRead(Right_Line_Sensor) == 0 && partial_central_line_sensor(); }
bool partial_central_line_sensor()  { return digitalRead(Central_Line_Sensor) == 1 || digitalRead(Central_Left_Line_Sensor) == 1 || digitalRead(Central_Right_Line_Sensor) == 1; }
bool all_central_line_sensor()      { return digitalRead(Central_Line_Sensor) == 1 && digitalRead(Central_Left_Line_Sensor) == 1 && digitalRead(Central_Right_Line_Sensor) == 1; }

void adjust_line_tracking()
{
  Serial.print("adjust_line_tracking()\n");

  // Central Sensors
  if ( digitalRead(Central_Left_Line_Sensor) == 0 && digitalRead(Central_Right_Line_Sensor) == 1 ) 
  { 
    right_turn(Slow_Turning_Speed, 100, true); 
  }
  
  if ( digitalRead(Central_Left_Line_Sensor) == 1 && digitalRead(Central_Right_Line_Sensor) == 0 ) 
  { 
    left_turn(Slow_Turning_Speed, 100, true); 
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
