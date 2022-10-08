bool collision_detected()
{ 
  ultra_sonic_update_distance();
  return left_distance < Safety_Distance || right_distance < Safety_Distance; 
}

void avoid_object()
{
  move_back(200);
  delay(100);
  stop_movement();
  Serial.print("avoid_object()\n");
  
  ultra_sonic_update_distance();
  if ( left_distance < Safety_Distance && right_distance < Safety_Distance ) { random_turn(350); }
  else if ( left_distance < Safety_Distance )  { right_turn(Default_Turning_Speed, random(175,350)); }
  else if ( right_distance < Safety_Distance ) { left_turn(Default_Turning_Speed, random(175,350)); }
    
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
