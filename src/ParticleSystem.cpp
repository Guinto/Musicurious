#include "ParticleSystem.h"

ParticleSystem::ParticleSystem() {
   initializeParticlesPerSecond();
   initializeParticleProperties();
}

void ParticleSystem::initializeParticlesPerSecond() {
   particlesPerSecond = DEFAULT_PARTICLES_PER_SECOND;
}

void ParticleSystem::initializeParticleProperties() {
   particleProperties.birthSize = DEFAULT_BIRTH_SIZE;
   particleProperties.deathSize = DEFAULT_DEATH_SIZE;
   particleProperties.birthColor = Color(DEFAULT_RED, DEFAULT_GREEN, DEFAULT_BLUE);
   particleProperties.deathColor = Color(DEFAULT_RED, DEFAULT_GREEN, DEFAULT_BLUE);
}

void ParticleSystem::resetSystem() {
   position <= 0;
   initializeParticlesPerSecond();
   initializeParticleProperties();
}

void ParticleSystem::update(float timeElapsed) {
   setTimeElapsed(timeElapsed);
   keyboardActions();
   updateParticles();
   addParticlesToSystem();
}

void ParticleSystem::setTimeElapsed(float newTimeElapsed) {
   timeElapsed = newTimeElapsed;
}

void ParticleSystem::updateParticles() {
   for (unsigned int i = 0; i < particles.size(); i++) {
      Particle *p = (Particle*) particles.get(i);
      p->update(timeElapsed);
      if (p->isDead()) {
         particles.erase(i--);
      }
   }
}

void ParticleSystem::addParticlesToSystem() {
   if (totalTime > (1 / particlesPerSecond)) {
      int particlesToAdd = (int)(particlesPerSecond * totalTime);
      for (unsigned int i = 0; i < particlesToAdd; i++) {
         Particle *p = createCustomParticle();
         particles.add(p);
      }
      totalTime = 0;
   } else {
      totalTime += timeElapsed;
   }
}

Particle* ParticleSystem::createCustomParticle() {
   Particle *p = new Particle();
   p->setPosition(Point3d(position.x, position.y, position.z));
   particleProperties.birthSize = p->setBirthSize(particleProperties.birthSize);
   particleProperties.deathSize = p->setDeathSize(particleProperties.deathSize);
   particleProperties.birthColor = p->setBirthColor(particleProperties.birthColor);
   particleProperties.deathColor = p->setDeathColor(particleProperties.deathColor);
   /*particleProperties.velocity = p->setVelocity(particleProperties.velocity);
   particleProperties.acceration = p->setAcceleration(particleProperties.acceleration);
   particleProperties.force = p->setForce(particleProperties.force);*/
   p->applySettings();
   return p;
}

void ParticleSystem::draw() {
   glPushMatrix(); {
      for (unsigned int i = 0; i < particles.size(); i++) {
         particles.get(i)->draw();
      }
   } glPopMatrix();
}

void ParticleSystem::setKeyboardState(KeyboardState newKeyboardState) {
   keyboardState = newKeyboardState;
}

void ParticleSystem::keyboardActions() {
   if (keyboardState.get('\\')) {
      resetSystem();
   }
   if (keyboardState.get('x')) {
      translatePositiveX();
   }
   if (keyboardState.get('X')) {
      translateNegativeX();
   }
   if (keyboardState.get('y')) {
      translatePositiveY();
   }
   if (keyboardState.get('Y')) {
      translateNegativeY();
   }
   if (keyboardState.get('z')) {
      translatePositiveZ();
   }
   if (keyboardState.get('Z')) {
      translateNegativeZ();
   }
   if (keyboardState.get('a')) {
      increaseParticlesPerSecond();
   }
   if (keyboardState.get('A')) {
      decreaseParticlesPerSecond();
   }
   if (keyboardState.get('s')) {
      increaseBirthSize();
   }
   if (keyboardState.get('S')) {
      decreaseBirthSize();
   }
   if (keyboardState.get('r')) {
      increaseBirthRed();
   }
   if (keyboardState.get('R')) {
      decreaseBirthRed();
   }
   if (keyboardState.get('g')) {
      increaseBirthGreen();
   }
   if (keyboardState.get('G')) {
      decreaseBirthGreen();
   }
   if (keyboardState.get('b')) {
      increaseBirthBlue();
   }
   if (keyboardState.get('B')) {
      decreaseBirthBlue();
   }
   if (keyboardState.get('t')) {
      increaseDeathRed();
   }
   if (keyboardState.get('T')) {
      decreaseDeathRed();
   }
   if (keyboardState.get('h')) {
      increaseDeathGreen();
   }
   if (keyboardState.get('H')) {
      decreaseDeathGreen();
   }
   if (keyboardState.get('n')) {
      increaseDeathBlue();
   }
   if (keyboardState.get('N')) {
      decreaseDeathBlue();
   }
}

