void IRTest() {
  int irclock = 0;
  while (!stopbutton()) {
    if (irclock == 150) {
      LCD.clear();
      LCD.setCursor(0,0);
      irPrint("L", analogRead(IRFRONTLEFT),"R", analogRead(IRFRONTRIGHT),"S", analogRead(IRFRONT));
      LCD.setCursor(0,1);
      irPrint("L", analogRead(IRLEFT),"R", analogRead(IRRIGHT),"",0);  
      irclock = 0;
    }
    irclock++;
  }
  LCD.clear();
  LCD.setCursor(0,0);
  LCD.print("START to test, hold");
  LCD.setCursor(0,1);
  LCD.print("STOP&START to cont");
  while (!startbutton()) {
    // just chilling
  }
}

