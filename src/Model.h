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
#include "Utilities.h"
#include "Object.h"

struct Triangle {
       int v1;
       int v2;
       int v3;
};

struct Vertex {
      float x;
      float y;
      float z;
};

#define SIZE 0.25

class Model: public Object {
private:
	char* fileName;
	Vertex v[50000];
	Triangle t[50000];
	int vertexCount;
	int triangleCount;
	void init();

public:
	Model();
	virtual ~Model();
	void setModelFile(char* newFileName);
	void draw();
	void update(float timeElapsed);
};

#endif /* MODEL_H_ */
