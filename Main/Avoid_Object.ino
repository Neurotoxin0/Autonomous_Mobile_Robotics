/*long distance,a1,a2;

void avoid()
{
  distance=sr04.Distance(); //obtain the value detected by ultrasonic sensor 
  
  if((distance < 20)&&(distance > 0))//if the distance is greater than 0 and less than 20  
  {
    stop_movement();//stop
    delay(100);
    
    servopulse(Servo_Pin,180);//servo rotates to 180°
    delay(500);
    a1=sr04.Distance();//measure the distance
    delay(100);
    
    servopulse(Servo_Pin,0);//rotate to 0 degree
    delay(500);
    a2=sr04.Distance();//measure the distance
    delay(100);
    
    if(a1 > a2) //if distance a1 is greater than a2
    {
      left_turn(350);//turn left
      servopulse(Servo_Pin,90);//servo rotates to 90 degree
      delay(300); 
    }
    else  //if the right distance is greater than the left
    {
      right_turn(350);// turn right
      servopulse(Servo_Pin,90);// servo rotates to 90 degree
      delay(300); 
    }
  }
  else//otherwise
  {
    move_front(100);//go forward
  }
}

void servopulse(int Servo_Pin,int myangle) //the running angle of servo
{
  for(int i=0; i<30; i++)
  {
    int pulsewidth = (myangle*11)+500;
    digitalWrite(Servo_Pin,HIGH);
    delayMicroseconds(pulsewidth);
    digitalWrite(Servo_Pin,LOW);
    delay(20-pulsewidth/1000);
  }  
}*/
