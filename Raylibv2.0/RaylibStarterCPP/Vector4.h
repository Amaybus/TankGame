#pragma once

#include <cmath>
#include <string>

namespace MathClasses
{
	struct Vector4
	{
	public:
		union
		{
			struct { float x, y, z, w; };
			float data[4];
		};

		Vector4();
		Vector4(float x, float y, float z, float w);

		float Dot(const Vector4 rhs);
		Vector4 Cross(const Vector4 rhs);
		float Magnitude();
		Vector4 Normalise();
		Vector4 Normalised();

		std::string ToString() const;

		//Operators
		Vector4 operator+(const Vector4 rhs); // Addition
		Vector4 operator-(const Vector4 rhs); // Subtraction
		Vector4 operator*(const Vector4 rhs); // Multiply a float by Vec4
		Vector4 operator/(const float divisionNum); // Division

		bool operator==(const Vector4 rhs); // Equal To
		bool operator!=(const Vector4 rhs); // Not Equal to

		float& operator[](int dim);
		const float& operator[](const int dim) const;

		operator float* (); //casting
		operator const float* () const;
	};

	Vector4 operator*(Vector4 lhsVec, float rhsNum); // Multiplication rhs float
	Vector4 operator*(float lhsNum, Vector4 rhsVec);// Multiplication lhs float
}