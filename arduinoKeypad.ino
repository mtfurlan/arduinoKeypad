const int button_pins[] = {2,3,4,5,6,7};
int button_state[] = {1,1,1,1,1,1};
int button_state_last[] = {1,1,1,1,1,1};
int debounce[] = {0,0,0,0,0,0};
const int debounce_time = 50;

void enter();
void science();
void bitches();
void del();
void bell();
void what();

void (*button_functions[])() = {&enter, &science, &bitches, &del, &bell, &what};

void enter() {
  Keyboard.write(10);
}

void science() {
      Keyboard.press(131);
      Keyboard.press('r');
      delay(10);
      Keyboard.releaseAll();
      delay(100);
      Keyboard.println("firefox http://xkcd.com/683/");
}

void bitches() {
  Keyboard.println("Yeah, Science Bitches!");
}

void del() {
  Keyboard.write(127);
}

void bell() {
  Keyboard.write(7);
}

void what() {
  Keyboard.write(0);
}

void setup() {
  int i = 0;
  for (; i < 6; ++i) {
    pinMode(button_pins[i], INPUT_PULLUP);
  }
}

void loop() {
  int i = 0;
  for (; i < 6; ++i) {
    button_state[i] = digitalRead(button_pins[i]);
    if (millis() - debounce[i] > debounce_time && button_state[i] != button_state_last[i]) {
      if (button_state[i] == LOW) {
        button_functions[i]();
      }
      button_state_last[i] = button_state[i];
      debounce[i] = millis();
    }
  }
}
