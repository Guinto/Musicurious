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
   keyboardActions();
   updateKeyboardStateInObjects();
   for (int i = 0; i < objects.size(); i++) {
      objects.get(i)->update(timeElapsed);
   }
}

void Scene::keyboardActions() {
	if (keyboardState.get(' ')) {
		destroyScene();
		startScene();
	}
}

void Scene::destroyScene() {
	for (int i = 0; i < objects.size(); i++) {
		objects.erase(i);
	}
	if (audio != 0) {
		audio->~Audio();
	}
}

void Scene::startScene() {
   objects.add(new Cube());
   audio = new Audio();
   audio->play((char*)"audio/test.wav");
}

void Scene::updateKeyboardStateInObjects() {
   for (int i = 0; i < objects.size(); i++) {
      Cube *c = (Cube*) objects.get(i);
      c->setKeyboardState(keyboardState);
   }
}


void Scene::setup(char* songFileName) {
   /*Model *sharky = new Model();
   sharky->setModelFile((char*)"model/sharky/sharky_complete.obj");
   objects.add(sharky);*/
}
