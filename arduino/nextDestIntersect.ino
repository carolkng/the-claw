//Returns the next direction you should go based on the IR intensity
int nextDestIntersect(int currentNode, int nextNode){
  int lIntIr = -1;
  int rIntIr = -1;
  int fIntIr = -1;
//  // Serial.print("\nnextDestIntersect - currentNode: "); 
//  // Serial.print(currentNode);
//  // Serial.print("\nnextDestIntersect - nextNodede: "); 
//  // Serial.print(nextNode);
//  // Serial.print("\nnextDestIntersect - LEFT: "); 
//  // Serial.print(nodeMap[currentNode][nextNode][LEFT]);
//  // Serial.print("\nnextDestIntersect - RIGHT: "); 
//  // Serial.print(nodeMap[currentNode][nextNode][RIGHT]);
//  // Serial.print("\nnextDestIntersect - STRAIGHT: "); 
//  // Serial.print(nodeMap[currentNode][nextNode][STRAIGHT]);
  
  if(nodeMap[currentNode][nextNode][LEFT] > -1){
    lIntIr = analogRead(IRFRONTLEFT);
  }
  if(nodeMap[currentNode][nextNode][RIGHT] > -1){
    rIntIr  = analogRead(IRFRONTRIGHT);
  }
  if(nodeMap[currentNode][nextNode][STRAIGHT] > -1){
    fIntIr = analogRead(IRFRONT);
  }
  int Irs[3] = {lIntIr, rIntIr, fIntIr};
  return findMax(Irs, 3);
}
