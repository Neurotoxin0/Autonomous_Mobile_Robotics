int angle;
//long left_distance, right_distance;

bool collision_detected() { return ultra_sonic_get_distance(0) < 20; } // ultra_sonic_get_distance(0) > 1180: case happen when distance == 0

void avoid_object()
{
  move_back(200);
  delay(100);
  stop_movement();
  Serial.print("avoid_object()\n");
  
  angle = servo.read();
  if ( angle >= 75 && angle <= 90 ) { random_turn(350); }
  else if ( angle > 45 && angle < 75 ) { left_turn(Default_Turning_Speed, random(175,350)); }
  else if ( angle > 90 && angle < 135 ) { right_turn(Default_Turning_Speed, random(175,350)); }
    
  /* 
  // Measure left side distance
  servo_to_angle(180);
  left_distance = ultra_sonic_get_distance(0);
    
  // Measure right side distance
  servo_to_angle(0);  // turn to right
  right_distance = ultra_sonic_get_distance(0);
    
  if (left_distance > right_distance) { left_turn(Default_Turning_Speed, 175); }
  else                                { right_turn(Default_Turning_Speed, 175); }
    
  servo_to_angle(90);
  */
}
