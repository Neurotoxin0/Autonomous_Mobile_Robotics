void light_following()
{
  light_update_signal();
  
  if (Left_Light == 1 && Right_Light == 0)
  {
    turn(1,0,120);
  }
  else if (Left_Light == 0 && Right_Light == 1)
  {
   turn(0,0,120);
  }
  else
  {
    adjust_speed();
    move_front(Base_Speed);
  }
}
