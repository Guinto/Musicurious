#ifndef _CUBE_H_
#define _CUBE_H_

#include <iostream>
#include <fstream>

#include "ParticleSystem.h"
#include "Audio.h"

#define DEFAULT_SIZE 0.5
#define DEFAULT_CUBE_RED 1
#define DEFAULT_CUBE_GREEN 1
#define DEFAULT_CUBE_BLUE 1

class Cube: public Object {
   private:
      float timeElapsed;
      float size;

      Audio *audio;
      ParticleSystem *particleSystem;
      KeyboardState keyboardState;

      void initializeDefaultSize();
      void setTimeElapsed(float newTimeElapsed);
      void movePositionWithPitch();
      void growSizeWithLoudness();

   public:
      Cube();
      Cube(char* songFileName);
      void draw();
      void update(float timeElapsed);
      void setKeyboardState(KeyboardState newKeyboardState);
};

#endif
