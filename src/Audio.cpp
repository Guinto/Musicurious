#include "Audio.h"

Audio::Audio() {
	totalTime = 0;
	totalTime2 = 0;
	readFile();
}

void Audio::play(string songFileName) {
	MarSystemManager mng;

	playbacknet = mng.create("Series", "playbacknet");

	playbacknet->addMarSystem(mng.create("SoundFileSource", "src"));
	playbacknet->addMarSystem(mng.create("Gain", "gt"));
	playbacknet->addMarSystem(mng.create("AudioSink", "dest"));

	playbacknet->updControl("SoundFileSource/src/mrs_string/filename", songFileName);
	playbacknet->updControl("Gain/gt/mrs_real/gain", 2.0);
	playbacknet->updControl("AudioSink/dest/mrs_bool/initAudio", true);
}

void Audio::update(float timeElapsed) {
	setTimeElapsed(timeElapsed);
	nextLoudness();
	nextPitch();
	/*if (playbacknet->getctrl("SoundFileSource/src/mrs_bool/hasData")->to<mrs_bool>() )
	{
		playbacknet->tick();
	}*/
   //mainLoop();
}

void Audio::setTimeElapsed(float newTimeElapsed) {
   timeElapsed = newTimeElapsed;
   totalTime += timeElapsed;
   totalTime2 += timeElapsed;
}

vector<string> getNextLineAndSplitIntoTokens(istream& str);

void Audio::readFile() {
    ifstream loudnessFile("audio/test.wav.lx.csv");

    if (!loudnessFile.is_open()) {
    	cerr << "FILE NOT OPEN" << endl;
    	exit(EXIT_FAILURE);
    }

    while (loudnessFile.good()) {
    	vector<string> row = getNextLineAndSplitIntoTokens(loudnessFile);
    	for (int i = 0; i < row.size(); i++) {
    		float *ll = (float*)malloc(sizeof(float));
    		sscanf(row[i].c_str(), "%g", ll);
    		loudList.push_back(ll);
    	}
    }

    loudit = loudList.begin();
    loudnessFile.close();

    ifstream pitchFile("audio/pitch.txt");

    if (!pitchFile.is_open()) {
    	cerr << "FILE NOT OPEN" << endl;
    	exit(EXIT_FAILURE);
    }

    while (pitchFile.good()) {
    	string pitchLine;
    	getline(pitchFile, pitchLine);
    	float *pitchRaw = (float*)malloc(sizeof(float));
    	sscanf(pitchLine.c_str(), "%f", pitchRaw);
    	pitchList.push_back(pitchRaw);
    }

    pitchit = pitchList.begin();
    pitchFile.close();
}

vector<string> getNextLineAndSplitIntoTokens(istream& str) {
	vector<string> result;
	string line;
	getline(str,line);

	stringstream lineStream(line);
	string cell;

	while(getline(lineStream,cell,',')) {
	   result.push_back(cell);
	}
	return result;
}

void Audio::nextLoudness() {
	float use = getLoudnessFileLength() / getAudioLength() * totalTime;
	if (loudit < loudList.end() && use > 1) {
		for (int i = 0; i < use; i++) {
			loudit++;
			setLoudness(**loudit);
		}
		totalTime = getAudioLength() * totalTime / getLoudnessFileLength();
	}
}

void Audio::nextPitch() {
	float use = getPitchFileLength() / getAudioLength() * totalTime2;
	if (pitchit < pitchList.end() && use > 1) {
		for (int i = 0; i < use; i++) {
			pitchit++;
			setPitch(**pitchit);
		}
		totalTime2 = getAudioLength() * totalTime2 / getPitchFileLength();
	}
}

void ERRCHECK(FMOD_RESULT result) {
    if (result != FMOD_OK) {
        printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
        exit(-1);
    }
}

float Audio::getPitch() {
	return pitch;
}

void Audio::setPitch(float newPitch) {
	pitch = newPitch;
}

float Audio::getLoudness() {
   return loudness;
}

void Audio::setLoudness(float newLoudness) {
   loudness = newLoudness;
}

