#ifndef _KEYBOARDSTATE_H_
#define _KEYBOARDSTATE_H_

#define NUMBER_OF_ASCII_KEYS 256

class KeyboardState {
   private:
      bool keyboardState[NUMBER_OF_ASCII_KEYS];

   public:
      KeyboardState();
      KeyboardState& operator= (KeyboardState newKeyboardState);
      bool get(char key);
      void set(char key, bool conditional);
};

#endif
