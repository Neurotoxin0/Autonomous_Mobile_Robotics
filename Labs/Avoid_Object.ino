bool collision_detected()
{ 
  ultra_sonic_update_distance();
  return central_distance <= Safety_Distance || left_distance <= Safety_Distance || right_distance <= Safety_Distance; 
}
bool front_collision_detected()
{
  ultra_sonic_update_distance();
  return central_distance <= Safety_Distance; 
}

void avoid_object()
{
  move_back(Base_Speed, 200);
  //Serial.print("avoid_object()\n");
  ultra_sonic_update_distance();

  if ( central_distance <= Safety_Distance )    { turn(-1, 350, -1); }
  else if ( left_distance <= Safety_Distance )  { move_back(Base_Speed, 200); turn(1, -1, -1); }
  else if ( right_distance <= Safety_Distance ) { move_back(Base_Speed, 200); turn(0, -1, -1); }
}
