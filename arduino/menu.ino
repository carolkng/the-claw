void motorMenu(int okp, int okd) {
  int value1 = knob(6);
  int value2 = knob(7);
  int count = 0;
  int speeds[4] = {50, 100, 125, 150};
  
  while ( ! (startbutton()) ){
    value1 = knob(6);
    value2 = knob(7);
    LCD.clear();
    LCD.setCursor(0, 0);
    LCD.print("P:");
    LCD.print(value1);
    LCD.print(" oP:");
    LCD.print(okp);
    LCD.setCursor(0, 1);
    LCD.print("D:");
    LCD.print(value2);
    LCD.print(" oD:");
    LCD.print(okd);
    if (stopbutton()) {
      lbase = speeds[count];
      rbase = speeds[count];
      if (count > 4)
        count = 0;
      else 
        count++;
     delay(100);
    }
    LCD.print("M:");
    LCD.print(lbase);
    delay(100);
  }

  kp = value1;
  kd = value2;
  delay(500);
}
void servoMenu() {
  int angle = ARMSERVREST;

  while(! startbutton()) {
    angle = knob(6)/3;
    LCD.clear();
    LCD.setCursor(0,0);
    LCD.print("angle: ");
    LCD.print(angle);
    LCD.setCursor(0,1);
    LCD.print("START to write");
  }
  armRotate(angle);
  while(! stopbutton()) {
    angle = knob(6)/3;
    LCD.clear();
    LCD.setCursor(0,0);
    LCD.print("angle: ");
    LCD.print(angle);
    LCD.setCursor(0,1);
    LCD.print("STOP to write");    
  }
  armRotate(angle);
  delay(200);
}
//void nodeMenu(i
