#define DOT_LENGTH 100

const uint8_t alphabet [] = {
  5, 24, 26, 12, 2,
  18, 14, 16, 4, 23,
  13, 20, 7, 6, 15,
  22, 29, 10, 8, 3,
  9, 17, 11, 25, 27,
  28
};

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  transmit("hello your name here");
  delay(1000);
}

void transmit(String string) {
  for (int i = 0; string[i] > 0; i++) {
    char c = string[i];
    if (c >= 'a' && c <= 'z') {
      dot_dash(alphabet[c - 'a']);
      letter();
    } else {
      // Everything else is a word separator
      word();
    }
  }
}

void dot_dash(uint8_t elements) {
  do {
    if (elements & 1) {
      dash();
    } else {
      dot();
    }
    elements >>= 1;
    if (elements > 1) {
      symbol();
    }
  } while (elements > 1);
}

void dot() {
  led(DOT_LENGTH);
}

void dash() {
  led(3 * DOT_LENGTH);
}

void symbol() {
  delay(DOT_LENGTH);
}

void letter() {
  delay(3 * DOT_LENGTH);
}

void word() {
  delay(7 * DOT_LENGTH);
}

void led(uint16_t time) {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(time);
  digitalWrite(LED_BUILTIN, LOW);
}
