#pragma once
#include "Vector2.h"
#include <cmath>
#include <string>

namespace MathClasses
{
	struct Vector3
	{
	public:
		union
		{
			struct { float x, y, z; };
			float data[3];
		};

		Vector3();
		Vector3(float x, float y, float z);

		float Dot(const Vector3 rhs);
		Vector3 Cross(const Vector3 rhs);
		float Magnitude();
		Vector3 Normalise();
		Vector3 Normalised();

		std::string ToString() const;

		//Operators
		Vector3 operator+(const Vector3 rhs); // Addition
		Vector3 operator-(const Vector3 rhs); // Subtraction
		Vector3 operator*(const Vector3 rhs); // Multiply a float by a Vector
		Vector3 operator/(const float divisionNum); // Division
		Vector3 operator+=(const Vector3 rhs);
		Vector3 operator*=(const Vector3 rhs);

		bool operator==(const Vector3 rhs); // Equal to
		bool operator!=(const Vector3 rhs); // Not equal to

		float& operator[](int dim);
		const float& operator[](const int dim) const;

		operator float* (); //casting
		operator const float* () const;
		operator vec2();
	};

	Vector3 operator*(Vector3 lhsVec, float rhsNum); // Multiplication rhs float
	Vector3 operator*(float lhsNum, Vector3 rhsVec);// Multiplication lhs float

}
using vec3 = MathClasses::Vector3;
