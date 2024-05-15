#include "Vector3.h"

using namespace MathClasses;

MathClasses::Vector3::Vector3()
	: x{ 0 }, y{ 0 }, z{ 0 }
{

}

MathClasses::Vector3::Vector3(float x, float y, float z)
	: x{ x }, y{ y }, z{ z }
{

}

Vector3 MathClasses::Vector3::operator+(const Vector3 rhs)
{
	Vector3 sum;

	sum.x = x + rhs.x;
	sum.y = y + rhs.y;
	sum.z = z + rhs.z;

	return sum;
}

Vector3 MathClasses::Vector3::operator-(const Vector3 rhs)
{
	Vector3 sum;

	sum.x = x - rhs.x;
	sum.y = y - rhs.y;
	sum.z = z - rhs.z;

	return sum;
}

Vector3 MathClasses::Vector3::operator*(const Vector3 rhs)
{
	Vector3 sum;

	sum.x = x * rhs.x;
	sum.y = y * rhs.y;
	sum.z = z * rhs.z;

	return sum;
}

Vector3 MathClasses::Vector3::operator/(const float divisionNum)
{
	Vector3 sum;

	sum.x = x / divisionNum;
	sum.y = y / divisionNum;
	sum.z = z / divisionNum;

	return sum;
}

Vector3 MathClasses::Vector3::operator+=(const Vector3 rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;
	return *this;
}

Vector3 MathClasses::Vector3::operator*=(const Vector3 rhs)
{
	this->x *= rhs.x;
	this->y *= rhs.y;
	this->z *= rhs.z;
	return *this;
}

float MathClasses::Vector3::Dot(const Vector3 rhs)
{
	return x * rhs.x + y * rhs.y + z * rhs.z;
}

Vector3 MathClasses::Vector3::Cross(const Vector3 rhs)
{
	Vector3 sum;

	sum.x = y * rhs.z - z * rhs.y;
	sum.y = z * rhs.x - x * rhs.z;
	sum.z = x * rhs.y - y * rhs.x;

	return sum;
}

float MathClasses::Vector3::Magnitude()
{
	return sqrtf(x * x + y * y + z * z);
}

Vector3 MathClasses::Vector3::Normalise()
{
	float magnitude = this->Magnitude();
	if (magnitude == 0)
	{
		return Vector3();
	}
	else 
	{
		x = x / magnitude;
		y = y / magnitude;
		z = z / magnitude;

		return *this;
	}
}

Vector3 MathClasses::Vector3::Normalised()
{
	Vector3 copy = *this;
	copy.Normalise();

	return copy;
}

std::string MathClasses::Vector3::ToString() const
{
	return std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z);
}

bool MathClasses::Vector3::operator==(const Vector3 rhs)
{
	float xDist = fabsf(x - rhs.x);
	float yDist = fabsf(y - rhs.y);
	float zDist = fabsf(z - rhs.z);

	const float threshold = 0.00001f;

	return xDist < threshold && yDist < threshold && zDist < threshold;
}

bool MathClasses::Vector3::operator!=(const Vector3 rhs)
{
	return !(*this == rhs);
}

float& MathClasses::Vector3::operator[](int dim)
{
	return data[dim];
}

const float& MathClasses::Vector3::operator[](const int dim) const
{
	return data[dim];
}

MathClasses::Vector3::operator float* ()
{
	return data;
}

MathClasses::Vector3::operator const float* () const
{
	return data;
}

Vector3 MathClasses::operator*(Vector3 lhsVec, float rhsNum)
{
	Vector3 sum;

	sum.x = lhsVec.x * rhsNum;
	sum.y = lhsVec.y * rhsNum;
	sum.z = lhsVec.z * rhsNum;

	return sum;
}

Vector3 MathClasses::operator*(float lhsNum, Vector3 rhsVec)
{
	Vector3 sum;

	sum.x = lhsNum * rhsVec.x;
	sum.y = lhsNum * rhsVec.y;
	sum.z = lhsNum * rhsVec.z;

	return sum;
}