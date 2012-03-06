#include "Audio.h"

using namespace std;

Audio::Audio() {
	totalTime = 0;
	totalTime2 = 0;
	readFiles();
}

Audio::Audio(char* newSongFileName) {
	songFileName = newSongFileName;
	ap = AudioPlayer::file(songFileName);
	if (!ap) {
		cerr << "Error loading audio" << endl;
		exit(EXIT_FAILURE);
	}

	totalTime = 0;
	totalTime2 = 0;
	readFiles();
}

Audio::~Audio() {
	delete ap;
}

void Audio::play() {
	if (ap) {
		ap->play();
	} else {
		cerr << "Error playing audio" << endl;
	}
}

void Audio::update(float timeElapsed) {
	setTimeElapsed(timeElapsed);
	nextLoudness();
	nextPitch();
}

void Audio::setTimeElapsed(float newTimeElapsed) {
   timeElapsed = newTimeElapsed;
   totalTime += timeElapsed;
   totalTime2 += timeElapsed;
}

vector<string> getNextLineAndSplitIntoTokens(istream& str);

void Audio::readFiles() {
	readLoudnessFile();
	readPitchFile();
}

void Audio::readLoudnessFile() {
	string loudnessFileName = songFileName;
	ifstream loudnessFile((loudnessFileName + ".lx.csv").c_str());

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

    loudnessFile.close();
    loudit = loudList.begin();
}

void Audio::readPitchFile() {
	string pitchFileName = songFileName;
	ifstream pitchFile((pitchFileName + ".pitch").c_str());

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

    pitchFile.close();
    pitchit = pitchList.begin();
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
	if (use > 1) {
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
	if (use > 1) {
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
	return ap->duration();
}

float Audio::getLoudnessFileLength() {
	return loudList.size();
}

float Audio::getPitchFileLength() {
	return pitchList.size();
}
