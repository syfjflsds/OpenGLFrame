//
//  GLMatrix.h
//  HelloOpenGL
//
//  Created by syf on 14/11/29.
//  Copyright (c) 2014年 Zstar Studio. All rights reserved.
//

#ifndef __HelloOpenGL__GLMatrix__
#define __HelloOpenGL__GLMatrix__

#include <stdio.h>

class GLMatrix
{
public:
    float **matrix;
    
    GLMatrix();
    GLMatrix(const GLMatrix &);
    virtual ~GLMatrix();
    
    float * & operator [] (int row);
    virtual void showMatrixInfo(); //显示该矩阵存储的矩阵信息
    float *getOneDemonsialnalArray(); //获取矩阵的一维数组
    static void printArray(float *arr); //以矩阵方式打印一维数组
public:
    GLMatrix & operator = (const GLMatrix & matrix);
private:
    float *m_toOneDemensionalArray; //私有一维矩阵信息，只在必要时会赋值(惰性初始化)
};

#endif /* defined(__HelloOpenGL__GLMatrix__) */
