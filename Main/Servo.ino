void servo_init()
{
  servo.attach(Servo_Pin);
  Serial.print(servo.attached());
  servo_to_angle(45);
  servo_to_angle(135);
  servo_to_angle(90);
}

void servo_to_angle(int angle)  // params: angle: 0 < x < 180; 0 = left side
{ 
  servo.write(angle); 
  delay(500);
}

void servo_scaning_mode()
{
  for (int pos = 45; pos <= 135; pos += 45) 
  {
    servo.write(pos);
    //delay(15);
    fall_and_collision_detection();
    delay(15);
    
  }
  
  for (int pos = 135; pos >= 45; pos -= 45) 
  {
    servo.write(pos);
    //delay(15);
    fall_and_collision_detection();
    delay(15);
  }
}

void test_mode()  // use key points
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
