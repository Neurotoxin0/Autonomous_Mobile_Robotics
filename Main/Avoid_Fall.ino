
int front_fall_detection()
{
  return digitalRead(Front_left_sensor) && digitalRead(Front_middle_snsor) && digitalRead(Front_right_snsor);
}
