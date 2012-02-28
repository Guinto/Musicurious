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

void Scene::updateKeyboardStateInObjects() {
   for (int i = 0; i < objects.size(); i++) {
   }
}

void Scene::setup(string songFileName) {

   objects.add(new Cube());
   /*Model *sharky = new Model();
   sharky->setModelFile((char*)"model/sharky/sharky_complete.obj");
   objects.add(sharky);*/
}
