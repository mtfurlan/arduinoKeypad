#include <Keyboard.h>
#include "Remote.h"

//Set what pins you are using here.
const int button_pins[] = {10,14,15,9,7,5};

//This is an array of function pointers. It relates to the button on the same pin in the button_pins array.
void (*button_functions[])() = {&volDown, &volUp, &nothing, &hackADay, &boss, &pausePlay};

//Debounce setup
int button_state[] = {1,1,1,1,1,1};
int button_state_last[] = {1,1,1,1,1,1};
int debounce[] = {0,0,0,0,0,0};
const int debounce_time = 50;

/**** Functions to run ****/
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

/**** Setup and Loop ****/
void setup() {
  int i = 0;
  //Set each pin to be an input pin tied high
  for (; i < 6; ++i) {
    pinMode(button_pins[i], INPUT_PULLUP);
  }
}

void loop() {
  int i = 0;
  //Foreach pin run debouncing, and if it's a real press call the function
  for (; i < 6; ++i) {
    button_state[i] = digitalRead(button_pins[i]);//Read current state
    //If the current state does not equal the last state, AND it's been long enough since the last change
    if (button_state[i] != button_state_last[i] && millis() - debounce[i] > debounce_time) {
      //If the button is pressed, call funciton
      if (button_state[i] == LOW) {
        button_functions[i]();
      }
      //If the button was pressed or released, we still need to reset the debounce timer.
      button_state_last[i] = button_state[i];
      debounce[i] = millis();
    }
  }
}
