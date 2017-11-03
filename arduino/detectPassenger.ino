#define IR_THRESH 500
#define MAX_NOISE_AMP 20

void detectPassenger(){
  if (analogRead(IRLEFT) > IR_THRESH) {
    //passenger detected on the left
    //don't turn on a dime
    if(analogRead(IRLEFT)< (IRVal-MAX_NOISE_AMP)){
      hardStop();
      LCD.clear();
      LCD.setCursor(0,0);
      LCD.print("L IRVal: ");
      LCD.print(IRVal);
      LCD.setCursor(0,1);
      LCD.print("START to pickup");
      while(!startbutton()) {
        //just chill
      }
      IRVal = 0;
    } else {
      IRVal = analogRead(IRLEFT);
    }
    Serial.println(IRVal);
  } 
//  else if (analogRead(IRRIGHT) > IR_THRESH) {
//    if(analogRead(IRRIGHT)<IRVal){
//      hardStop();
//      IRVal = 0;
//    } else {
//      IRVal = analogRead(IRRIGHT);
//    }
//    LCD.clear();
//    LCD.setCursor(0,0);
//    LCD.print("R IRVal: ");
//    LCD.print(IRVal);
//    LCD.setCursor(0,1);
//    LCD.print("START to U_turn");
//    while(!startbutton()) {
//      //just chill
//    }
//    motor.speed(LMOTOR, -200);
//    motor.speed(RMOTOR, 200);
//  }
  pickupPassenger();
}

void pickupPassenger() {
  adjustGripper();

  armGetPassenger();
  armDropPassenger();
  numPassengers++;
}

void adjustGripper(){
  int armServo = 0;
  int maxArmServo = 180;
  int armShoulder = analogRead(ARMPOS1);
  int gripIR = analogRead(IRGRIP);

  int prevLoIR, prevHiIR;
  int servoSpeed = 5;
  int motorSpeed = 50;

  do {
    RCServo2.write(armServo);
    armServo += servoSpeed;
    if (armServo > maxArmServo)
      break;

    prevLoIR = gripIR - MAX_NOISE_AMP;
    prevHiIR = gripIR + MAX_NOISE_AMP;
    gripIR = analogRead(IRGRIP);
  } while (gripIR > prevLoIR && gripIR < prevHiIR);
}
//
//void adjustChassis(int overShoot) {
//  int gripIR = analogRead(IRGRIP);
//  int prevLoIR, prevHiIR;
//
//  int motorSpeed = 50;
//  if (overShoot)
//    motorSpeed = -50;
//
//  do {
//    motor.speed(LMOTOR, motorSpeed);
//    motor.speed(RMOTOR, motorSpeed);
//
//    prevLoIR = gripIR - MAX_NOISE_AMP;
//    prevHiIR = gripIR + MAX_NOISE_AMP;
//    gripIR = analogRead(IRGRIP);
//  } while (gripIR > prevLoIR && gripIR < prevHiIR);
//
//  hardStop();
//}
