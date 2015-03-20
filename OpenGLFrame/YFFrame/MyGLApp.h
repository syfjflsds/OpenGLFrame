//
//  MyGLApp.h
//  HelloOpenGL
//
//  Created by syf on 14/12/20.
//  Copyright (c) 2014年 Zstar Studio. All rights reserved.
//

#ifndef HelloOpenGL_MyGLApp_h
#define HelloOpenGL_MyGLApp_h
#include "GLFrame.h"

class MyGLApp : public GLFrame
{
public:
    bool setup(int argc, char **argv);
    void render(int delayPerFrame);
private:
	GLuint positionBufferObject;
	GLint program;
	GLfloat change;
	void changeUniformPerFrame();
};

#endif
