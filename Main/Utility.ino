// Motor
void adjust_speed() // based on distance obtained by front ultra sonic
{
  ultra_sonic_update_distance();

  if (Front_Distance <= Safety_Distance)
  {
    if (Front_Distance > Minimum_Distance)  // slow speed
    {
      Base_Speed = 45;
      //Serial.print("Slow Down\n");
    }
    else                                      // stop
    {
      Base_Speed = 0;
      //Serial.print("Stop\n");
    }
  }
  else if (Front_Distance <= 1000)          // normal speed
  {
    Base_Speed = 60;
    //Serial.print("Normal\n"); 
  }
}

// Servo
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


// Ultra Sonic
void ultra_sonic_update_distance()  // if distance > 1180 -> either to far OR too close(~0)
{ 
  Front_Distance = central_sr04.Distance();
}


// IR Sensor
void line_update_signal()
{
  Central       = digitalRead(Central_Line_Sensor);
  Central_Left  = digitalRead(Central_Left_Line_Sensor);
  Central_Right = digitalRead(Central_Right_Line_Sensor);
  Outer_Left    = digitalRead(Left_Line_Sensor);
  Outer_Right   = digitalRead(Right_Line_Sensor);
}

void back_update_signal()
{
  Back_Collision = digitalRead(Back_IR_Sensor);
  Back_Right_Collision = digitalRead(Back_Right_IR_Sensor);
}


// Light Sensor
void light_update_signal()
{
  Left_Light = digitalRead(Left_Light_Sensor);
  Right_Light = digitalRead(Right_Light_Sensor);
}
