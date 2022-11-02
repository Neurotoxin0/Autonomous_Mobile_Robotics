bool collision_detected()
{ 
  ultra_sonic_update_distance();
  return central_distance <= Safety_Distance || left_distance <= Safety_Distance || right_distance <= Safety_Distance; 
}

void avoid_object()
{
  move_back(Base_Speed, 200);
  Serial.print("avoid_object()\n");
  ultra_sonic_update_distance();
  
  if ( central_distance <= Safety_Distance ) { random_turn(350); }
  else if ( left_distance <= Safety_Distance )  
  { 
    move_back(Base_Speed, 200);
    right_turn(Default_Turning_Speed, random(175,350));
  }
  else if ( right_distance <= Safety_Distance ) 
  { 
    move_back(Base_Speed, 200);
    left_turn(Default_Turning_Speed, random(175,350));
  }
}
