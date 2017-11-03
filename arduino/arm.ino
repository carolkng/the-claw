void armGetPassenger() {
  int currentAngle = ARMSERVOUT;
  armRotate(currentAngle);
  int armStatus = armGoTo(ARMPOSOUT);
  while (armStatus != STRAIGHT) {
    // arm hit left switch (left from arm POV)
    if (armStatus == LEFT) {
      currentAngle = currentAngle + ARMSERVNUDGE;
      armRotate(currentAngle);
      armStatus = armGoTo(ARMPOSOUT);
    } else if (armStatus == RIGHT) {
      currentAngle = currentAngle + ARMSERVNUDGE;
      armRotate(currentAngle);
      armStatus = armGoTo(ARMPOSOUT);
    } else {
      armStatus = armGoTo(ARMPOSOUT);
    }
  }
  gripperClose();
}

void armDropPassenger() {
  armRotate(ARMSERVOUT);
  armForceGoTo(ARMPOSOUT);
  gripperOpen();
  armForceGoTo(ARMPOSIN);
  armRotate(ARMSERVREST); 
}

void armRotate(int angle) {
  RCServo0.write(angle);
}

int armGoTo(int armDest) {
  int armMin = armDest - ARMTOLERANCE;
  int armMax = armDest + ARMTOLERANCE;

  int arm = analogRead(ARMPOS1);
  
  while ((arm > armMax) && (arm < armMin)){
    if (arm > armMax) {
      motor.speed(ARMMOTOR1, ARMSPEEDNEG);
    } else if (arm < armMin) {
      motor.speed(ARMMOTOR1, ARMSPEEDPOS);
    } else {
      motor.speed(ARMMOTOR1, 0);
    }

    arm = analogRead(ARMPOS1);

    if (digitalRead(GRIPBUMP)) {
      return STRAIGHT;
    }
    
    if (digitalRead(RGRIPBUMP)) {
      return LEFT;
    } else if (digitalRead(LGRIPBUMP)) {
      return RIGHT;
    }
  }

// in case the motor hit the switch and didn't stop!
  motor.speed(ARMMOTOR1, 0);
}

// Goes to armDest without looking at any of the switches
int armForceGoTo(int armDest) {
  int armMin = armDest - ARMTOLERANCE;
  int armMax = armDest + ARMTOLERANCE;

  int arm = analogRead(ARMPOS1);
  
  while ((arm > armMax) && (arm < armMin)){
    if (arm > armMax) {
      motor.speed(ARMMOTOR1, ARMSPEEDNEG);
    } else if (arm < armMin) {
      motor.speed(ARMMOTOR1, ARMSPEEDPOS);
    } else {
      motor.speed(ARMMOTOR1, 0);
    }

    arm = analogRead(ARMPOS1);
  }

// in case the motor hit the switch and didn't stop!
  motor.speed(ARMMOTOR1, 0);
  return 0;
}

