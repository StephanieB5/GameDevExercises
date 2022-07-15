#pragma once
#include "Vector3F.h"

class Vector4F
{
public:
	float elements[4];

	Vector4F()
	{
		for (int i = 0; i < 4; i++)
		{
			elements[i] = 0.f;
		}
	}

	Vector4F(Vector3F inVector, float const inW)
	{
		elements[0] = inVector.x;
		elements[1] = inVector.y;
		elements[2] = inVector.z;
		elements[3] = inW;
	}

	Vector3F MakeVector3F() const
	{
		return Vector3F(elements[0], elements[1], elements[2]);
	}
};