void ParticleSystem::translatePositiveX() {
   position.x += CHANGE_IN_TRANSLATION;
}

void ParticleSystem::translateNegativeX() {
   position.x -= CHANGE_IN_TRANSLATION;
}

void ParticleSystem::translatePositiveY() {
   position.y += CHANGE_IN_TRANSLATION;
}

void ParticleSystem::translateNegativeY() {
   position.y -= CHANGE_IN_TRANSLATION;
}

void ParticleSystem::translatePositiveZ() {
   position.z += CHANGE_IN_TRANSLATION;
}

void ParticleSystem::translateNegativeZ() {
   position.z -= CHANGE_IN_TRANSLATION;
}

void ParticleSystem::increaseParticlesPerSecond() {
   particlesPerSecond += CHANGE_IN_PARTICLES_PER_SECOND;
}

void ParticleSystem::decreaseParticlesPerSecond() {
   particlesPerSecond -= CHANGE_IN_PARTICLES_PER_SECOND;
   if (particlesPerSecond < 0) {
      particlesPerSecond = 0;
   }
}

void ParticleSystem::increaseBirthSize() {
   particleProperties.birthSize += CHANGE_IN_SIZE;
}

void ParticleSystem::decreaseBirthSize() {
   particleProperties.birthSize -= CHANGE_IN_SIZE;
}

void ParticleSystem::increaseDeathSize() {
   particleProperties.deathSize += CHANGE_IN_SIZE;
}

void ParticleSystem::decreaseDeathSize() {
   particleProperties.deathSize -= CHANGE_IN_SIZE;
}

void ParticleSystem::increaseBirthRed() {
   particleProperties.birthColor.red += CHANGE_IN_COLOR;
}

void ParticleSystem::decreaseBirthRed() {
   particleProperties.birthColor.red -= CHANGE_IN_COLOR;
}

void ParticleSystem::increaseDeathRed() {
   particleProperties.deathColor.red += CHANGE_IN_COLOR;
}

void ParticleSystem::decreaseDeathRed() {
   particleProperties.deathColor.red -= CHANGE_IN_COLOR;
}

void ParticleSystem::increaseBirthGreen() {
   particleProperties.birthColor.green += CHANGE_IN_COLOR;
}

void ParticleSystem::decreaseBirthGreen() {
   particleProperties.birthColor.green -= CHANGE_IN_COLOR;
}

void ParticleSystem::increaseDeathGreen() {
   particleProperties.deathColor.green += CHANGE_IN_COLOR;
}

void ParticleSystem::decreaseDeathGreen() {
   particleProperties.deathColor.green -= CHANGE_IN_COLOR;
}

void ParticleSystem::increaseBirthBlue() {
   particleProperties.birthColor.blue += CHANGE_IN_COLOR;
}

void ParticleSystem::decreaseBirthBlue() {
   particleProperties.birthColor.blue -= CHANGE_IN_COLOR;
}

void ParticleSystem::increaseDeathBlue() {
   particleProperties.deathColor.blue += CHANGE_IN_COLOR;
}

void ParticleSystem::decreaseDeathBlue() {
   particleProperties.deathColor.blue -= CHANGE_IN_COLOR;
}

