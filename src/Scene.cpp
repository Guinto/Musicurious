#include "Scene.h"

void Scene::draw() {
   camera.updateLookAt();
   glPushMatrix(); {
      ground.draw();
      for (int i = 0; i < objects.size(); i++) {
         objects.get(i)->draw();
      }
   } glPopMatrix();
}

void Scene::update(float timeElapsed) {
   updateKeyboardStateInObjects();
   for (int i = 0; i < objects.size(); i++) {
      objects.get(i)->update(timeElapsed);
   }
}

void Scene::setKeyboardState(KeyboardState newKeyboardState) {
   keyboardState = newKeyboardState;
}

void Scene::keyboardActions() {
	if (keyboardState.get(' ')) {
		startScene();
	}
}

void Scene::updateKeyboardStateInObjects() {
   for (int i = 0; i < objects.size(); i++) {
      Cube *c = (Cube*) objects.get(i);
      c->setKeyboardState(keyboardState);
   }
}

void Scene::startScene() {
   objects.add(new Cube());
   Audio *audio = new Audio();
   audio->play((char*)"audio/test.wav");
}

void Scene::setup(char* songFileName) {
	startScene();
   /*Model *sharky = new Model();
   sharky->setModelFile((char*)"model/sharky/sharky_complete.obj");
   objects.add(sharky);*/
}
