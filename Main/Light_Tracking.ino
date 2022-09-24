int left_light, right_light;

bool following_light() { return (digitalRead(Left_Light_Sensor) == 1) && (digitalRead(Right_Light_Sensor) == 1); }

void adjust_light_following()
{
  Serial.print("adjust_light_following()\n");
  
  left_light = digitalRead(Left_Light_Sensor);
  right_light = digitalRead(Right_Light_Sensor);
  
  if      ( (left_light == 1) && (right_light == 0) ) { left_turn(Slow_Turning_Speed, 100); }
  else if ( (left_light == 0) && (right_light == 1))  { right_turn(Slow_Turning_Speed, 100); }
  // completly off-track OR adjust (above) is complete
  else { stop_movement(); }
}
