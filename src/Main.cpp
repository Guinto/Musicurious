#include "Utilities.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Window.h"
#include "Scene.h"

#define FIELD_OF_VIEW_ANGLE 60
#define NEAR_CLIPPING_PLANE 0.05
#define FAR_CLIPPING_PLANE 2000
#define MILLISECONDS_OVER_SECONDS .001
#define IGNORE_KEY_REPEAT_ON 1

void initializeGlobalVariables();
void initializeGlutSettings(int argc, char **argv);
void enableDepthTestingForRendering3DPolygons();
void registerCallbackFunctions();
void startTheMainLoop();

Scene scene;
long startLoop;

void setupScene(char **argv) {
	char* songFileName = argv[1];
	scene.setup(songFileName);
}

void loop(int n) {
   long oldStartLoop = startLoop;
   startLoop = (long) glutGet(GLUT_ELAPSED_TIME);
   float timeElapsed = (float) (startLoop - oldStartLoop);
   timeElapsed = timeElapsed * MILLISECONDS_OVER_SECONDS;

   updateKeyboardStateInScene();
   scene.update(timeElapsed);
   
   glutPostRedisplay();
   glutTimerFunc(TIMER_TRIGGER, loop, TIMER_TRIGGER);
}

void display() {
   glFlush();
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(FIELD_OF_VIEW_ANGLE, 
      ((float)Utilities::getGlobalWidth()) / Utilities::getGlobalHeight(), 
      NEAR_CLIPPING_PLANE,
      FAR_CLIPPING_PLANE);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   scene.draw();

   glutSwapBuffers();
}

int main(int argc, char **argv) {
   setupScene(argv);
   initializeGlobalVariables();
   initializeGlutSettings(argc, argv);
   enableDepthTestingForRendering3DPolygons();
   registerCallbackFunctions();
   startTheMainLoop();
}

void initializeGlobalVariables() {
   startLoop = 0;
   glutTimerFunc(TIMER_TRIGGER, loop, TIMER_TRIGGER);
   initializeMousePosition();
}

void initializeGlutSettings(int argc, char **argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(Utilities::getGlobalWidth(), Utilities::getGlobalHeight());
   glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
   glutCreateWindow("Particle System");
   glutIgnoreKeyRepeat(IGNORE_KEY_REPEAT_ON);
}

void enableDepthTestingForRendering3DPolygons() {
   glEnable(GL_DEPTH_TEST);
   glClearColor(0.0, 0.0, 0.0, 1.0);
}

void registerCallbackFunctions() {
   glutDisplayFunc(display);
   glutReshapeFunc(reshapeWindow);
   glutMouseFunc(mouseClick);
   glutMotionFunc(mouseMove);
   glutKeyboardFunc(keyboard);
   glutKeyboardUpFunc(keyboardUp);
}

void startTheMainLoop() {
   glutMainLoop();
}
