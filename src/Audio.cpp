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
}

void Audio::update(float timeElapsed) {
	setTimeElapsed(timeElapsed);
	nextLoudness();
	nextPitch();
	/*if (ap->isPlaying()) {
		CFRunLoopRunInMode (kCFRunLoopDefaultMode, 0.25, false);
	}*/
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
	if (loudit != loudList.end() && use > 1) {
		for (int i = 0; i < use; i++) {
			if (loudit + 1 != loudList.end()) {
				loudit++;
				setLoudness(**loudit);
			}
		}
		totalTime = getAudioLength() * totalTime / getLoudnessFileLength();
	}
}

void Audio::nextPitch() {
	float use = getPitchFileLength() / getAudioLength() * totalTime2;
	if (pitchit != pitchList.end() && use > 1) {
		for (int i = 0; i < use; i++) {
			if (pitchit + 1 != pitchList.end()) {
				pitchit++;
				setPitch(**pitchit);
			}
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
