int fall_detection()
{
  if (front_central_fall_detection()) return 2;
  //else if (digitalRead(Front_Left_Sensor)) return 1;
  //else if (digitalRead(Front_Right_Sensor)) return 3;
  //else if (digitalRead(Back_Left_Sensor)) return 4;
  //else if (digitalRead(Back_Right_Sensor)) return 5;
  return 0;
}

bool front_central_fall_detection() { return digitalRead(Front_Central_Left_Sensor) || digitalRead(Front_Central_Middle_Sensor) || digitalRead(Front_Central_Right_Sensor); }
