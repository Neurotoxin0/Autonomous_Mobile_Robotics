void ultra_sonic_update_distance()  // if distance > 1180 -> either to far OR too close(~0)
{ 
  central_distance = central_sr04.Distance();
  
  /*
  Serial.print("Left Distance: ");
  Serial.print(left_distance);
  Serial.print("\tCentral Distance: ");
  Serial.print(central_distance);
  Serial.print("\tRight Distance: ");
  Serial.print(right_distance);
  Serial.print("\n");
  */
}
