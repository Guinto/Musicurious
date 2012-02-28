#ifndef _CUBE_H_
#define _CUBE_H_

#include "KeyboardState.h"
#include "Object.h"
#include "Point3d.h"
#include "Color.h"
#include "Audio.h"

#include <iostream>
#include <fstream>
#include <string>

#define DEFAULT_SIZE 0.5
#define DEFAULT_RED 1
#define DEFAULT_GREEN 1
#define DEFAULT_BLUE 1

using namespace std;

class Cube: public Object {
   private:
      float timeElapsed;
      float size;

      Audio *audio;

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
