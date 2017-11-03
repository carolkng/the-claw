// Returns the next direction you should take if you want to go to the dropoff point
int nextDestDropoff(int currentNode, int nextNode) {
  int nodesToDest[21] = {10, 7, 5, 8, 15, 12, 7, 11, 14, 8, 16, 17, 11, 14, 19, 20, 17, 18, 18, 18, 19};
  if (nodeMap[currentNode][nextNode][LEFT] == nodesToDest[nextNode])
    return LEFT;
  else if (nodeMap[currentNode][nextNode][RIGHT] == nodesToDest[nextNode])
    return RIGHT;
  else
    return STRAIGHT;
}
