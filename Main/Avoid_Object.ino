bool collision_detected()
{ 
  ultra_sonic_update_distance();
  return central_distance <= Minimum_Distance; 
}


void avoid_object()
{
  move_back(Base_Speed, 200);
  //Serial.print("avoid_object()\n");
  ultra_sonic_update_distance();

  if ( central_distance <= Safety_Distance )    { turn(-1, 350, -1); }
}
