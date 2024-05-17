#pragma once

#include <string>

namespace MathClasses
{
	struct Vector2
	{
	public:
		union
		{
			struct { float x, y; };
			float data[2];
		};

		Vector2();
		Vector2(float x, float y);

		std::string ToString() const;

		//Operators
		Vector2 operator+(const Vector2 rhs); // Addition
		Vector2 operator-(const Vector2 rhs); // Subtraction
		Vector2 operator*(const Vector2 rhs); // Multiply a float by a Vector
		Vector2 operator/(const float divisionNum); // Division
		Vector2 operator+=(const Vector2 rhs);
		Vector2 operator*=(const Vector2 rhs);

		bool operator==(const Vector2 rhs); // Equal to
		bool operator!=(const Vector2 rhs); // Not equal to

		float& operator[](int dim);
		const float& operator[](const int dim) const;

		float Min(float a, float b) const;
		Vector2 Min(Vector2 lhs, Vector2 rhs);
		float Max(float a, float b) const;
		Vector2 Max(Vector2 lhs, Vector2 rhs);

		float Clamp(float t, float a, float b);
		Vector2 Clamp(Vector2& t, Vector2& a, Vector2& b);

		float DistanceTo(Vector2 rhs);
		float Cross(Vector2 rhs);
		Vector2 Normalise();
		Vector2 Normalised();
		float Magnitude();
		float Dot(Vector2 rhs);
		float MagnitudeSqr();
	};

	Vector2 operator*(Vector2 lhsVec, float rhsNum); // Multiplication rhs float
	Vector2 operator*(float lhsNum, Vector2 rhsVec);// Multiplication lhs float

}
using vec2 = MathClasses::Vector2;
