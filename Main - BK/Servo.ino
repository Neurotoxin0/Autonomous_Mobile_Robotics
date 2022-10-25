void servo_init()
{
  servo.attach(Servo_Pin);
  Serial.print(servo.attached());
  servo_to_angle(50);
  servo_to_angle(130);
  servo_to_angle(90);
}

void servo_to_angle(int angle)  // params: angle: 0 < x < 180; 0 = left side
{ 
  servo.write(angle); 
  delay(500);
}

void servo_scaning_mode()
{
  for (int pos = 50; pos <= 130; pos += 20) 
  {
    servo.write(pos);
    //delay(15);
    fall_and_collision_detection();
    delay(15);
    
  }
  
  for (int pos = 130; pos >= 50; pos -= 20) 
  {
    servo.write(pos);
    //delay(15);
    fall_and_collision_detection();
    delay(15);
  }
}

void test_mode()
{
    servo.write(45);
    delay(15);
    fall_and_collision_detection();
    delay(15);

    servo.write(90);
    delay(15);
    fall_and_collision_detection();
    delay(15);

    servo.write(135);
    delay(15);
    fall_and_collision_detection();
    delay(15);

    servo.write(90);
    delay(15);
    fall_and_collision_detection();
    delay(15);
}

//angle = servo.read();
