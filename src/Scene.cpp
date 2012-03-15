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
   if (audio != 0) {
	   audio->update(timeElapsed);
   }
   for (int i = 0; i < objects.size(); i++) {
      objects.get(i)->update(timeElapsed);
      objects.get(i)->movePositionWithPitch();
      objects.get(i)->growSizeWithLoudness();
   }
}

void Scene::keyboardActions() {
	if (keyboardState.get(' ')) {
		destroyScene();
		startScene(songFileName);
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
   audio = new Audio(songFileName);
   Cube *c = new Cube();
   c->setAudio(audio);
   objects.add(c);
   /*Model *m = new Model();
   m->setAudio(audio);
   objects.add(m);*/
   audio->play();
}

void Scene::updateKeyboardStateInObjects() {
   for (int i = 0; i < objects.size(); i++) {
      Cube *c = (Cube*) objects.get(i);
      c->setKeyboardState(keyboardState);
   }
}


void Scene::setup(char* newSongFileName) {
	songFileName = newSongFileName;
   /*Model *sharky = new Model();
   sharky->setModelFile((char*)"model/sharky/sharky_complete.obj");
   objects.add(sharky);*/
}
