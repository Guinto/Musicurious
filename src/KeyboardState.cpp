#include "KeyboardState.h"
#include <stdio.h>

KeyboardState::KeyboardState() {
   for (unsigned int key = 0; key < NUMBER_OF_ASCII_KEYS; key++) {
      keyboardState[key] = false;
   }
}

KeyboardState& KeyboardState::operator= (KeyboardState newKeyboardState) {
   for (unsigned int key = 0; key < NUMBER_OF_ASCII_KEYS; key++) {
      keyboardState[key] = newKeyboardState.get(key);
   }
   return *this;
}

bool KeyboardState::get(char key) {
   return keyboardState[key];
}

void KeyboardState::set(char key, bool conditional) {
   keyboardState[key] = conditional;
}
