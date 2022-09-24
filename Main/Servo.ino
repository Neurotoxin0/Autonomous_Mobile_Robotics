void servo_init()
{
  servo.attach(Servo_Pin);
  Serial.print(servo.attached());
  servo_to_angle(90); // to central
}

void servo_to_angle(int angle) 
{ 
  servo.write(angle); 
  delay(500);
}

void servo_scaning_mode()
{
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
