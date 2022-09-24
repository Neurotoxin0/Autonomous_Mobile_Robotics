long Ultrasonic_Central_Distance, Ultrasonic_Left_Distance, Ultrasonic_Right_Distance;

bool collision_detected() { return ultra_sonic_get_distance() < 10; }

void avoid_object()
{
  Ultrasonic_Central_Distance = ultra_sonic_get_distance();
  
  if (Ultrasonic_Central_Distance < 10)
  {
    move_back(200);
    delay(100);
    stop_movement();
    
    // Measure left side distance
    servo_to_angle(180);
    Ultrasonic_Left_Distance = ultra_sonic_get_distance();
    
    // Measure right side distance
    servo_to_angle(0);  // turn to right
    Ultrasonic_Right_Distance = ultra_sonic_get_distance();
    
    if (Ultrasonic_Left_Distance > Ultrasonic_Right_Distance) { left_turn(Default_Turning_Speed, 350); }
    else                                                      { right_turn(Default_Turning_Speed, 350); }
    
    servo_to_angle(90);
  }
}
