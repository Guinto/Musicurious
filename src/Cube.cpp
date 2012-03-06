#include "Cube.h"

Cube::Cube() {
   initializeDefaultSize();
   particleSystem = new ParticleSystem();
   audio = new Audio();
}

Cube::Cube(Audio* newAudio) {
   initializeDefaultSize();
   particleSystem = new ParticleSystem();
   audio = newAudio;
}

void Cube::initializeDefaultSize() {
   size = DEFAULT_SIZE;
}

void Cube::update(float timeElapsed) {
   setTimeElapsed(timeElapsed);
   audio->update(timeElapsed);
   particleSystem->setPosition(Point3d(position.x, position.y, position.z));
   particleSystem->update(timeElapsed);
   movePositionWithPitch();
   growSizeWithLoudness();
   particleSystem->setKeyboardState(keyboardState);
}

void Cube::setKeyboardState(KeyboardState newKeyboardState) {
   keyboardState = newKeyboardState;
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
      glColor3f(DEFAULT_CUBE_RED, DEFAULT_CUBE_GREEN, DEFAULT_CUBE_BLUE);
      glTranslatef(position.x, position.y, position.z);
      glutSolidCube(size);
   } glPopMatrix();
   glPushMatrix(); {
	   particleSystem->draw();
   } glPopMatrix();
}
