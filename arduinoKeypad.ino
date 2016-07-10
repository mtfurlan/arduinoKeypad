#include <Keyboard.h>
#include "Remote.h"


const int button_pins[] = {10,14,15,9,7,5};//Set what pins you are using here.
int button_state[] = {1,1,1,1,1,1};
int button_state_last[] = {1,1,1,1,1,1};
int debounce[] = {0,0,0,0,0,0};
const int debounce_time = 50;

void volUp();
void volDown();
void pausePlay();
void nothing();

//So this is an array of function pointers. This way, you can assign keys to functions easily.
void (*button_functions[])() = {&volDown, &volUp, &nothing, &hackADay, &boss, &pausePlay};

void hackADay() {
  //Windows only, is example of keyboard stuff
  Keyboard.press(KEY_RIGHT_GUI);
  Keyboard.press('r');
  delay(10);
  Keyboard.releaseAll();
  delay(100);
  Keyboard.println("chrome http://hackaday.com/");

  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
}

void boss(){
  Keyboard.press(KEY_ESC);
  Keyboard.releaseAll();

  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_TAB);
  delay(10);
  Keyboard.releaseAll();
}

void nothing() {
  //Look at all the nothing this is doing!:w
}

void volUp() {
  Remote.increase();
  Remote.clear();
}
void volDown() {
  Remote.decrease();
  Remote.clear();
}
void pausePlay() {
  Remote.pause();//Seems to toggle, think it might be an OS thing? If it's a problem, should put in a toggle variable here
  Remote.clear();
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
    if (button_state[i] != button_state_last[i] && millis() - debounce[i] > debounce_time) {
      if (button_state[i] == LOW) {
        button_functions[i]();
      }
      button_state_last[i] = button_state[i];
      debounce[i] = millis();
    }
  }
}
