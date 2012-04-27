#ifndef _COLOR_H_
#define _COLOR_H_

typedef struct Color {
   float red;
   float green;
   float blue;

   Color(): red(0), green(0), blue(0) {};
   Color(float inRed, float inGreen, float inBlue): red(inRed), green(inGreen), blue(inBlue) {};

   Color operator+ (Color c) {
      return Color(red + c.red, green + c.green, blue + c.blue);
   }
   Color operator+= (Color c) {
      return Color(red += c.red, green += c.green, blue += c.blue);
   }
   Color operator- (Color c) {
      return Color(red - c.red, green - c.green, blue - c.blue);
   }
   Color operator-= (Color c) {
      return Color(red -= c.red, green -= c.green, blue -= c.blue);
   }
   Color operator* (float x) {
      return Color(red * x, green * x, blue * x);
   }
   Color operator/ (float x) {
      return Color(red / x, green / x, blue / x);
   }
   Color& operator= (Color c) {
      red = c.red;
      green = c.green;
      blue = c.blue;
      return *this;
   }

} Color;

#endif
