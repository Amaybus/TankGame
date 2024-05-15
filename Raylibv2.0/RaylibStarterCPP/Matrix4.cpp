#include "Matrix4.h"

using namespace MathClasses;

MathClasses::Matrix4::Matrix4()
	: m1{ 0 }, m2{ 0 }, m3{ 0 }, m4{ 0 },
	m5{ 0 }, m6{ 0 }, m7{ 0 }, m8{ 0 },
	m9{ 0 }, m10{ 0 }, m11{ 0 }, m12{ 0 },
	m13{ 0 }, m14{ 0 }, m15{ 0 }, m16{ 0 }
{
}

MathClasses::Matrix4::Matrix4(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9, float m10, float m11, float m12, float m13, float m14, float m15, float m16)
	: m1{ m1 }, m2{ m2 }, m3{ m3 }, m4{ m4 }, m5{ m5 }, m6{ m6 }, m7{ m7 }, m8{ m8 }, m9{ m9 }, m10{ m10 }, m11{ m11 }, m12{ m12 }, m13{ m13 }, m14{ m14 }, m15{ m15 }, m16{ m16 }
{
}

MathClasses::Matrix4::Matrix4(float* v)
	: m1{ v[0] }, m2{ v[1] }, m3{ v[2] }, m4{ v[3] }, m5{ v[4] }, m6{ v[5] }, m7{ v[6] }, m8{ v[7] }, m9{ v[8] }, m10{ v[9]}, m11{ v[10] }, m12{ v[11] }, m13{ v[12]}, m14{ v[13] }, m15{ v[14] }, m16{ v[15] }
{
}

float& MathClasses::Matrix4::operator[](int dim)
{
	return v[dim];
}

const float& MathClasses::Matrix4::operator[](int dim) const
{
	return v[dim];
}

bool MathClasses::Matrix4::operator==(const Matrix4 rhs)
{
	const float threshold = 0.00001;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (fabsf(mm[i][j] - rhs.mm[i][j]) > threshold)
			{
				return false;
			}
		}
	}
	return true;
}

bool MathClasses::Matrix4::operator!=(const Matrix4 rhs)
{
	return !(*this == rhs);
}

Matrix4 MathClasses::Matrix4::MakeIdentity()
{
	return Matrix4(1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);
}

Matrix4 MathClasses::Matrix4::MakeEuler(float pitch, float yaw, float roll)//~~~~~~~~~~~~~~
{
	Matrix4 x = x.MakeRotateX(pitch);
	Matrix4 y = y.MakeRotateY(yaw);
	Matrix4 z = z.MakeRotateZ(roll);

	return Matrix4(z * y * x);
}

Matrix4 MathClasses::Matrix4::MakeEuler(Vector3 eulerRot) //~~~~~~~~~~~~~~
{
	Matrix4 x = x.MakeRotateX(eulerRot.x);
	Matrix4 y = y.MakeRotateY(eulerRot.y);
	Matrix4 z = z.MakeRotateZ(eulerRot.z);

	return Matrix4(z * y * x);
}

std::string MathClasses::Matrix4::ToString() const
{
	std::string str = std::to_string(v[0]);
	for (size_t i = 1; i < 16; i++)
	{
		str += ", " + std::to_string(v[i]);
	}
	return str;
}

