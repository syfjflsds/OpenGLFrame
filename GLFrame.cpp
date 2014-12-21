//
//  GLFrame.cpp
//  HelloOpenGL
//
//  Created by syf on 14/11/26.
//  Copyright (c) 2014年 Zstar Studio. All rights reserved.
//

#include "GLFrame.h"
#ifdef WIN32

#else

#endif

#include <iostream>

GLFrame *GLFrame::m_renderObject = NULL;

void GLFrame::staticDisplay()
{
    if (m_renderObject) {
        m_renderObject->render(0);
    }
}

void GLFrame::render(int delayPerFrame)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

bool GLFrame::setup(int argc, char **argv)
{
    setupGlut(argc, argv);
    m_renderObject = this;
    
    //设置投影矩阵和摄像机位置
    glPushMatrix();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0f, (float)800 / (float)640, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    //gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
    //printMatrix();
    camera.resetCamera();
    return true;
}

void GLFrame::setupGlut(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 640);
    
    glutCreateWindow("OpenGL Main Window");
    glutDisplayFunc(staticDisplay);
    glutKeyboardFunc(staticKeyFun);
}

void GLFrame::run()
{
    glutMainLoop();
}

char *GLFrame::textFileRead(const char *fileName)
{
    FILE *fp;
    char *content = NULL;
    int count = 0;
    
    if (fileName != NULL) {
        fp = fopen(fileName, "r");
        if (fp != nullptr) {
            fseek(fp, 0, SEEK_END);
            count = ftell(fp);
            rewind(fp);
            if (count > 0) {
                content = new char[count + 1];
                count = fread(content, sizeof(char), count, fp);
                content[count] = '\0';
            }
            fclose(fp);
        }
    }
    return content;
}

GLint GLFrame::createShader(GLenum shaderType, const GLchar *shaderSourceStr)
{
    int shader = glCreateShader(shaderType);
    int statusMark;
    glShaderSource(shader, 1, &shaderSourceStr, nullptr);
    glCompileShader(shader);
    glGetShaderiv(shader, GL_COMPILE_STATUS, &statusMark);
    if (!statusMark) {
        GLint infoLogLength;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);
        
        GLchar *strInfoLog = new GLchar[infoLogLength + 1];
        glGetShaderInfoLog(shader, infoLogLength, NULL, strInfoLog);
        fprintf(stderr, "%s", strInfoLog);
        delete[] strInfoLog;
    }
    return shader;
}

GLint GLFrame::createShaderFromFile(const char *fileName)
{
    int length = strlen(fileName);
    int i;
    for (i = 0; i < length; i++) {
        if (fileName[i] == '.') {
            break;
        }
    }
    if (i == length) {
        return 0;
    }
    char buf[10];
    int start = 0;
    for (i++; i < length; i++) {
        buf[start++] = fileName[i];
    }
    buf[i] = '\0';
    GLenum shaderType;
    if (strcmp(buf, "vert") == 0) {
        shaderType = GL_VERTEX_SHADER;
    }
    else
    {
        shaderType = GL_FRAGMENT_SHADER;
    }
    
    char *shaderSourceStr = textFileRead(fileName);
    int shader;
    shader = createShader(shaderType, shaderSourceStr);
    delete[] shaderSourceStr;
    return shader;
}

GLint GLFrame::createProgram(std::vector<GLint> shaderList)
{
    GLint program = glCreateProgram();
    
    for (std::vector<GLint>::iterator i = shaderList.begin(); i != shaderList.end(); i++) {
        glAttachShader(program, *i);
    }
    
    glLinkProgram(program);
    int statusMark;
    glGetProgramiv(program, GL_LINK_STATUS, &statusMark);
    if (!statusMark) {
        GLint infoLogLength;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);
        
        GLchar *strInfoLog = new GLchar[infoLogLength + 1];
        glGetProgramInfoLog(program, infoLogLength, NULL, strInfoLog);
        fprintf(stderr, "%s", strInfoLog);
        delete[] strInfoLog;
    }
    return program;
}

void GLFrame::staticKeyFun(unsigned char key, int x, int y)
{
    if (key == 'w') { //向前移动
        m_renderObject->camera.moveForward();
    }
    if (key == 's') { //向后移动
        m_renderObject->camera.moveBack();
    }
    if (key == 'a') {
        m_renderObject->camera.moveLeft();
    }
    if (key == 'd') {
        m_renderObject->camera.moveRight();
    }
    if (key == 'i') {
        m_renderObject->camera.moveUp();
    }
    if (key == 'k') {
        m_renderObject->camera.moveDown();
    }
}

void GLFrame::printMatrix(GLint model)
{
    if (model == GL_MODELVIEW_MATRIX || model == GL_PROJECTION_MATRIX) {
        float matrix[16];
        glGetFloatv(model, matrix);
        std::cout << "print Matrix:" << std::endl;
        for (int i = 0; i < 16; i++) {
            std::cout << matrix[i] << " ";
            if ((i+1) % 4 == 0) {
                std::cout << std::endl;
            }
        }
    }
    else
    {
        std::cout << "没有输入正确的Matrix Model" << std::endl;
    }
}