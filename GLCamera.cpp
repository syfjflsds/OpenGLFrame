//
//  GLcpp
//  HelloOpenGL
//
//  Created by syf on 14/11/28.
//  Copyright (c) 2014年 Zstar Studio. All rights reserved.
//

#include "GLCamera.h"
#include <GLUT/GLUT.h>

GLCamera::GLCamera(GLVector up, GLVector look, GLVector right, GLVector pos) : speed(1)
{
    m_up = up;
    m_look = look;
    m_pos = pos;
    m_right = right;
}

void GLCamera::resetCamera()
{
    GLMatrix matrix = getViewMatrix();
    float *arr = matrix.getOneDemonsialnalArray();
//    GLMatrix::printArray(arr);
    glLoadMatrixf(arr);
}

GLMatrix GLCamera::getViewMatrix()
{
    //首先对三者做正交变换处理，避免精度损失
    m_up = m_up.normal();
    m_right = m_look.cross(m_up);
    m_right = m_right.normal();
    m_look = m_up.cross(m_right);
    m_look = m_look.normal();
    
    /*
     *    生成View矩阵，算法如下(该算法与DirectX的API接口相反，平移的位置Z取了相反的值)
     *
     *    [r.x, u.x, l.x, 0]
     *    [r.y, u.y, l.y, 0]
     *    [r.z, u.z, l.z, 0]
     *    [-p*r, -p*u, p*l, 1] (DirectX中的算法为-p*r, -p*u, -p*l)
     *
    */
    GLMatrix matrix;
    
    matrix[0][0] = m_right.x;
    matrix[0][1] = m_up.x;
    matrix[0][2] = m_look.x;
    matrix[0][3] = 0;
    
    matrix[1][0] = m_right.y;
    matrix[1][1] = m_up.y;
    matrix[1][2] = m_look.y;
    matrix[1][3] = 0;
    
    matrix[2][0] = m_right.z;
    matrix[2][1] = m_up.z;
    matrix[2][2] = m_look.z;
    matrix[2][3] = 0;
    
    matrix[3][0] = -m_pos.dot(m_right);
    matrix[3][1] = -m_pos.dot(m_up);
    matrix[3][2] = m_pos.dot(m_look);
    matrix[3][3] = 1;
    
    return matrix;
}

void GLCamera::moveBack()
{
    m_pos -= speed * m_look;
    resetCamera();
}

void GLCamera::moveForward()
{
    m_pos += speed * m_look;
    resetCamera();
}

void GLCamera::moveLeft()
{
    m_pos -= speed * m_right;
    resetCamera();
}

void GLCamera::moveRight()
{
    m_pos += speed * m_right;
    resetCamera();
}

void GLCamera::moveUp()
{
    m_pos += speed * m_up;
    resetCamera();
}

void GLCamera::moveDown()
{
    m_pos -= speed * m_up;
    resetCamera();
}