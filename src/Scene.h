#ifndef _SCENE_H_
#define _SCENE_H_

#include "Cube.h"
#include "ObjectCollection.h"
#include "Ground.h"
#include "Camera.h"
#include "Model.h"

class Scene: public Object {
   private:
      ObjectCollection objects;
      Camera camera;
      Ground ground;
      Audio *audio;

      void updateKeyboardStateInObjects();
      void startScene();
      void destroyScene();
      void keyboardActions();

   public:
      void setup(char* songFileName);
      void draw();
      void update(float timeElapsed);
};

#endif
