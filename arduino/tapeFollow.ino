void tapeFollow() {
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
  if (!(err == lerr)) {
    recerr = lerr;
    q = m;
    m = 1;
  }

  p = KP * err;
  d = (int)((float)KD * (float)(err - recerr) / (float)(q + m));
  con = p + d;

  l_motor = LBASE + con;
  r_motor = RBASE - con;

  if (l_motor < -250) {
    l_motor = -250;
  } else if (l_motor > 250) {
    l_motor = 250;
  }
  if (r_motor < -250) {
    r_motor = -250;
  } else if (r_motor > 250) {
    r_motor = 250;
  }

  m++;
  motor.speed(LMOTOR, l_motor);
  motor.speed(RMOTOR, r_motor);
  lerr = err;  
}