#if 0 // not in use
void Audio::detectPitch() {
	detectPitchWithFMOD();
}

void Audio::detectPitchWithFMOD() {
   initSoundVariables();
   checkGlobalSettings();
   enumeratePlaybackDrivers();
   enumerateRecordDrivers();
   createASoundToRecordTo();
   startTheInterface();
}

void Audio::initSoundVariables() {
   system = 0;
   sound = 0;
   channel = 0;
}

void Audio::checkGlobalSettings() {
   unsigned int version;

   result = FMOD::System_Create(&system);
   ERRCHECK(result);
   
   result = system->getVersion(&version);
   ERRCHECK(result);
   
   if (version < FMOD_VERSION) {
       printf("Error!  You are using an old version of FMOD %08x.  This program requires %08x\n", version, FMOD_VERSION);
       return;
   }
} 

void Audio::enumeratePlaybackDrivers() {
   int numDrivers, driver;

   findPlaybackDrivers(&numDrivers);
   displayPlaybackDriverChoices(numDrivers);
   driver = getPlaybackDriverChoice(numDrivers);
   setPlaybackDriver(driver);
}

void Audio::findPlaybackDrivers(int *numDrivers) {
   int setNumDrivers;

   result = system->getNumDrivers(&setNumDrivers);
   ERRCHECK(result);

   *numDrivers = setNumDrivers;
}

void Audio::displayPlaybackDriverChoices(int numDrivers) {
   int count;

   printf("---------------------------------------------------------\n");    
   printf("Choose a PLAYBACK driver\n");
   printf("---------------------------------------------------------\n");    
   for (count = 0; count < numDrivers; count++) {
      char name[256];
      
      result = system->getDriverInfo(count, name, 256, 0);
      ERRCHECK(result);
      
      printf("%d : %s\n", count + 1, name);
   }
   printf("---------------------------------------------------------\n");
   printf("Press a corresponding number or ESC to quit\n");
}

int Audio::getPlaybackDriverChoice(int numDrivers) {
   int key, driver;
   do {
      key = getch();
      if (key == 27) {
          exit(EXIT_SUCCESS);
      }
      driver = key - '1';
   } while (driver < 0 || driver >= numDrivers);

   return driver;
}

void Audio::setPlaybackDriver(int driver) {
   result = system->setDriver(driver);
   ERRCHECK(result);
}

void Audio::enumerateRecordDrivers() {
   int numDrivers;

   findRecordDrivers(&numDrivers);
   displayRecordingDriverChoices(numDrivers);
   getRecordingDriverChoice(numDrivers);  
   setRecordFormat();
}

void Audio::findRecordDrivers(int *numDrivers) {
   int setNumDrivers;

   result = system->getRecordNumDrivers(&setNumDrivers);
   ERRCHECK(result);

   *numDrivers = setNumDrivers;
} 

void Audio::displayRecordingDriverChoices(int numDrivers) {
   int count;
   printf("---------------------------------------------------------\n");    
   printf("Choose a RECORD driver\n");
   printf("---------------------------------------------------------\n");    
   for (count = 0; count < numDrivers; count++) {
       char name[256];
       
       result = system->getRecordDriverInfo(count, name, 256, 0);
       ERRCHECK(result);
       
       printf("%d : %s\n", count + 1, name);
   }
   printf("---------------------------------------------------------\n");
   printf("Press a corresponding number or ESC to quit\n\n");
}

void Audio::getRecordingDriverChoice(int numDrivers) {
   int key;

   recordDriver = 0;
   do {
      key = getch();
      if (key == 27) {
          return;
      }
      recordDriver = key - '1';
   } while (recordDriver < 0 || recordDriver >= numDrivers);
}

void Audio::setRecordFormat() {
   int outputfreq;
   result = system->setSoftwareFormat(OUTPUTRATE, FMOD_SOUND_FORMAT_PCM16, 2, 0, FMOD_DSP_RESAMPLER_LINEAR);
   ERRCHECK(result);
  
   result = system->init(32, FMOD_INIT_NORMAL, 0);
   ERRCHECK(result);
   
   system->getSoftwareFormat(&outputfreq, 0, 0, 0, 0, 0);
   ERRCHECK(result);
}

