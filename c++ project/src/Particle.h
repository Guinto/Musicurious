#ifndef _PARTICLE_H_
#define _PARTICLE_H_

#include "Object.h"
#include "Point3d.h"
#include "Color.h"

#define DEFAULT_LIFE_TIME 4
#define DEFAULT_ROTATION 0
#define DEFAULT_BIRTH_SIZE 0.1f
#define DEFAULT_DEATH_SIZE 0
#define DEFAULT_RED 0
#define DEFAULT_GREEN 0
#define DEFAULT_BLUE 0
#define DEFAULT_SIZE_VARIANCE 0.5f
#define PHYSICS_POSITION_CONSTANT 0.5f
#define DEFAULT_MASS 50

typedef Point3d Vector;

typedef struct Life {
   float time;
   float birthSize;
   float deathSize;
   Color birthColor;
   Color deathColor;
} Life;

class Particle: public Object {
   private:
      float timeElapsed;
      Point3d rotationAxis;
      float rotationDegree;
      float size;
      Color color;
      Life life;

      Vector velocity;
      Vector acceleration;
      Vector force;
      float mass;

      void initializeDefaultLifeVariables();
      void initializeRotation();
      void initializeColor();
      void createColorVariance();
      void createSizeVariance();
      void initializeDefaultSize();
      void initializeDefaultPhysics();
      void interpolateLifeTime();
      void setTimeElapsed(float newTimeElapsed);
      void interpolateSize();
      void interpolateColor();
      void calculatePhysics();
      void calculateAcceleration();
      void calculateVelocity();
      void calculatePosition();

   public:
      Particle();
      void draw();
      void update(float timeElapsed);
      bool isDead();
      void setRotationAxis(Point3d newRotationAxis);
      void setRotationDegree(float newRotationDegree);
      float setBirthSize(float newBirthSize);
      float setDeathSize(float newDeathSize);
      Color setBirthColor(Color newBirthColor);
      Color setDeathColor(Color newDeathColor);
      Vector setVelocity(Vector newVelocity);
      Vector setAcceleration(Vector newAcceleration);
      Vector setForce(Vector newForce);
      void applySettings();
};

#endif
