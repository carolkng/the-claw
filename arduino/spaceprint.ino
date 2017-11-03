int labelPrint(char s1[], int i1, char s2[], int i2, char s3[], int i3) {
  LCD.print(s1);
  LCD.print(":");
  LCD.print(i1);
  LCD.print(" ");
  LCD.print(s2);
  LCD.print(":");
  LCD.print(i2);
  LCD.print(" ");
  LCD.print(s3);
  LCD.print(":");
  LCD.print(i3);
  return 0;
}
int irPrint(char s1[], int i1, char s2[], int i2, char s3[], int i3) {
  LCD.print(s1);
  LCD.print(i1);
  LCD.print(s2);
  LCD.print(i2);
  LCD.print(s3);
  LCD.print(i3); 
  return 0;
}

