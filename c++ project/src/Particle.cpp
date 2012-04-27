#include "Particle.h"

Particle::Particle() {
   initializeDefaultLifeVariables();
   initializeRotation();
   initializeColor();
   initializeDefaultSize();
   initializeDefaultPhysics();
}

void Particle::initializeDefaultLifeVariables() {
   life.time = DEFAULT_LIFE_TIME;
   life.birthSize = DEFAULT_BIRTH_SIZE;
   life.deathSize = DEFAULT_DEATH_SIZE;
   life.birthColor = Color(DEFAULT_RED, DEFAULT_GREEN, DEFAULT_BLUE);
   life.deathColor = Color(DEFAULT_RED, DEFAULT_GREEN, DEFAULT_BLUE);
}

void Particle::initializeRotation() {
   rotationDegree = DEFAULT_ROTATION;
   rotationAxis = Point3d();
}

void Particle::initializeColor() {
   createColorVariance();
   color += life.birthColor;
}

void Particle::createColorVariance() {
   float colorBase = Utilities::randomZeroToOne();
   color = Color(colorBase, colorBase, colorBase);
}

void Particle::initializeDefaultSize() {
   createSizeVariance();
   size += life.birthSize;
}

void Particle::createSizeVariance() {
   size = Utilities::randomZeroToOne() * DEFAULT_SIZE_VARIANCE;
}

void Particle::initializeDefaultPhysics() {
   position = Point3d();
   velocity = Point3d(Utilities::randomNegOneToOne(),
                      Utilities::randomNegOneToOne(),
                      Utilities::randomNegOneToOne());
   force = Point3d(-velocity.x, -velocity.y, -velocity.z);
   mass = DEFAULT_MASS;
}

void Particle::update(float timeElapsed) {
   setTimeElapsed(timeElapsed);
   interpolateLifeTime();
   interpolateSize();
   interpolateColor();
   calculatePhysics();
}

void Particle::setTimeElapsed(float newTimeElapsed) {
   timeElapsed = newTimeElapsed;
} 

void Particle::interpolateLifeTime() {
   life.time -= timeElapsed;
}

void Particle::interpolateSize() {
   size -= ((size - life.deathSize) / life.time) * timeElapsed;
}

void Particle::interpolateColor() {
   color -= ((color - life.deathColor) / life.time) * timeElapsed;
}

void Particle::calculatePhysics() {
   calculateAcceleration();
   calculateVelocity();
   calculatePosition();
}

void Particle::calculateAcceleration() {
   acceleration = force / mass;
}

void Particle::calculateVelocity() {
   velocity = velocity + (acceleration * timeElapsed);
}

void Particle::calculatePosition() {
   position = position + (velocity * timeElapsed + acceleration * PHYSICS_POSITION_CONSTANT * timeElapsed * timeElapsed);
}

bool Particle::isDead() {
   return life.time <= 0;
}

void Particle::draw() {
   glPushMatrix(); {
      glColor3f(color.red, color.green, color.blue);
      glTranslatef(position.x, position.y, position.z);
      glRotatef(rotationDegree, rotationAxis.x, rotationAxis.y, rotationAxis.z);
      glutSolidCube(size);
   } glPopMatrix();
}

void Particle::setRotationAxis(Point3d newRotationAxis) {
   rotationAxis = newRotationAxis;
}

void Particle::setRotationDegree(float newRotationDegree) {
   rotationDegree = newRotationDegree;
}

float Particle::setBirthSize(float newBirthSize) {
   life.birthSize = newBirthSize;
   if (life.birthSize < 0) {
      life.birthSize = 0;
   }
   return life.birthSize;
}

float Particle::setDeathSize(float newDeathSize) {
   life.deathSize = newDeathSize;
   if (life.deathSize < 0) {
      life.deathSize = 0;
   }
   return life.deathSize;
}

Color Particle::setBirthColor(Color newBirthColor) {
   life.birthColor = newBirthColor;
   if (life.birthColor.red > 1) {
      life.birthColor.red = 1;
   }
   if (life.birthColor.red < -1) {
      life.birthColor.red = -1;
   }
   if (life.birthColor.green > 1) {
      life.birthColor.green = 1;
   }
   if (life.birthColor.green < -1) {
      life.birthColor.green = -1;
   }
   if (life.birthColor.blue > 1) {
      life.birthColor.blue = 1;
   }
   if (life.birthColor.blue < -1) {
      life.birthColor.blue = -1;
   }
   return life.birthColor;
}

Color Particle::setDeathColor(Color newDeathColor) {
   life.deathColor = newDeathColor;
   if (life.deathColor.red > 1) {
      life.deathColor.red = 1;
   }
   if (life.deathColor.red < -1) {
      life.deathColor.red = -1;
   }
   if (life.deathColor.green > 1) {
      life.deathColor.green = 1;
   }
   if (life.deathColor.green < -1) {
      life.deathColor.green = -1;
   }
   if (life.deathColor.blue > 1) {
      life.deathColor.blue = 1;
   }
   if (life.deathColor.blue < -1) {
      life.deathColor.blue = -1;
   }
   return life.deathColor;
}

Vector Particle::setVelocity(Vector newVelocity) {
   velocity = newVelocity;
   return velocity;
}

Vector Particle::setAcceleration(Vector newAcceleration) {
   acceleration = newAcceleration;
   return acceleration;
}

Vector Particle::setForce(Vector newForce) {
   force = newForce;
   return force;
}

void Particle::applySettings() {
   initializeDefaultSize();
   initializeColor();
}
