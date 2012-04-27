#include "Ground.h"

#define FLOOR_SIZE 100

void Ground::draw() {
   glPushMatrix(); {
      glColor3f(1, 1, 1);
      glBegin(GL_LINES); {
         drawHorizontalLines();
         drawVerticalLines();
      } glEnd();
   } glPopMatrix();
}

void Ground::setPitch(float newPitch) {
}

void Ground::drawHorizontalLines() {
   Point3d lineCreator;

   lineCreator = Point3d(position.x - FLOOR_SIZE / 2, position.y, position.z - FLOOR_SIZE / 2);
   for (unsigned int i = 0; i < FLOOR_SIZE; i++) {
      glVertex3f(lineCreator.x, lineCreator.y, lineCreator.z);
      lineCreator.z += FLOOR_SIZE;
      glVertex3f(lineCreator.x, lineCreator.y, lineCreator.z);
      lineCreator.z -= FLOOR_SIZE;
      lineCreator.x++;
   }
}

void Ground::drawVerticalLines() {
   Point3d lineCreator;

   lineCreator = Point3d(position.x - FLOOR_SIZE / 2, position.y, position.z - FLOOR_SIZE / 2);
   for (unsigned int i = 0; i < FLOOR_SIZE; i++) {
      glVertex3f(lineCreator.x, lineCreator.y, lineCreator.z);
      lineCreator.x += FLOOR_SIZE;
      glVertex3f(lineCreator.x, lineCreator.y, lineCreator.z);
      lineCreator.x -= FLOOR_SIZE;
      lineCreator.z++;
   }
}

void Ground::update(float timeElapsed) {

}
