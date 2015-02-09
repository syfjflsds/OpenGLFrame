//
//  GLVector.cpp
//  HelloOpenGL
//
//  Created by syf on 14/11/28.
//  Copyright (c) 2014年 Zstar Studio. All rights reserved.
//

#include "GLVector.h"

GLVector::GLVector(float x, float y, float z, float w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

GLVector GLVector::operator + (const GLVector &glVector) const
{
    return GLVector(glVector.x + x, glVector.y + y, glVector.z + z, 1);
}

GLVector GLVector::operator - (const GLVector &glVector) const
{
    return GLVector(x - glVector.x, y - glVector.y, z - glVector.z, 1);
}

GLVector GLVector::operator - ()
{
    float outX = -x;
    float outY = -y;
    float outZ = -z;
//    if (outX == -0) {
//        outX = 0;
//    }
//    if (outY == -0) {
//        outY = 0;
//    }
//    if (outZ == -0) {
//        outZ = 0;
//    }
    return GLVector(outX, outY, outZ);
}

float GLVector::dot(const GLVector &glVector) const
{
    return x * glVector.x + y * glVector.y + z * glVector.z;
}

GLVector GLVector::cross(const GLVector &glVector) const
{
    float tempX = y * glVector.z - z * glVector.y;
//    if (tempX == -0) {
//        tempX = 0;
//    }
    float tempY = z * glVector.x - x * glVector.z;
//    if (tempY == -0) {
//        tempY = 0;
//    }
    float tempZ = x * glVector.y - y * glVector.x;
//    if (tempZ == -0) {
//        tempZ = 0;
//    }
    return GLVector(tempX, tempY, tempZ);
    //return GLVector(y * glVector.z - z * glVector.y, z * glVector.x - x * glVector.z, x * glVector.y - y * glVector.x);
}

float GLVector::length() const
{
    return sqrtf(x * x + y * y + z * z);
}

GLVector GLVector::normal() const
{
    float len = length();
    return GLVector(x / len, y / len, z / len);
}

GLVector operator * (const float &number, const GLVector &glVector)
{
    return GLVector(number * glVector.x, number *glVector.y, number *glVector.z);
}

void GLVector::operator+=(const GLVector &glVector)
{
    this->x += glVector.x;
    this->y += glVector.y;
    this->z += glVector.z;
}

void GLVector::operator-=(const GLVector &glVector)
{
    this->x -= glVector.x;
    this->y -= glVector.y;
    this->z -= glVector.z;
}