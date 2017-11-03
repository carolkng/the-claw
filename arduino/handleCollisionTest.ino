void handleCollisionTest() {
  int colllideClock = 0;
  motor.stop_all();
  LCD.clear();
  LCD.setCursor(0,0);
  LCD.print("Collided!");
  LCD.setCursor(0,0);
  LCD.print("Collided!");
  while(!startbutton()) {
    //just chilling
  }
}

