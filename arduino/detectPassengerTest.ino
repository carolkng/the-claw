void detectPassengerTest() {
  if ((analogRead(IRLEFT) > IR_THRESH) || (analogRead(IRRIGHT) > IR_THRESH)) {
    hardStop();
    LCD.clear();
    LCD.print("Passenger detected");
    delay(200);
  }
}

