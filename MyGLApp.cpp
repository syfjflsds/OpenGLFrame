//
//  MyGLApp.cpp
//  HelloOpenGL
//
//  Created by syf on 14/11/26.
//  Copyright (c) 2014年 Zstar Studio. All rights reserved.
//

#include "MyGLApp.h"

bool MyGLApp::setup(int argc, char **argv)
{
    GLFrame::setup(argc, argv);
    std::vector<GLint> shaderVector;
    int vertexShader = createShaderFromFile("min.vert");
    int fragmentShader = createShaderFromFile("min.frag");
    
    shaderVector.push_back(vertexShader);
    shaderVector.push_back(fragmentShader);
    int program = createProgram(shaderVector);
    
    glClearColor(1.0, 1.0, 1.0, 1.0);
    //glColor3f(0.5, 0.5, 0.5);
    glUseProgram(program);
    
    int location = glGetUniformLocation(program, "colorBase");
    glUniform1f(location, 0.3);
    
    return true;
}

void MyGLApp::render(int delayPerFrame)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glutSolidTeapot(1.0);
    glutSwapBuffers();
    glutPostRedisplay();
}