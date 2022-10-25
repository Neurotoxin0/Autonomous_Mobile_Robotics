bool collision_detected()
{ 
  ultra_sonic_update_distance();
  return left_distance <= Safety_Distance || right_distance <= Safety_Distance; 
}

void avoid_object()
{
  move_back(Base_Speed, 200);
  ultra_sonic_update_distance();
  //Serial.print("avoid_object()\n");
  
  if ( left_distance <= Safety_Distance && right_distance <= Safety_Distance ) { random_turn(350);  }
  else if ( left_distance <= Safety_Distance )  
  { 
    move_back(Base_Speed, 200);
    right_turn(Default_Turning_Speed, random(175,350));
  }
  else if ( right_distance <= Safety_Distance ) 
  { 
    move_back(Base_Speed, 200);
    left_turn(Default_Turning_Speed, random(175,350)); }
  }
}
