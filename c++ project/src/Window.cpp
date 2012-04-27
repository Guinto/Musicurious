#include "Window.h"

#define LOWER_LEFT_X 0
#define LOWER_LEFT_Y 0

/*note that we have made our world 2ce as big */
void reshapeWindow(int width, int height) {
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glViewport(LOWER_LEFT_X, LOWER_LEFT_Y, width, height);

   glutPostRedisplay();
}
