#include "Camera.h"

void Camera::updateLookAt() {
   gluLookAt(eye.x, eye.y, eye.z, center.x, center.y, center.z, up.x, up.y, up.z);
}

void Camera::update() {
   if (theta <= -FULL_CIRCLE_DEGREES || theta >= FULL_CIRCLE_DEGREES) {
      theta = 0;
   }

   theta += SPIN_SPEED;

   float radius;
   radius = eye.magnitude();
   eye.x = radius * cos(phi * DEGREES_TO_RADIANS) * cos(theta * DEGREES_TO_RADIANS);
   eye.y = radius * sin(phi * DEGREES_TO_RADIANS);
   eye.z = radius * cos(phi * DEGREES_TO_RADIANS) * cos((RIGHT_ANGLE_DEGREES - theta) * DEGREES_TO_RADIANS);
}
