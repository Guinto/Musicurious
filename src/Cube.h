#ifndef _CUBE_H_
#define _CUBE_H_

#include <iostream>
#include <fstream>
#include <string>

#include "ParticleSystem.h"
#include "Audio.h"

#define DEFAULT_SIZE 0.5
#define DEFAULT_CUBE_RED 1
#define DEFAULT_CUBE_GREEN 1
#define DEFAULT_CUBE_BLUE 1

using namespace std;

class Cube: public Object {
   private:
      float timeElapsed;
      float size;

      Audio *audio;
      ParticleSystem *particleSystem;

      void initializeDefaultSize();
      void setTimeElapsed(float newTimeElapsed);
      void movePositionWithPitch();
      void growSizeWithLoudness();

   public:
      Cube();
      void draw();
      void update(float timeElapsed);
};

#endif
