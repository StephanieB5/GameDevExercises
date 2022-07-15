#include "Vector3F.h"
#include "OrionMath.h"  

float Vector3F::Dot(Vector3F const inVector) const
{
	return x * inVector.x + y * inVector.y + z * inVector.z;
}

Vector3F Vector3F::Cross(Vector3F const inVector) const
{
	return Vector3F
	(y * inVector.z - z * inVector.y,
		z * inVector.x - x * inVector.z,
		x * inVector.y - y * inVector.x);
}

float Vector3F::LengthSquared() const
{
	return x * x + y * y + z * z;
}

bool Vector3F::IsEqual(Vector3F const inVector) const
{
	return (OrionMath::IsEqual(x, inVector.x)
		&& OrionMath::IsEqual(y, inVector.y)
		&& OrionMath::IsEqual(z, inVector.z));
	return false;
}

Vector3F Vector3F::operator-(Vector3F const& inVector) const
{
	return Vector3F(x - inVector.x, y - inVector.y, z - inVector.z);
}

bool Vector3F::Normalize()
{
	float const lengthSq = LengthSquared();
	if (lengthSq > OrionMath::epsilon)
	{
		float const length = sqrtf(lengthSq);
		x /= length;
		y /= length;
		z /= length;
		return true;
	}
	return false;
}
