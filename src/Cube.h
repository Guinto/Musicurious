#ifndef _CUBE_H_
#define _CUBE_H_

#include <iostream>
#include <fstream>

#include "ParticleSystem.h"
#include "Audio.h"

#define DEFAULT_CUBE_RED 1
#define DEFAULT_CUBE_GREEN 1
#define DEFAULT_CUBE_BLUE 1

class Cube: public Object {
   private:
      float timeElapsed;

      ParticleSystem *particleSystem;

      void initializeDefaultSize();
      void setTimeElapsed(float newTimeElapsed);

   public:
      Cube();
      void draw();
      void update(float timeElapsed);
};

#endif
