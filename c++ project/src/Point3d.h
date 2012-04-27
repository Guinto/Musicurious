#ifndef _POINT3D_H_
#define _POINT3D_H_

#include <math.h>

typedef struct Point3d {
   float x;
   float y;
   float z;

   Point3d(): x(0), y(0), z(0) {};
   Point3d(float inX, float inY, float inZ): x(inX), y(inY), z(inZ) {};

   Point3d operator* (float f) {
      return Point3d(x * f, y * f, z * f);
   }
   Point3d operator/ (float f) {
      return Point3d(x / f, y / f, z / f);
   }
   Point3d operator+ (Point3d p) {
      return Point3d(x + p.x, y + p.y, z + p.z);
   }
   Point3d operator- (Point3d p) {
      return Point3d(x - p.x, y - p.y, z - p.z);
   }
   void operator= (Point3d p) {
      x = p.x;
      y = p.y;
      z = p.z;
   }
   void operator<= (float f) {
      x = f;
      y = f;
      z = f;
   }

   float magnitude() { return sqrt(x * x + y * y + z * z); }

} Point3d;

#endif
