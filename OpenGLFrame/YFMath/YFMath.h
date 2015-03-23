#ifndef _YF_MATH_H__
#define _YF_MATH_H__

#include "../YFFrame/GLFrame.h"

namespace YFun
{
	class YFMath
	{
	public:
		static GLMatrix buildPerspectiveProjectionMatrix(float fov, float aspect, float zNear, float zFar);
	};
}

#endif