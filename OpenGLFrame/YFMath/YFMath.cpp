#include "YFMath.h"
#include <cmath>

using namespace YFun;

/*
*		º∆À„Õ∂”∞æÿ’Û
*
*	[cot¶» / Aspect, 0, 0, 0]	 
*	[0, cot¶» , 0, 0]
*	[0, 0, far / (far - near), 1]
*   [0, 0, far * near / (near - far), 0]
*
*/
GLMatrix YFMath::buildPerspectiveProjectionMatrix(float fov, float aspect, float zNear, float zFar)
{
	GLMatrix matrix;
	memset(&matrix, 0, sizeof(matrix));
	matrix[0][0] = 1 / (tan(fov * 0.5f) * aspect); //cot¶» / aspect = 1 / (tan¶» * aspect) 
	matrix[1][1] = 1 / (tan(fov * 0.5f));
	matrix[2][2] = zFar / (zFar - zNear);
	matrix[2][3] = 1.0f;
	matrix[3][2] = (zNear * zFar) / (zNear - zFar);

	return matrix;
}