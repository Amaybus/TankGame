#pragma once

#include  "Vector3.h"

#include <cmath>
#include <string>

namespace MathClasses
{
	struct Matrix3
	{
	public:
		union
		{
			struct { float m1, m2, m3, m4, m5, m6, m7, m8, m9; };

			// 1D array
			float v[9];

			// 2D array
			float mm[3][3];

			// as Vector3
			Vector3 axis[3];
		};

		Matrix3();
		Matrix3(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9);
		Matrix3(float* v);

		static Matrix3 MakeIdentity();
		static Matrix3 MakeEuler(float pitch, float yaw, float roll);
		static Matrix3 MakeEuler(Vector3 eulerRot); 
		std::string ToString() const;

		float& operator[] (int dim);
		const float& operator[] (int dim) const;

		bool operator==(const Matrix3 rhs) const;
		bool operator!=(const Matrix3 rhs) const;

		static Matrix3 MakeRotateX(float rotAmount);
		static Matrix3 MakeRotateY(float rotAmount);
		static Matrix3 MakeRotateZ(float rotAmount);
		static Matrix3 MakeTranslation2D(float x, float y);
		static Matrix3 MakeTranslation(float transX, float transY, float transZ); 
		static Matrix3 MakeTranslation(Vector3 translate); 
		Matrix3 Transposed() const;
		static Matrix3 MakeScale(float xScale, float yScale);
		static Matrix3 MakeScale(float xScale, float yScale, float zScale);
		static Matrix3 MakeScale(Vector3 scale);

		//casting
		operator float* ();
		operator const float* () const;
		operator Vector3* ();
		operator const Vector3* () const;
	};
	Matrix3 operator*(Matrix3 lhs, Matrix3 rhs);
	Vector3 operator*(Matrix3 lhs, Vector3 rhs);
}