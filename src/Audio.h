#ifndef _AUDIO_H_
#define _AUDIO_H_

#include "../lib/marsyas/MarSystemManager.h"
#include <math.h>
#include <string.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
using namespace Marsyas;


using namespace std;

class Audio {
   private:

      MarSystem* playbacknet;
      void readFile();

      void setLoudness(float newLoudness);
      void setPitch(float newPitch);
      void nextLoudness();
      void nextPitch();
      void setTimeElapsed(float newTimeElapsed);

      float getAudioLength();
      float getPitchFileLength();
      float getLoudnessFileLength();

      float timeElapsed;
      float totalTime;
      float totalTime2;
      float loudness;
      float pitch;

      vector<float*> loudList;
      vector<float*>::iterator loudit;

      vector<float*> pitchList;
      vector<float*>::iterator pitchit;

   public:
      Audio();
      void play(string songFileName);
      //void detectPitch();
      void update(float timeElapsed);
      float getLoudness();
      float getPitch();
};

#endif
