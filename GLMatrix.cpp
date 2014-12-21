//
//  GLMatrix.cpp
//  HelloOpenGL
//
//  Created by syf on 14/11/29.
//  Copyright (c) 2014年 Zstar Studio. All rights reserved.
//

#include "GLMatrix.h"
#include <memory.h>
#include <iostream>

GLMatrix::GLMatrix()
{
    matrix = new float *[4];
    for (int i = 0; i < 4; i++) {
        matrix[i] = new float[4];
        memset(matrix[i], 0, 4 * sizeof(float));
    }
    m_toOneDemensionalArray = NULL;
}

GLMatrix::GLMatrix(const GLMatrix &copyMatrix)
{
    matrix = new float *[4];
    for (int i = 0; i < 4; i++) {
        matrix[i] = new float[4];
        for (int j = 0; j < 4; j++) {
            matrix[i][j] = copyMatrix.matrix[i][j];
        }
    }
}

float * & GLMatrix::operator[](int row)
{
    return matrix[row];
}

GLMatrix::~GLMatrix()
{
    for (int i = 0; i < 4; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    if (m_toOneDemensionalArray) {
        delete m_toOneDemensionalArray;
    }
}

GLMatrix &GLMatrix::operator=(const GLMatrix &matrix)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            this->matrix[i][j] = matrix.matrix[i][j];
        }
    }
    return *this;
}

void GLMatrix::showMatrixInfo()
{
    printf("矩阵为\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
        {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
}

float *GLMatrix::getOneDemonsialnalArray()
{
    if (!m_toOneDemensionalArray) {
        m_toOneDemensionalArray = new float[16];
    }
    for (int i = 0; i < 16; i++) {
        m_toOneDemensionalArray[i] = matrix[i / 4][i % 4];
    }
    return m_toOneDemensionalArray;
}

void GLMatrix::printArray(float *arr)
{
    if (arr == 0) {
        return;
    }
    else
    {
        std::cout << "print Array:" << std::endl;
        for (int i = 0; i < 16; i++) {
            std::cout << arr[i] << " ";
            if ((i + 1) % 4 == 0) {
                std::cout << std::endl;
            }
        }
    }
}