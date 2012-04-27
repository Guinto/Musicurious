#ifndef _WINDOW_H_
#define _WINDOW_H_

#include "Utilities.h"

#define WORLD_SIZE_MULT 2

void reshapeWindow(int w, int h);
float viewPortWidth(int w);
float viewPortHeight(int h);
float viewPortLowerLeftCornerY();
float viewPortLowerLeftCornerX();
float leftVerticalClippingPlane(int w, int h);
float rightVerticalClippingPlane(int w, int h);
float topHorizontalClippingPlane();
float bottomHorizontalClippingPlane();
float nearDepthClippingPlane();
float farDepthClippingPlane();

#endif
