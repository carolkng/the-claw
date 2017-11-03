int findMax(int intArray[], int arraySize){
  int i, val, id;
  val = -2;
  // Serial.print("\nfindMax - intArray:");
  for (i=0;i<arraySize;i++) {
    if (intArray[i] > val) {
      id = i;
      val = intArray[i];
    }
    // Serial.print(intArray[i]);
    // Serial.print(" ");
  }
  // Serial.print("\nfindMax - returned:");
  // Serial.print(id);
  return id;
}

