#include "Vector2.h"

using namespace MathClasses;

MathClasses::Vector2::Vector2()
	: x{ 0 }, y{ 0 }
{
}

MathClasses::Vector2::Vector2(float x, float y)
	: x{ x }, y{ y }
{
}

std::string MathClasses::Vector2::ToString() const
{
	return std::to_string(x) + ", " + std::to_string(y);
}

Vector2 MathClasses::Vector2::operator+(const Vector2 rhs) 
{
	Vector2 sum;

	sum.x = x + rhs.x;
	sum.y = y + rhs.y;

	return sum;
}

Vector2 MathClasses::Vector2::operator-(const Vector2 rhs)
{
	Vector2 sum;

	sum.x = x - rhs.x;
	sum.y = y - rhs.y;

	return sum;
}

Vector2 MathClasses::Vector2::operator*(const Vector2 rhs)
{
	Vector2 sum;

	sum.x = x * rhs.x;
	sum.y = y * rhs.y;

	return sum;
}

Vector2 MathClasses::Vector2::operator/(const float divisionNum)
{
	Vector2 sum;

	sum.x = x / divisionNum;
	sum.y = y / divisionNum;

	return sum;
}

Vector2 MathClasses::Vector2::operator+=(const Vector2 rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	return *this;
}

Vector2 MathClasses::Vector2::operator*=(const Vector2 rhs)
{
	this->x *= rhs.x;
	this->y *= rhs.y;
	return *this;
}

bool MathClasses::Vector2::operator==(const Vector2 rhs)
{
	float xDist = fabsf(x - rhs.x);
	float yDist = fabsf(y - rhs.y);

	const float threshold = 0.00001f;

	return xDist < threshold && yDist < threshold;
}

bool MathClasses::Vector2::operator!=(const Vector2 rhs)
{
	return !(*this == rhs);
}

float& MathClasses::Vector2::operator[](int dim)
{
	return data[dim];
}

const float& MathClasses::Vector2::operator[](const int dim) const
{
	return data[dim];
}

float MathClasses::Vector2::Min(float a, float b) const
{
	return a < b ? a : b;
}

Vector2 MathClasses::Vector2::Min(Vector2 lhs, Vector2 rhs)
{
	return { Min(lhs.x,rhs.x), Min(lhs.y,rhs.y) };
}

float MathClasses::Vector2::Max(float a, float b) const
{
	return a > b ? a : b;
}

Vector2 MathClasses::Vector2::Max(Vector2 lhs, Vector2 rhs)
{
	return { Max(lhs.x, rhs.x), Max(lhs.y,rhs.y) };
}

Vector2 MathClasses::Vector2::Clamp(Vector2& t, Vector2& a, Vector2& b)
{
	return Max(a, Min(b, t));
}

float MathClasses::Vector2::DistanceTo(Vector2 rhs)
{
	Vector2 sum = rhs - *this ;
	sum.Normalise();
	return 0.0f;
}

float MathClasses::Vector2::Cross(Vector2 rhs)
{
	return x * rhs.x + y * rhs.y;
}

Vector2 MathClasses::Vector2::Normalise()
{
	float magnitude = this->Magnitude();
	if (magnitude == 0)
	{
		return Vector2();
	}
	else
	{
		x = x / magnitude;
		y = y / magnitude;

		return *this;
	}
}

Vector2 MathClasses::Vector2::Normalised()
{
	Vector2 copy = *this;
	copy.Normalise();

	return copy;
}

float MathClasses::Vector2::Magnitude()
{
	return sqrtf(x * x + y * y);
}

float MathClasses::Vector2::Dot(Vector2 rhs)
{
	return x * rhs.x + y * rhs.y;
}

float MathClasses::Vector2::MagnitudeSqr()
{
	return x * x + y * y;
}

float MathClasses::Vector2::Clamp(float t, float a, float b)
{
	return Max(a, Min(b, t));
}

Vector2 MathClasses::operator*(Vector2 lhsVec, float rhsNum)
{
	Vector2 sum;

	sum.x = lhsVec.x * rhsNum;
	sum.y = lhsVec.y * rhsNum;

	return sum;
}

Vector2 MathClasses::operator*(float lhsNum, Vector2 rhsVec)
{
	Vector2 sum;

	sum.x = lhsNum * rhsVec.x;
	sum.y = lhsNum * rhsVec.y;

	return sum;
}

