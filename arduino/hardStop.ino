void hardStop(){
  LCD.clear();
  LCD.print("hard stop!");
  motor.speed(LMOTOR, -255);
  motor.speed(RMOTOR, -255);
  delay(10);
  motor.stop(LMOTOR);
  motor.stop(RMOTOR);
}
void hardRight() {
  int cc=0;
  motor.speed(LMOTOR, 250);
  motor.speed(RMOTOR, 0);

  // while on tape
  while(!digitalRead(RTAPE)) {
    LCD.clear();
    LCD.print("hard right! ");
    LCD.print(cc);
    LCD.setCursor(0,1);
    labelPrint("RT", !digitalRead(RTAPE), "LI", !digitalRead(LINTTAPE), "RI", !digitalRead(RINTTAPE));
    motor.speed(LMOTOR, 300);
    motor.speed(RMOTOR, 0);
    cc++;
  }
  // while off tape
  while(digitalRead(RTAPE)) {
    LCD.clear();
    LCD.print("hard right! ");
    LCD.print(cc);
    LCD.setCursor(0,1);
    labelPrint("RT", !digitalRead(RTAPE), "LI", !digitalRead(LINTTAPE), "RI", !digitalRead(RINTTAPE));
    motor.speed(LMOTOR, 300);
    motor.speed(RMOTOR, 0);
    cc++;
  }
}

void hardLeft() {
  int cc=0;
  LCD.clear();
  LCD.print("hard right! ");
  LCD.print(cc);
  LCD.setCursor(0,1);
//  labelPrint("RT", !digitalRead(RTAPE), "LI", !digitalRead(LINTTAPE), "RI", !digitalRead(RINTTAPE));
  motor.speed(RMOTOR, 250);
  motor.speed(LMOTOR, 0);

  while(!digitalRead(LTAPE)) {
    LCD.clear();
    LCD.print("hard left! ");
    LCD.print(cc);
    LCD.setCursor(0,1);
    labelPrint("LT", !digitalRead(LTAPE), "RT", !digitalRead(RTAPE), "LI", !digitalRead(RINTTAPE));
    motor.speed(RMOTOR, 300);
    motor.speed(LMOTOR, 0);
    cc++;
  }
  while(digitalRead(LTAPE)) {
    LCD.clear();
    LCD.print("hard left! ");
    LCD.print(cc);
    LCD.setCursor(0,1);
    labelPrint("LT", !digitalRead(LTAPE), "RT", !digitalRead(RTAPE), "LI", !digitalRead(RINTTAPE));
    motor.speed(RMOTOR, 300);
    motor.speed(LMOTOR, 0);
    cc++;
  }
}

