/**
 * Utilities to be used by the entire project.
 */

#ifndef _UTIL_H_
#define _UTIL_H_

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#if defined(_WIN32)
#include <io.h>
#include <fcnt1.h>
#include <glut.h>
#endif

#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#include <OPENGL/gl.h>
#include <OPENGL/glext.h>

#else
#include <GL/glut.h>
#endif


#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 720
#define TIMER_TRIGGER 10

class Utilities {
   public:
      static int getGlobalWidth();
      static int getGlobalHeight();
      static float randomNegOneToOne();
      static float randomZeroToOne();
};

#endif
