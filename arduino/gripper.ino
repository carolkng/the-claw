void gripperClose() {
  RCServo1.write(GRIPSERVMAX);
}

void gripperOpen() {
  RCServo1.write(GRIPSERVMIN);
}
