#ifndef _SCENE_H_
#define _SCENE_H_

#include "Cube.h"
#include "ObjectCollection.h"
#include "Ground.h"
#include "Camera.h"
#include "Model.h"

class Scene {
   private:
      KeyboardState keyboardState;
      ObjectCollection objects;
      Camera camera;
      Ground ground;

      void updateKeyboardStateInObjects();
      void startScene();
      void keyboardActions();

   public:
      void setup(char* songFileName);
      void draw();
      void update(float timeElapsed);
      void setKeyboardState(KeyboardState newKeyboardState);
};

#endif
