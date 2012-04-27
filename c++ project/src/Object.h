#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "Utilities.h"
#include "Point3d.h"
#include "KeyboardState.h"
#include "Audio.h"

#define DEFAULT_SIZE 0.5

class Object {
   public:
      int id;
      Point3d position;
      float size;
      KeyboardState keyboardState;
      Audio *audio;
      virtual ~Object() {}
      virtual void draw() = 0;
      virtual void update(float timeElapsed) = 0;
      void setAudio(Audio *audio);
      void setPosition(Point3d newPosition);
      void movePositionWithPitch();
      void growSizeWithLoudness();
      void setKeyboardState(KeyboardState newKeyboardState);
};

#endif
