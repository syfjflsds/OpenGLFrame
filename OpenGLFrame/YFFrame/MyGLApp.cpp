//
//  MyGLApp.cpp
//  HelloOpenGL
//
//  Created by syf on 14/11/26.
//  Copyright (c) 2014年 Zstar Studio. All rights reserved.
//

#include "MyGLApp.h"
#include "../YFLogger/YFLogger.h"
#include "../YFMath/YFMath.h"

using namespace YFun;

bool MyGLApp::setup(int argc, char **argv)
{
	YFLogger::getInstance().init(argv[0]);
	//YFLogger::getInstance()->init(argv[0]);
	GLFrame::setup(argc, argv);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CW);
	camera.speed = 0.1f;
	change = 0;
	float vertexPosition[] = 
	{
		0.75f, 0.75f, 0.0f, 1.0f,
		0.75f, -0.75f, 0.0f, 1.0f,
		-0.75f, -0.75f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
	};
	// Initialise the vertex position
	glGenBuffers(1, &positionBufferObject);	
	glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPosition), vertexPosition, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);


	std::vector<GLint> shaderVector;
	int vertexShader = createShaderFromFile("min.vert");
	int fragmentShader = createShaderFromFile("min.frag");

	shaderVector.push_back(vertexShader);
	shaderVector.push_back(fragmentShader);
	program = createProgram(shaderVector);

	//auto perspectiveProjectionMatrix = YFMath::buildPerspectiveProjectionMatrix(1.0, 800 / 640, 1.0, 1000.0);
	//perspectiveProjectionMatrix = perspectiveProjectionMatrix * camera.getViewMatrix();

	glClearColor(1.0, 1.0, 1.0, 1.0);
	return true;

}


void MyGLApp::changeUniformPerFrame()
{
	change += 0.01;
	if(change >= 1.0)
	{
		change = 0.0;
	}
	GLuint uniformLocation = glGetUniformLocation(program, "offset");
	glUniform2f(uniformLocation, change, 0.0);
}

void MyGLApp::render(int delayPerFrame)
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glUseProgram(program);	
	auto modelViewProjectionMatrix = camera.getViewMatrix();
	auto oneDemonsinalMatrixArray = modelViewProjectionMatrix.getOneDemonsialnalArray();
	GLuint loc = glGetUniformLocation(program, "modelViewProjectionMatrix");
	glUniformMatrix4fv(loc, 1, GL_FALSE, oneDemonsinalMatrixArray);
	glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject);
	glEnableVertexAttribArray(0);
	//glEnableVertexAttribArray(1);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	loc = glGetAttribLocation(program, "color");
	glEnableVertexAttribArray(loc);
	glVertexAttribPointer(loc, 4, GL_FLOAT, GL_FALSE, 0, (void *)48);

	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);
	glUseProgram(0);

	//glutSolidTeapot(1.0);
	glutSwapBuffers();
	glutPostRedisplay();
}