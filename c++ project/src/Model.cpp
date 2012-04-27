/*
 * Model.cpp
 *
 *  Created on: Feb 23, 2012
 *      Author: Trent Ellingsen
 */

#include "Model.h"

using namespace std;

void Model::setModelFile(char* newFileName) {
	fileName = newFileName;
	init();
}

void Model::update(float timeElapsed) {

}

bool Model::isTriangle(char* test) {
	int numSpaces = 0;

	for (int i = 0; test[i] != '\0'; i++) {
		if (test[i] == ' ') {
			numSpaces++;
		}
	}
	return numSpaces == 3;
}

void Model::init() {
	string modelFileName = fileName;
	ifstream modelFile(modelFileName.c_str());

    if (!modelFile.is_open()) {
    	cerr << "FILE NOT OPEN" << endl;
    	exit(EXIT_FAILURE);
    }

    while (modelFile.good()) {
		string modelLine;
		getline(modelFile, modelLine);
		if (modelLine.c_str()[0] == 'v') {
			float x, y, z;
			sscanf(modelLine.c_str(), "%*c %f %f %f", &x, &y, &z);
			Point3d p = Point3d(x, y, z);
			verticies.push_back(p);
		} else if (modelLine.c_str()[0] == 'f') {
			Face f;
			int v1, v2, v3, v4;
			if (isTriangle((char*) modelLine.c_str())) {
				sscanf(modelLine.c_str(), "%*c %d/%*d/%*d %d/%*d/%*d %d/%*d/%*d", &v1, &v2, &v3);
				v4 = -1;
			} else {
				sscanf(modelLine.c_str(), "%*c %d/%*d/%*d %d/%*d/%*d %d/%*d/%*d %d/%*d/%*d", &v1, &v2, &v3, &v4);
				f.v4 = v4;
			}
			f.v1 = v1;
			f.v2 = v2;
			f.v3 = v3;
			faces.push_back(f);
		}
    }

    modelFile.close();
}

void Model::draw() {
	glPushMatrix(); {
		glColor3f(0.5, 0.5, 0.5);
		glRotatef(90, 0, 1, 0);
		glTranslatef(position.x, position.y, position.z);
		glScalef(2, 2, 2);
		for(int i = 0; i < faces.size(); i++) {
			//glBegin(GL_POLYGON);
			if (faces.at(i).v4 == -1) {
			glBegin(GL_TRIANGLES);
				glVertex3f(verticies.at(faces.at(i).v1 - 1).x, verticies.at(faces.at(i).v1 - 1).y, verticies.at(faces.at(i).v1 - 1).z);
				glVertex3f(verticies.at(faces.at(i).v2 - 1).x, verticies.at(faces.at(i).v2 - 1).y, verticies.at(faces.at(i).v2 - 1).z);
				glVertex3f(verticies.at(faces.at(i).v3 - 1).x, verticies.at(faces.at(i).v3 - 1).y, verticies.at(faces.at(i).v3 - 1).z);
			glEnd();
			} else {
			glBegin(GL_QUADS);
				glVertex3f(verticies.at(faces.at(i).v1 - 1).x, verticies.at(faces.at(i).v1 - 1).y, verticies.at(faces.at(i).v1 - 1).z);
				glVertex3f(verticies.at(faces.at(i).v2 - 1).x, verticies.at(faces.at(i).v2 - 1).y, verticies.at(faces.at(i).v2 - 1).z);
				glVertex3f(verticies.at(faces.at(i).v3 - 1).x, verticies.at(faces.at(i).v3 - 1).y, verticies.at(faces.at(i).v3 - 1).z);
				glVertex3f(verticies.at(faces.at(i).v4 - 1).x, verticies.at(faces.at(i).v4 - 1).y, verticies.at(faces.at(i).v4 - 1).z);
			glEnd();
			}
			//glEnd();
		}
	} glPopMatrix();

    glFlush();
}

Model::Model() {
	setModelFile((char*)"model/sharky/sharky_complete.obj");
}

Model::~Model() {
}
