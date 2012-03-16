/*
 * Model.h
 *
 *  Created on: Feb 23, 2012
 *      Author: Trent Ellignsen
 */

#ifndef MODEL_H_
#define MODEL_H_

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

#include "Utilities.h"
#include "Object.h"

struct Face {
	int v1, v2, v3, v4;
};

#define SIZE 2

class Model: public Object {
private:
	char* fileName;
	std::vector<Point3d> verticies;
	std::vector<Face> faces;
	void init();
	bool isTriangle(char* modelLine);

public:
	Model();
	virtual ~Model();
	void setModelFile(char* newFileName);
	void draw();
	void update(float timeElapsed);
};

#endif /* MODEL_H_ */
