#include "Cube.h"

Cube::Cube() {
   initializeDefaultSize();
   particleSystem = new ParticleSystem();
}

void Cube::initializeDefaultSize() {
   size = DEFAULT_SIZE;
}

void Cube::update(float timeElapsed) {
   setTimeElapsed(timeElapsed);
   particleSystem->setPosition(Point3d(position.x, position.y, position.z));
   particleSystem->update(timeElapsed);
   particleSystem->setKeyboardState(keyboardState);
}

void Cube::setTimeElapsed(float newTimeElapsed) {
   timeElapsed = newTimeElapsed;
} 

void Cube::draw() {
   glPushMatrix(); {
      glColor3f(DEFAULT_CUBE_RED, DEFAULT_CUBE_GREEN, DEFAULT_CUBE_BLUE);
      glTranslatef(position.x, position.y, position.z);
      glutSolidCube(size);
   } glPopMatrix();
   glPushMatrix(); {
	   particleSystem->draw();
   } glPopMatrix();
}
