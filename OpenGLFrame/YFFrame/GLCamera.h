//
//  GLCamera.h
//  HelloOpenGL
//
//  Created by syf on 14/11/28.
//  Copyright (c) 2014年 Zstar Studio. All rights reserved.
//

#ifndef __HelloOpenGL__GLCamera__
#define __HelloOpenGL__GLCamera__

#include <stdio.h>
#include "GLVector.h"
#include "GLMatrix.h"

class GLCamera
{
public:
    GLCamera(GLVector up = GLVector(0, 1, 0), GLVector look = GLVector(0, 0, -1), GLVector right = GLVector(1, 0, 0), GLVector pos = GLVector(0, 0, 1.0));
    void resetCamera(); //重置摄像机，即重设ModelViewMatrix
    GLMatrix getViewMatrix(); //获取摄像机的Matrix
    void moveForward(); //向前
    void moveBack(); //向后
    void moveLeft(); //向左
    void moveRight(); //向右
    void moveUp(); //向上
    void moveDown(); //向下
public:
    GLVector m_up;
    GLVector m_look;
    GLVector m_pos;
    GLVector m_right;
    float speed;
    
};

#endif /* defined(__HelloOpenGL__GLCamera__) */
