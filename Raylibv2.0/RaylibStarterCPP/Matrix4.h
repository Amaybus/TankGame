#pragma once

#include "Vector4.h"
#include "Vector3.h"

#include <cmath>
#include <string>

namespace MathClasses
{
	struct Matrix4
	{
	public:
		union
		{
			struct { float m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16; };

			// 1D array
			float v[16];

			// 2D array
			float mm[4][4];

			// as Vector3
			Vector4 axis[4];
		};

		Matrix4();
		Matrix4(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9, float m10, float m11, float m12, float m13, float m14, float m15, float m16);
		Matrix4(float* v);

		float& operator[] (int dim);
		const float& operator[] (int dim) const;

		bool operator==(const Matrix4 rhs);
		bool operator!=(const Matrix4 rhs);

		static Matrix4 MakeIdentity();
		static Matrix4 MakeEuler(float pitch, float yaw, float roll);
		static Matrix4 MakeEuler(Vector3 eulerRot);
		std::string ToString() const;

		Matrix4 operator*(const Matrix4 rhs) const;
		Vector4 operator*(const Vector4 rhs) const;

		static Matrix4 MakeRotateX(float rotAmount);
		static Matrix4 MakeRotateY(float rotAmount);
		static Matrix4 MakeRotateZ(float rotAmount);
		static Matrix4 MakeTranslation(float transX, float transY, float transZ);
		static Matrix4 MakeTranslation(Vector3& translate);
		Matrix4 Transposed() const;
		static Matrix4 MakeScale(float xScale, float yScale, float zScale);
		static Matrix4 MakeScale(const Vector3 scale);

		//casting
		operator float* ();
		operator const float* () const;
		operator Vector4* ();
		operator const Vector4* () const;
	};
}