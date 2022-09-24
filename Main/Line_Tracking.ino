int left_line, right_line;
const int Slow_Turning_Speed = 80;

bool on_track() { return digitalRead(Front_Central_Middle_Sensor) == 1; }

void back_on_track()
{
  left_line = digitalRead(Front_Central_Left_Sensor);
  right_line = digitalRead(Front_Central_Right_Sensor);
  
  if( (left_line == 1) && (right_line == 0) ){ left_turn(Slow_Turning_Speed, 100); }
  else if( (left_line == 0) && (right_line == 1)) { right_turn(Slow_Turning_Speed, 100); }
  // completly off-track OR adjust (above) is complete
  else { stop_movement(); }
}
