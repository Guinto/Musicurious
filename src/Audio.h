#ifndef _AUDIO_H_
#define _AUDIO_H_

#include <math.h>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <CoreFoundation/CoreFoundation.h>

#include "AudioPlayer.h"

class Audio {
   private:

      void readFiles();
      void readLoudnessFile();
      void readPitchFile();

      void setLoudness(float newLoudness);
      void setPitch(float newPitch);
      void nextLoudness();
      void nextPitch();
      void setTimeElapsed(float newTimeElapsed);

      float getAudioLength();
      float getPitchFileLength();
      float getLoudnessFileLength();
      char* getSongFileName();

      float timeElapsed;
      float totalTime;
      float totalTime2;
      float loudness;
      float pitch;
      char* songFileName;

      AudioPlayer* ap;

      std::vector<float*> loudList;
      std::vector<float*>::iterator loudit;

      std::vector<float*> pitchList;
      std::vector<float*>::iterator pitchit;


   public:
      Audio();
      ~Audio();
      Audio(char* newSongFileName);
      void play();
      void update(float timeElapsed);
      float getLoudness();
      float getPitch();
};

#endif
