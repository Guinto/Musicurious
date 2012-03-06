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
		startScene(getSongFileName());
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

void Scene::startScene(char* songFileName) {
   objects.add(new Cube(songFileName));
   audio = new Audio(songFileName);
   audio->play();
}

void Scene::updateKeyboardStateInObjects() {
   for (int i = 0; i < objects.size(); i++) {
      Cube *c = (Cube*) objects.get(i);
      c->setKeyboardState(keyboardState);
   }
}

char* Scene::getSongFileName() {
	return songFileName;
}

void Scene::setup(char* newSongFileName) {
	songFileName = newSongFileName;
   /*Model *sharky = new Model();
   sharky->setModelFile((char*)"model/sharky/sharky_complete.obj");
   objects.add(sharky);*/
}
