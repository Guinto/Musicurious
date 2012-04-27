#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "Utilities.h"
#include "Point3d.h"

#define DEGREES_TO_RADIANS 0.0174532925
#define SPIN_SPEED 0.25
#define FULL_CIRCLE_DEGREES 360
#define RIGHT_ANGLE_DEGREES 90

class Camera {
   public:
      Point3d eye; 
      Point3d center; 
      Point3d up; 
      float theta;
      float phi;

      Camera() {
         eye = Point3d(0, 0, 5);
         center = Point3d();
         up = Point3d(0, 1, 0);
         theta = 0;
         phi = 0;
      }

      void update();
      void updateLookAt();
};

#endif
