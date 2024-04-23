const int segmentPins[] = {3, 7, 12, 10, 9, 4, 13, 11}; // pins A - G, DP
const int digitPins[] = {2, 5, 6, 8}; // D1 - D4
const int t = 250; // Time delay

void setup() {
  for (int pin : segmentPins)
    pinMode(pin, OUTPUT);
  for (int pin : digitPins)
    pinMode(pin, OUTPUT);
}

void loop() {
  //F
  writeDigit(0);
  printChar(10);
  //A
  writeDigit(1);
  printChar(11);
  //I
  writeDigit(2);
  printChar(1);
  //L
  writeDigit(3);
  printChar(12);
  
  //printDP();
  delay(1);
}

void writeDigit(int digit) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(digitPins[i], i == digit ? LOW : HIGH);
  }
}

void printChar(int character) {
  const int numCharacters = 16;
  const int characterPatterns[numCharacters][8] = {
    {1, 1, 1, 1, 1, 1, 0, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1, 0}, // 2
    {1, 1, 1, 1, 0, 0, 1, 0}, // 3
    {0, 1, 1, 0, 0, 1, 1, 0}, // 4
    {1, 0, 1, 1, 0, 1, 1, 0}, // 5
    {1, 0, 1, 1, 1, 1, 1, 0}, // 6
    {1, 1, 1, 0, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1, 0}, // 8
    {1, 1, 1, 1, 0, 1, 1, 0}, // 9
    {0, 1, 1, 1, 1, 1, 1, 0}, // F
    {1, 1, 1, 0, 1, 1, 1, 0}, // A
    {0, 0, 0, 1, 1, 1, 0, 0}  // L
  };

  if (character >= 0 && character < numCharacters) {
    for (int i = 0; i < 7; i++)
      digitalWrite(segmentPins[i], characterPatterns[character][i] ? HIGH : LOW);
  }
}

void printDP() {
  digitalWrite(segmentPins[7], HIGH);
}

void printOff() {
  for (int pin : segmentPins)
    digitalWrite(pin, LOW);
}