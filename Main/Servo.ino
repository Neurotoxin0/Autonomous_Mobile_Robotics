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
  for (int pos = 45; pos <= 135; pos += 3) 
  {
    servo.write(pos);
    fall_and_collision_detection();
    delay(15);
  }
  
  for (int pos = 135; pos >= 45; pos -= 3) 
  {
    servo.write(pos);
    fall_and_collision_detection();
    delay(15);
  }
}
