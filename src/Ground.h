#ifndef _GROUND_H_
#define _GROUND_H_

#include "Object.h"
#include "Point3d.h"

class Ground: public Object {
   private:
      void drawHorizontalLines();
      void drawVerticalLines();
      
   public:
      Ground() {
         position = Point3d(0, -5, 0);
      }
      void draw();
      void update(float timeElapsed);
      void setPitch(float newPitch);
};

#endif
