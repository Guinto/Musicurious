#include "Cube.h"

Cube::Cube() {
   initializeDefaultSize();
   audio = new Audio();
}

void Cube::initializeDefaultSize() {
   size = DEFAULT_SIZE;
}

void Cube::update(float timeElapsed) {
   setTimeElapsed(timeElapsed);
   audio->update(timeElapsed);
   movePositionWithPitch();
   growSizeWithLoudness();
}

void Cube::growSizeWithLoudness() {
	size = DEFAULT_SIZE + audio->getLoudness() * 0.2;
}

void Cube::movePositionWithPitch() {
	position.y = audio->getPitch() * 0.01 - 2;
}

void Cube::setTimeElapsed(float newTimeElapsed) {
   timeElapsed = newTimeElapsed;
} 

void Cube::draw() {
   glPushMatrix(); {
      glColor3f(DEFAULT_RED, DEFAULT_GREEN, DEFAULT_BLUE);
      glTranslatef(position.x, position.y, position.z);
      glutSolidCube(size);
   } glPopMatrix();
}
