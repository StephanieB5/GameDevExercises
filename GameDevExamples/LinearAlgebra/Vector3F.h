#pragma once

class Vector3F
{
public:
	float x;
	float y; 
	float z;

	Vector3F() = default;  // needed because another constructor is defined

	Vector3F(float const inX, float const inY, float const inZ)
		: x(inX),
		y(inY),
		z(inZ)
	{}


	float Dot(Vector3F const inVector) const;
	Vector3F Cross(Vector3F const inVector) const;
	float LengthSquared() const;
	bool IsEqual(Vector3F const inVector) const;

	Vector3F operator-(Vector3F const& p_v) const;

	bool Normalize();
};
