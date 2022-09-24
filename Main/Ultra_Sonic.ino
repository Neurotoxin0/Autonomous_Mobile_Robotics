long ultra_sonic_get_distance() 
{ 
  long result = sr04.Distance();
  Serial.print("Distance: ");
  Serial.print(result);
  Serial.print("\n");
  return result; 
}