void Audio::createASoundToRecordTo() {
   bool isCoreAudio = false;
   FMOD_CREATESOUNDEXINFO exinfo;

   memset(&exinfo, 0, sizeof(FMOD_CREATESOUNDEXINFO));
   
   exinfo.cbsize           = sizeof(FMOD_CREATESOUNDEXINFO);
   exinfo.numchannels      = 2;
   exinfo.defaultfrequency = OUTPUTRATE;
   if (isCoreAudio) {
      exinfo.format = FMOD_SOUND_FORMAT_PCMFLOAT;
      exinfo.length = exinfo.defaultfrequency * sizeof(float) * exinfo.numchannels * 5;
   } else {
      exinfo.format = FMOD_SOUND_FORMAT_PCM16;
      exinfo.length = exinfo.defaultfrequency * sizeof(short) * exinfo.numchannels * 5;
   }
    
   result = system->createSound(0, FMOD_2D | FMOD_SOFTWARE | FMOD_LOOP_NORMAL | FMOD_OPENUSER, &exinfo, &sound);
   ERRCHECK(result);
} 

void Audio::startTheInterface() {
   printf("=========================================================================\n");
   printf("Pitch detection example.  Copyright (c) Firelight Technologies 2004-2011.\n");
   printf("=========================================================================\n");
   printf("\n");
   printf("Record something through the selected recording device and FMOD will\n");
   printf("Determine the pitch.  Sustain the tone for at least a second to get an\n");
   printf("accurate reading.\n");
   printf("Press 'Esc' to quit\n");
   printf("\n");
   
   result = system->recordStart(recordDriver, sound, true);
   ERRCHECK(result);
   
   //Sleep(200); /* Give it some time to record something */
   
   result = system->playSound(FMOD_CHANNEL_REUSE, sound, false, &channel);
   ERRCHECK(result);
   
   /* Dont hear what is being recorded otherwise it will feedback.  Spectrum analysis is done before volume scaling in the DSP chain */
   result = channel->setVolume(0);
   ERRCHECK(result);
} 

void Audio::mainLoop() {
   int count, key;
   int bin = 0;

   static float spectrum[SPECTRUMSIZE];
   float        dominanthz = 0;
   float        max;
   int          dominantnote = 0;
        
   if (kbhit()) {
      key = getch();
   }
      
   result = channel->getSpectrum(spectrum, SPECTRUMSIZE, 0, FMOD_DSP_FFT_WINDOW_TRIANGLE);
   ERRCHECK(result);
       
   max = 0;
       
   for (count = 0; count < SPECTRUMSIZE; count++) {
      if (spectrum[count] > 0.01f && spectrum[count] > max) {
         max = spectrum[count];
         bin = count;
      }
   }        
        
   dominanthz  = (float)bin * BINSIZE;       /* dominant frequency min */
        
   dominantnote = 0;
   for (count = 0; count < 120; count++) {
      if (dominanthz >= notefreq[count] && dominanthz < notefreq[count + 1]) {
         /* which is it closer to.  This note or the next note */
         if (fabs(dominanthz - notefreq[count]) < fabs(dominanthz - notefreq[count+1])) {
            dominantnote = count;
         } else {
            dominantnote = count + 1;
         }
         break;
      }
   }

   setLoudness(dominanthz);
        
   printf("\rDetected rate : %7.1f -> %7.1f hz.  Detected musical note. %-3s (%7.1f hz)", dominanthz, ((float)bin + 0.99f) * BINSIZE, note[dominantnote], notefreq[dominantnote]);
   fflush(stdout);
        
   system->update();
        
   //Sleep(10);
}

void Audio::shutDown() {
   result = sound->release();
   ERRCHECK(result);
   
   result = system->release();
   ERRCHECK(result);
}
#endif

float Audio::getAudioLength() {
	return 11.023;
}

float Audio::getLoudnessFileLength() {
	return 995 * 24;
}

float Audio::getPitchFileLength() {
	return 474;
}
