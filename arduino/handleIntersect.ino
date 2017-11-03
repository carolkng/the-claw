void handleIntersect() {
  int temp;
  leftint = !digitalRead(LINTTAPE);
  rightint = !digitalRead(RINTTAPE);

  if (leftint) {
    hardLeft();

    temp = nodeMap[lastNode][nextNode][0];
    lastNode = nextNode;
    nextNode = temp;
  }
  else if (rightint) {
    hardRight();

    temp = nodeMap[lastNode][nextNode][1];
    lastNode = nextNode;
    nextNode = temp;
  } 
  // if nothing happened, then false positive! keep chilling.
}
