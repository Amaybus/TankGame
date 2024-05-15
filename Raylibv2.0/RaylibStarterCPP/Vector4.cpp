#include "Vector4.h"
using namespace MathClasses;

MathClasses::Vector4::Vector4()
	: x{ 0 }, y{ 0 }, z{ 0 }, w{ 0 }
{
}

MathClasses::Vector4::Vector4(float x, float y, float z, float w)
	:x{ x }, y{ y }, z{ z }, w{ w }
{
}

float MathClasses::Vector4::Dot(const Vector4 rhs)
{
	return x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w;
}

Vector4 MathClasses::Vector4::Cross(const Vector4 rhs) 
{
	Vector4 sum;

	sum.x = (y * rhs.z) - (z * rhs.y);
	sum.y = (z * rhs.x) - (x * rhs.z);
	sum.z = (x * rhs.y) - (y * rhs.x);
	sum.w = (w * rhs.w) - (w * rhs.w);

	return sum;
}

float MathClasses::Vector4::Magnitude()
{
	return sqrtf(x * x + y * y + z * z + w * w);
}

Vector4 MathClasses::Vector4::Normalise()
{
	float magnitude = this->Magnitude();
	if (magnitude == 0)
	{
		return Vector4();
	}
	else
	{
		x = x / magnitude;
		y = y / magnitude;
		z = z / magnitude;
		w = w / magnitude;

		return *this;
	}
}

Vector4 MathClasses::Vector4::Normalised()
{
	Vector4 copy = *this;
	copy.Normalise();

	return copy;
}

std::string MathClasses::Vector4::ToString() const
{
	return std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ", " + std::to_string(w);
}

Vector4 MathClasses::Vector4::operator+(const Vector4 rhs)
{
	Vector4 sum;

	sum.x = x + rhs.x;
	sum.y = y + rhs.y;
	sum.z = z + rhs.z;
	sum.w = w + rhs.w;

	return sum;
}

Vector4 MathClasses::Vector4::operator-(const Vector4 rhs)
{
	Vector4 sum;

	sum.x = x - rhs.x;
	sum.y = y - rhs.y;
	sum.z = z - rhs.z;
	sum.w = w - rhs.w;

	return sum;
}

Vector4 MathClasses::Vector4::operator*(const Vector4 rhs)
{
	Vector4 sum;

	sum.x = x * rhs.x;
	sum.y = y * rhs.y;
	sum.z = z * rhs.z;
	sum.w = w * rhs.w;

	return sum;
}

Vector4 MathClasses::Vector4::operator/(const float divisionNum)
{
	Vector4 sum;

	sum.x = x / divisionNum;
	sum.y = y / divisionNum;
	sum.z = z / divisionNum;
	sum.w = w / divisionNum;

	return sum;
}

bool MathClasses::Vector4::operator==(const Vector4 rhs)
{
	float xDist = fabsf(x - rhs.x);
	float yDist = fabsf(y - rhs.y);
	float zDist = fabsf(z - rhs.z);
	float wDist = fabsf(w - rhs.w);

	const float threshold = 0.00001;

	return xDist < threshold && yDist < threshold && zDist < threshold && wDist < threshold;
}

bool MathClasses::Vector4::operator!=(const Vector4 rhs)
{
	return !(*this == rhs);
}

float& MathClasses::Vector4::operator[](int dim)
{
	return data[dim];
}

const float& MathClasses::Vector4::operator[](const int dim) const
{
	return data[dim];
}

MathClasses::Vector4::operator float* ()
{
	return data;
}

MathClasses::Vector4::operator const float* () const
{
	return data;
}

Vector4 MathClasses::operator*(Vector4 lhsVec, float rhsNum)
{
	Vector4 sum;

	sum.x = lhsVec.x * rhsNum;
	sum.y = lhsVec.y * rhsNum;
	sum.z = lhsVec.z * rhsNum;
	sum.w = lhsVec.w * rhsNum;

	return sum;
}

Vector4 MathClasses::operator*(float lhsNum, Vector4 rhsVec)
{
	Vector4 sum;

	sum.x = lhsNum * rhsVec.x;
	sum.y = lhsNum * rhsVec.y;
	sum.z = lhsNum * rhsVec.z;
	sum.w = lhsNum * rhsVec.w;

	return sum;
}