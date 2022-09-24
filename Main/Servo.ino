void servo_init()
{
  Serial.print(servo.attached());
  servo.write(90); // to central

  for (Servo_Position = 0; Servo_Position <= 180; Servo_Position += 1) 
  {
    servo.write(Servo_Position);
    Servo_Angle = servo.read();
    Serial.print("Servo Angle: ");
    Serial.print(Servo_Angle);
    Serial.print("\n");
    delay(15);
  }
  
  for (Servo_Position = 180; Servo_Position >= 0; Servo_Position -= 1) 
  {
    servo.write(Servo_Position);
    Servo_Angle = servo.read();
    Serial.print("Servo Angle: ");
    Serial.print(Servo_Angle);
    Serial.print("\n");
    delay(15);
  }
}
