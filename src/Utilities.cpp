/**
 * The utility functions that will be used by all classes.
 */

#include "Utilities.h"

int Utilities::getGlobalWidth() {
   return WINDOW_WIDTH;
}

int Utilities::getGlobalHeight() {
   return WINDOW_HEIGHT;
}

float Utilities::randomNegOneToOne() {
   return (float) rand() / RAND_MAX * 2 - 1;
}

float Utilities::randomZeroToOne() {
   return (float) rand() / RAND_MAX;
}
