#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "Utilities.h"
#include "Point3d.h"
#include "KeyboardState.h"

class Object {
   public:
      int id;
      Point3d position;
      KeyboardState keyboardState;
      virtual ~Object() {}
      virtual void draw() = 0;
      virtual void update(float timeElapsed) = 0;
      void setPosition(Point3d newPosition);
      void setKeyboardState(KeyboardState newKeyboardState);
};

#endif
