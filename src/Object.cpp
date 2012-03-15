#include "Object.h"

void Object::setAudio(Audio* newAudio) {
   audio = newAudio;
}

void Object::setPosition(Point3d newPosition) {
   position.x = newPosition.x;
   position.y = newPosition.y;
   position.z = newPosition.z;
}

void Object::movePositionWithPitch() {
	position.y = audio->getPitch() * 0.01 - 2;
}

void Object::growSizeWithLoudness() {
	size = DEFAULT_SIZE + audio->getLoudness() * 0.2;
}

void Object::setKeyboardState(KeyboardState newKeyboardState) {
	keyboardState = newKeyboardState;
}
