void motor_speed_adjust()
{
  move_front(Base_Speed);
  Serial.print("\nBase Speed: ");
  Serial.print(Base_Speed);
  Serial.print("\n");
  
  while (digitalRead(Back_Central_Edge_Sensor) == 1 && Base_Speed < 250)
  {
    Base_Speed += 5;
    Serial.print("Adjust Base Speed to: ");
    Serial.print(Base_Speed);
    Serial.print("\n");
    move_front(Base_Speed);
    delay(500);
  }
  
  Base_Speed += 2;
  Serial.print("FINAL Base Speed: ");
  Serial.print(Base_Speed);
  Serial.print("\n");
}
