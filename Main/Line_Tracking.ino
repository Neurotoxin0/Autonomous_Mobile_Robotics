int left_line, right_line;

bool following_line()       { return digitalRead(Left_Line_Sensor) == 1 && digitalRead(Right_Line_Sensor) == 1 && central_line_sensor(); }
bool central_line_sensor()  { return digitalRead(Central_Line_Sensor) == 0 || digitalRead(Central_Left_Line_Sensor) == 0 || digitalRead(Central_Right_Line_Sensor) == 0; }

void adjust_line_tracking()
{
  //Serial.print("adjust_line_tracking()\n");

  // Central Sensors
  if ( digitalRead(Central_Left_Line_Sensor) == 0 && digitalRead(Central_Right_Line_Sensor) == 1 ) 
  { 
    left_turn(Slow_Turning_Speed, 100); 
  }
  
  if ( digitalRead(Central_Left_Line_Sensor) == 1 && digitalRead(Central_Right_Line_Sensor) == 0 ) 
  { 
    right_turn(Slow_Turning_Speed, 100); 
  }
  
  // Outer Sensors
  if ( digitalRead(Left_Line_Sensor) == 0 && digitalRead(Right_Line_Sensor) == 1 ) 
  { 
    right_turn(Slow_Turning_Speed, 350); 
  }
  
  if ( digitalRead(Left_Line_Sensor) == 1 && digitalRead(Right_Line_Sensor) == 0 ) 
  { 
    left_turn(Slow_Turning_Speed, 350); 
  }
}
