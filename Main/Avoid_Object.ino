void avoid_object()
{
  servo_to_angle(90);
  Ultrasonic_Central_Distance = ultra_sonic_get_distance();
  
  if ( (Ultrasonic_Central_Distance > 0) && (Ultrasonic_Central_Distance < 20) )
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
    
    if (Ultrasonic_Left_Distance > Ultrasonic_Right_Distance) { left_turn(Turning_Speed, 350); }
    else                                                      { right_turn(Turning_Speed, 350); }
    
    servo_to_angle(90);
  }
}
