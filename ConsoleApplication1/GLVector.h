//
//  GLVector.h
//  HelloOpenGL
//
//  Created by syf on 14/11/28.
//  Copyright (c) 2014年 Zstar Studio. All rights reserved.
//

#ifndef __HelloOpenGL__GLVector__
#define __HelloOpenGL__GLVector__

#include <stdio.h>
#include <math.h>

class GLVector
{
public:
    float x, y, z, w;
    
    GLVector(float x = 0, float y = 0, float z = 0, float w = 1.0);
    GLVector operator -(); //重载负向量
    GLVector operator + (const GLVector &glVector) const; //向量相加
    GLVector operator - (const GLVector &glVector) const; //向量相减
    void operator += (const GLVector &glVector); //向量+=操作
    void operator -= (const GLVector &glVector); //向量-=操作
    float dot(const GLVector &glVector) const; //向量点乘
    GLVector cross(const GLVector &glVector) const; //向量叉乘
    float length() const; //获取向量长度
    GLVector normal() const; //返回标准化向量
    friend GLVector operator * (const float &number, const GLVector &glVector);//一个常数乘以向量
};

#endif /* defined(__HelloOpenGL__GLVector__) */
