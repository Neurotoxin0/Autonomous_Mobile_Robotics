long ultra_sonic_get_distance(bool debug) 
{ 
  if (debug)
  {
    long result = sr04.Distance();
    Serial.print("Distance: ");
    Serial.print(result);
    Serial.print("\n");
    return result; 
  }
  else { return sr04.Distance(); }
}
