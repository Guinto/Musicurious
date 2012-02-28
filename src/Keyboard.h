#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include "Utilities.h"
#include "KeyboardState.h"

#define CAPITAL_A 65
#define CAPITAL_Z 90
#define LOWERCASE_A 97
#define LOWERCASE_Z 122
#define DIFFERENCE_BETWEEN_CAP_AND_LOWER 32

void updateKeyboardStateInScene();
void keyboard(unsigned char key, int x, int y);
void keyboardUp(unsigned char key, int x, int y);
void exitProgram();

#endif
