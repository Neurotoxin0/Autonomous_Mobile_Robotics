int left_line, right_line;

bool following_line() { return digitalRead(Central_Line_Sensor) == 1; }

void adjust_line_tracking()
{
  Serial.print("adjust_line_tracking()\n");
  
  left_line = digitalRead(Left_Line_Sensor);
  right_line = digitalRead(Right_Line_Sensor);
  
  if      ( (left_line == 1) && (right_line == 0) ) { left_turn(Slow_Turning_Speed, 100); }
  else if ( (left_line == 0) && (right_line == 1))  { right_turn(Slow_Turning_Speed, 100); }
  // completly off-track OR adjust (above) is complete
  else { stop_movement(); }
}
