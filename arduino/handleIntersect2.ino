void handleIntersect2() {
  int temp;
  int lInt = !digitalRead(LINTTAPE);
  int rInt = !digitalRead(RINTTAPE);
  
  boolean front = (nodeMap[lastNode][nextNode][STRAIGHT] != -1);
  boolean left = (nodeMap[lastNode][nextNode][LEFT] != -1);
  boolean right = (nodeMap[lastNode][nextNode][RIGHT] != -1);

  motor.stop_all();

  while (! startbutton()) {
    LCD.clear();
    LCD.setCursor(0,0);
    LCD.print("TD ");
    if (turnDecision == LEFT)
      LCD.print("L");
    else if (turnDecision == RIGHT)
      LCD.print("R");
    else if (turnDecision == STRAIGHT)
      LCD.print("S");
    else 
      LCD.print(turnDecision);
    LCD.print(" LN ");
    LCD.print(lastNode);
    LCD.print(" CN ");
    LCD.print(nextNode);
    LCD.setCursor(0,1);
    LCD.print("START to continue");
  }
  while(startbutton()) {
    LCD.print("CHILLING");
    // just chill
  }

  // Nodes 0-4 are the top nodes; if the tape follower turns around before reaching them instead of bumping into the side, reverse the nodes
  // Nodes 5 and 9 are the "dead end" nodes. The tape follower will reach the end of the tape and automatically turn around.
  if ((nextNode <= 5 && nextNode >= 0) || nextNode == 9) {
    temp = lastNode;
    lastNode = nextNode;
    nextNode = temp;
    return;
  }
  
  if(turnDecision == LEFT) {
    hardLeft();
    temp = nodeMap[lastNode][nextNode][0];
    lastNode = nextNode;
    nextNode = temp;
  }
  else if(turnDecision == RIGHT) {
    hardRight();
    temp = nodeMap[lastNode][nextNode][1];
    lastNode = nextNode;
    nextNode = temp;
  }
  else{
    temp = nodeMap[lastNode][nextNode][2];
    lastNode = nextNode;
    nextNode = temp;
  }
}
