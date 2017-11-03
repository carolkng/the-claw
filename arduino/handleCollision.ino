void handleCollision() {
  int temp;
  motor.stop_all();
  LCD.clear();
  LCD.setCursor(0,0);
  LCD.print("collided");
  LCD.setCursor(0,1);
  for (int switchi = 0; switchi < 5; switchi++) {
    if (digitalRead(switchi)) {
      LCD.print(switchi);
      LCD.print(" ");
    }
  }
  LCD.print("Press START to cont.");
  while(!startbutton()) {
    // just chilling
  }
  temp = lastNode;
  lastNode = nextNode;
  nextNode = temp;
  
  if (nextNode != 18) {
    motor.speed(LMOTOR, -250);
    motor.speed(RMOTOR, 200);
  }
  return;
}  
