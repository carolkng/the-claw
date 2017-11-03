void initializeRobot() {
  while (TRUE) {
    // digitalRead true if on tape, false otherwise
    left = !digitalRead(LTAPE);
    right = !digitalRead(RTAPE);
    leftint = !digitalRead(LINTTAPE);
    rightint = !digitalRead(RINTTAPE);
    
    // Both sensors on tape
    if (left && right)
      err = 0;
    // left sensor on tape, right sensor off
    if (left && (! right))
      err = -1;
    // right sensor on tape, left sensor off
    if ((! left) && right)
      err = 1;
    // both sensors are off the tape
    if (!(left || right)) {
      if (lerr > 0)
        err = 5;
      if (lerr <= 0)
        err = -5;
    }
    if (!(err==lerr)) {
      recerr=lerr;
      q=m;
      m=1;
    }
    
    p = kp * err;
    d = (int)((float)kd * (float)(err-recerr)/(float)(q+m));
    con = p+d;
    
    l_motor = -lbase+con;
    r_motor = -rbase-con;
    
    if (l_motor < -300) {
      l_motor = -300;
    } else if (l_motor > 300) {
      l_motor = 300;
    }
    if (r_motor < -300) {
      r_motor = -300;
    } else if (r_motor > 300) {
      r_motor = 300;
    }
    
    m++;
    motor.speed(LMOTOR, l_motor);
    motor.speed(RMOTOR, r_motor);
    lerr=err;
    
    if (!digitalRead(LINTTAPE)) {
      hardLeft();
      lastNode = 0;
      nextNode = 10;
      break;
    }
    if(!digitalRead(RINTTAPE)) {
      hardRight();
      lastNode = 4;
      nextNode = 15;
      break;
    }

    if (!(c%100)) {
      LCD.clear();
      LCD.print("detecting first node");
    }
  }
}
void initializeRobot2() {
  left = !digitalRead(LTAPE);
  right = !digitalRead(RTAPE);
  leftint = !digitalRead(LINTTAPE);
  rightint = !digitalRead(RINTTAPE);

    LCD.clear();
    LCD.setCursor(0,0);
    LCD.print("PRERUN- LT:");
    LCD.print(left);
    LCD.setCursor(0, 1);
    labelPrint("RT", right, "LI", leftint, "RI", rightint);
//    // Serial.print("initializing");
}

