#pragma once
#include <array>
#include "Vector4F.h"

class Matrix
{
public:
	static int constexpr size = 4;  // Hard coded for this example
	float elements[size][size];

	void clearToZero();

	void VectorMultiply(Vector4F const& inVector, Vector4F& result) const;
	void Multiply(Matrix const& inMatrix, Matrix& result) const;
};

