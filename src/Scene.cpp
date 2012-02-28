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
	const char *fn = songFileName.c_str();

	    AudioPlayer* ap = AudioPlayer::file(fn);

	    if(!ap) {
	        std::cerr << "Error loading audio" << std::endl;
	        exit(EXIT_FAILURE);
	    }

	    ap->play();

	    char indic[] = { '|', '/', '-', '\\' };
	    int i = 0;
	    do {                                               // 5
	//        std::cout << "Loop." << std::endl;
	        CFRunLoopRunInMode (                           // 6
	            kCFRunLoopDefaultMode,                     // 7
	            0.25,                                      // 8
	            false                                      // 9
	        );

	        std::cout << "\rPlaying.. " << indic[i];

	        double d = ap->progress();
	        double min = floor(d/60);
	        double sec = floor(fmod(d,60));
	        std::cout << "   " << min << ":" << sec;

	        d = ap->duration();
	        min = floor(d/60);
	        sec = floor(fmod(d,60));
	        std::cout << "   " << min << ":" << sec;

	        std::cout << std::flush;

	        if(ap->progress() > 5) {
	            ap->seek(rand()/(float(RAND_MAX))*ap->duration());
	        }

	        i = (i+1)%4;
	    } while (ap->isPlaying());

	    delete ap;
   //objects.add(new Cube());
   /*Model *sharky = new Model();
   sharky->setModelFile((char*)"model/sharky/sharky_complete.obj");
   objects.add(sharky);*/
}
