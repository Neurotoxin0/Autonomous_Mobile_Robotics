void motor_speed_adjust()
{
  move_front(Base_Speed);
  Serial.print("\nBase Speed: ");
  Serial.print(Base_Speed);
  Serial.print("\n");
  
  while (digitalRead(Back_Left_Edge_Sensor) && digitalRead(Back_Right_Edge_Sensor) && Base_Speed < 120)
  {
    Base_Speed += 5;
    Serial.print("Adjust Base Speed to: ");
    Serial.print(Base_Speed);
    Serial.print("\n");
    move_front(Base_Speed);
    delay(800);
  }
  
  Base_Speed += 2;
  Serial.print("FINAL Base Speed: ");
  Serial.print(Base_Speed);
  Serial.print("\n");
}
