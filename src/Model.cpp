/*
 * Model.cpp
 *
 *  Created on: Feb 23, 2012
 *      Author: ellingsenp
 */

#include "Model.h"

using namespace std;

void Model::setModelFile(char* newFileName) {
	fileName = newFileName;
	init();
}

void Model::update(float timeElapsed) {

}

void Model::init() {
    vertexCount = 0;
    triangleCount = 0;

    char line[100];

	FILE *fp = fopen(fileName, "r");

    if (fp != NULL) {
        while (fgets(line, 99, fp)) {
              if (line[0] == 'v') {
                  sscanf(line, "%*c %f %f %f", &v[vertexCount].x, &v[vertexCount].y, &v[vertexCount].z);
                  vertexCount++;
              }
              else if (line[0] == 'f') {
                  sscanf(line, "%*c %d %d %d", &t[triangleCount].v1, &t[triangleCount].v2, &t[triangleCount].v3);
                  triangleCount++;
              }
        }
    }

    fclose(fp);
}

/* OBJ Loader written by Kamran */
void Model::draw() {
	glPushMatrix(); {
		glBegin(GL_TRIANGLES); {
			for (int i = 0; i < triangleCount; i++) {
				glVertex3f(v[t[i].v1-1].x * SIZE, v[t[i].v1-1].y * SIZE, v[t[i].v1-1].z * SIZE);
				glVertex3f(v[t[i].v2-1].x * SIZE, v[t[i].v2-1].y * SIZE, v[t[i].v2-1].z * SIZE);
				glVertex3f(v[t[i].v3-1].x * SIZE, v[t[i].v3-1].y * SIZE, v[t[i].v3-1].z * SIZE);
			}
		} glEnd();
	} glPopMatrix();

    glFlush();
}

Model::Model() {
	// TODO Auto-generated constructor stub

}

Model::~Model() {
	// TODO Auto-generated destructor stub
}

