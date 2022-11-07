int l_val,c_val,r_val;//define these variables

void tracking()
{
  l_val = digitalRead(Central_Left_Line_Sensor);//read the value of left line tracking sensor
  c_val = digitalRead(Central_Line_Sensor);//read the value of middle line tracking sensor
  r_val = digitalRead(Central_Right_Line_Sensor);//read the value of right line tracking sensor
  
  if(c_val == 1)//if the state of middle one is 1, which means detecting black line
  {
    move_front(Base_Speed);
  }
  else
  {
    if((l_val == 1)&&(r_val == 0))//if only left line tracking sensor detects black trace
    {
      turn(0,0,true);
    }
else if((l_val == 0)&&(r_val == 1))//if only right line tracking sensor detects black trace
    {
      turn(1,0,true);
    }
    else// if left and right line tracking sensors detect black trace or they don’t read
    {
      stop_movement();//car stops
    }
  }
}
