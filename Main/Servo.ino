int angle;

void servo_init()
{
  servo.attach(Servo_Pin);
  Serial.print(servo.attached());
  servo_to_angle(0);
  servo_to_angle(180);
  servo_to_angle(90);
}

void servo_to_angle(int angle)  // params: angle: 0 < x < 180; 0 = left side
{ 
  servo.write(angle); 
  delay(500);
}

void servo_scaning_mode()
{
  for (int pos = 0; pos <= 180; pos += 1) 
  {
    servo.write(pos);
    angle = servo.read();
    Serial.print("Servo Angle: ");
    Serial.print(angle);
    Serial.print("\n");
    delay(15);
  }
  
  for (int pos = 180; pos >= 0; pos -= 1) 
  {
    servo.write(pos);
    angle = servo.read();
    Serial.print("Servo Angle: ");
    Serial.print(angle);
    Serial.print("\n");
    delay(15);
  }
}
