const int ledPins[11] = {2,3,4,5,6,7,8,9,10,11,12};

void setup() {
  for (int i = 0; i < 11; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }

  Serial.begin(9600);
}

void loop() {
  // MATLAB'tan 11 karakter bekleniyor (0 veya 1)
  if (Serial.available() >= 11) {
    for (int i = 0; i < 11; i++) {
      char c = Serial.read();
      if (c == '1')
        digitalWrite(ledPins[i], HIGH);
      else
        digitalWrite(ledPins[i], LOW);
    }
  }
}
