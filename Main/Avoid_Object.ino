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
  Serial.print("avoid_object()\n");
  ultra_sonic_update_distance();

  /*
  function turn(direction, time) usage: 
    @direction:
      -1: random direction
      0: left
      1: right
    @time:
      -1：random degree
      0: continous turning
      int: turning time
  */
  
  if ( central_distance <= Safety_Distance )    { turn(-1, 350, false); }
  else if ( left_distance <= Safety_Distance )  { move_back(Base_Speed, 200); turn(1, -1, false); }
  else if ( right_distance <= Safety_Distance ) { move_back(Base_Speed, 200); turn(0, -1, false); }
}
