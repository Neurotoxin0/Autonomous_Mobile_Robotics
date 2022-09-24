long left_distance, right_distance;

bool collision_detected() { return ultra_sonic_get_distance() < 10; }

void avoid_object()
{
  move_back(200);
  delay(100);
  stop_movement();
    
  // Measure left side distance
  servo_to_angle(180);
  left_distance = ultra_sonic_get_distance();
    
  // Measure right side distance
  servo_to_angle(0);  // turn to right
  right_distance = ultra_sonic_get_distance();
    
  if (left_distance > right_distance) { left_turn(Default_Turning_Speed, 350); }
  else                                { right_turn(Default_Turning_Speed, 350); }
    
  servo_to_angle(90);
}
