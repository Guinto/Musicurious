#include "Audio.h"

Audio::Audio() {
	totalTime = 0;
	totalTime2 = 0;
	readFile();
}

void Audio::play(string songFileName) {
	const char *fn = songFileName.c_str();

	ap = AudioPlayer::file(fn);

	if(!ap) {
		std::cerr << "Error loading audio" << std::endl;
		exit(EXIT_FAILURE);
	}

	ap->play();
	/*MarSystemManager mng;

	playbacknet = mng.create("Series", "playbacknet");

	playbacknet->addMarSystem(mng.create("SoundFileSource", "src"));
	playbacknet->addMarSystem(mng.create("Gain", "gt"));
	playbacknet->addMarSystem(mng.create("AudioSink", "dest"));

	playbacknet->updControl("SoundFileSource/src/mrs_string/filename", songFileName);
	playbacknet->updControl("Gain/gt/mrs_real/gain", 2.0);
	playbacknet->updControl("AudioSink/dest/mrs_bool/initAudio", true);*/
}

void Audio::update(float timeElapsed) {
	setTimeElapsed(timeElapsed);
	nextLoudness();
	nextPitch();
	/*if (playbacknet->getctrl("SoundFileSource/src/mrs_bool/hasData")->to<mrs_bool>() )
	{
		playbacknet->tick();
	}*/

	   if (ap->isPlaying()) {
	   CFRunLoopRunInMode (                           // 6
	   			kCFRunLoopDefaultMode,                     // 7
	   			0.25,                                      // 8
	   			false                                      // 9
	   		);
	   }
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

float Audio::getAudioLength() {
	return 11.023;
}

float Audio::getLoudnessFileLength() {
	return 995 * 24;
}

float Audio::getPitchFileLength() {
	return 474;
}