Matrix4 MathClasses::Matrix4::operator*(const Matrix4 rhs) const
{
	Matrix4 sum;

	sum.m1 = m1 * rhs.m1 + m5 * rhs.m2 + m9 * rhs.m3 + m13 * rhs.m4;
	sum.m2 = m2 * rhs.m1 + m6 * rhs.m2 + m10 * rhs.m3 + m14 * rhs.m4;
	sum.m3 = m3 * rhs.m1 + m7 * rhs.m2 + m11 * rhs.m3 + m15 * rhs.m4;
	sum.m4 = m4 * rhs.m1 + m8 * rhs.m2 + m12 * rhs.m3 + m16 * rhs.m4;

	sum.m5 = m1 * rhs.m5 + m5 * rhs.m6 + m9 * rhs.m7 + m13 * rhs.m8;
	sum.m6 = m2 * rhs.m5 + m6 * rhs.m6 + m10 * rhs.m7 + m14 * rhs.m8;
	sum.m7 = m3 * rhs.m5 + m7 * rhs.m6 + m11 * rhs.m7 + m15 * rhs.m8;
	sum.m8 = m4 * rhs.m5 + m8 * rhs.m6 + m12 * rhs.m7 + m16 * rhs.m8;

	sum.m9 = m1 * rhs.m9 + m5 * rhs.m10 + m9 * rhs.m11 + m13 * rhs.m12;
	sum.m10 = m2 * rhs.m9 + m6 * rhs.m10 + m10 * rhs.m11 + m14 * rhs.m12;
	sum.m11 = m3 * rhs.m9 + m7 * rhs.m10 + m11 * rhs.m11 + m15 * rhs.m12;
	sum.m12 = m4 * rhs.m9 + m8 * rhs.m10 + m12 * rhs.m11 + m16 * rhs.m12;

	sum.m13 = m1 * rhs.m13 + m5 * rhs.m14 + m9 * rhs.m15 + m13 * rhs.m16;
	sum.m14 = m2 * rhs.m13 + m6 * rhs.m14 + m10 * rhs.m15 + m14 * rhs.m16;
	sum.m15 = m3 * rhs.m13 + m7 * rhs.m14 + m11 * rhs.m15 + m15 * rhs.m16;
	sum.m16 = m4 * rhs.m13 + m8 * rhs.m14 + m12 * rhs.m15 + m16 * rhs.m16;

	return sum;
}

Vector4 MathClasses::Matrix4::operator*(const Vector4 rhs) const
{
	Vector4 sum;

	sum.x = m1 * rhs.x + m5 * rhs.y + m9 * rhs.z + m13 * rhs.w;
	sum.y = m2 * rhs.x + m6 * rhs.y + m10 * rhs.z + m14 * rhs.w;
	sum.z = m3 * rhs.x + m7 * rhs.y + m11 * rhs.z + m15 * rhs.w;
	sum.w = m4 * rhs.x + m8 * rhs.y + m12 * rhs.z + m16 * rhs.w;

	return sum;
}

Matrix4 MathClasses::Matrix4::MakeRotateX(const float rotAmount)
{
	return Matrix4(1, 0, 0, 0,
		0, cos(rotAmount), -sin(rotAmount), 0,
		0, sin(rotAmount), cos(rotAmount), 0,
		0, 0, 0, 1);
}

Matrix4 MathClasses::Matrix4::MakeRotateY(const float rotAmount)
{
	return Matrix4(cos(rotAmount), 0, sin(rotAmount), 0,
		0, 1, 0, 0,
		-sin(rotAmount), 0, cos(rotAmount), 0,
		0, 0, 0, 1);
}

Matrix4 MathClasses::Matrix4::MakeRotateZ(const float rotAmount)
{
	return Matrix4(cos(rotAmount), sin(rotAmount), 0, 0,
		-sin(rotAmount), cos(rotAmount), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);
}

Matrix4 MathClasses::Matrix4::MakeTranslation(float transX, float transY, float transZ)
{
	return Matrix4(1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		transX, transY, transZ, 1);
}

Matrix4 MathClasses::Matrix4::MakeTranslation(Vector3& translate)
{
	return Matrix4(1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		translate.x, translate.y, translate.z, 1);
}

Matrix4 MathClasses::Matrix4::Transposed() const
{
	return Matrix4(m1, m5, m9, m13, m2, m6, m10, m14, m3, m7, m11, m15, m4, m8, m12, m16);
}

Matrix4 MathClasses::Matrix4::MakeScale(float xScale, float yScale, float zScale)
{
	return Matrix4(xScale, 0, 0, 0,
		0, yScale, 0, 0,
		0, 0, zScale, 0,
		0, 0, 0, 1);
}

Matrix4 MathClasses::Matrix4::MakeScale(const Vector3 scale)
{
	return Matrix4(scale.x, 0, 0, 0,
		0, scale.y, 0, 0,
		0, 0, scale.z, 0,
		0, 0, 0, 1);
}

MathClasses::Matrix4::operator float* ()
{
	return v;
}

MathClasses::Matrix4::operator const float* () const
{
	return v;
}

MathClasses::Matrix4::operator Vector4* ()
{
	return axis;
}

MathClasses::Matrix4::operator const Vector4* () const
{
	return axis;
}
