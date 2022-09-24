
int front_fall_detection()
{
  return digitalRead(Front_Left_Sensor) || digitalRead(Front_Middle_Sensor) || digitalRead(Front_Right_Sensor);
}
