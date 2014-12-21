//
//  GLFrame.h
//  HelloOpenGL
//
//  Created by syf on 14/11/26.
//  Copyright (c) 2014年 Zstar Studio. All rights reserved.
//

#ifndef __HelloOpenGL__GLFrame__
#define __HelloOpenGL__GLFrame__

#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#include <string.h>
#include <vector>
#include "GLCamera.h"

class GLFrame
{
public:
    virtual bool setup(int argc, char **argv); //设置需要的OpenGL
    virtual void run(); //进入消息循环，运行
    char *textFileRead(const char *fileName); //从文件当中读取text(该方法会返回一个申请的空间，用完记得delete)
    GLint createShader(GLenum shaderType, const char *shaderSourceStr);//从文字中创建shader
    GLint createShaderFromFile(const char *fileName);
    GLint createProgram(std::vector<GLint> shaderList);
    void printMatrix(GLint model = GL_MODELVIEW_MATRIX);
protected:
    virtual void render(int delayPerFrame); //具体渲染代码，虚函数，可被子类修改
private:
    void setupGlut(int argc, char **argv);
    static void staticDisplay();
    static void staticKeyFun(unsigned char key, int x, int y);
    static void mouseMoveFun(int button, int state, int x, int y);
    static GLFrame *m_renderObject;
public:
    GLCamera camera;
};

#endif /* defined(__HelloOpenGL__GLFrame__) */
