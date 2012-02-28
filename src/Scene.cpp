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
   if (ap->isPlaying()) {
   CFRunLoopRunInMode (                           // 6
   			kCFRunLoopDefaultMode,                     // 7
   			0.25,                                      // 8
   			false                                      // 9
   		);
   }
}

void Scene::setKeyboardState(KeyboardState newKeyboardState) {
   keyboardState = newKeyboardState;
}

void Scene::updateKeyboardStateInObjects() {
   for (int i = 0; i < objects.size(); i++) {
   }
}

void Scene::setup(string songFileName) {
	const char *fn = songFileName.c_str();

	ap = AudioPlayer::file(fn);

	if(!ap) {
		std::cerr << "Error loading audio" << std::endl;
		exit(EXIT_FAILURE);
	}

	ap->play();

	//delete ap;
   objects.add(new Cube());
   /*Model *sharky = new Model();
   sharky->setModelFile((char*)"model/sharky/sharky_complete.obj");
   objects.add(sharky);*/
}
