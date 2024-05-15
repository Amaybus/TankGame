#include "Matrix3.h"

using namespace MathClasses;

MathClasses::Matrix3::Matrix3()
	: m1{ 0 }, m2{ 0 }, m3{ 0 }, m4{ 0 }, m5{ 0 }, m6{ 0 }, m7{ 0 }, m8{ 0 }, m9{ 0 }
{

}

MathClasses::Matrix3::Matrix3(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9)
	: m1{ m1 }, m2{ m2 }, m3{ m3 }, m4{ m4 }, m5{ m5 }, m6{ m6 }, m7{ m7 }, m8{ m8 }, m9{ m9 }
{
}

MathClasses::Matrix3::Matrix3(float* v)
	: m1{v[0]}, m2{v[1]}, m3{ v[2] }, m4{ v[3] }, m5{ v[4] }, m6{ v[5] }, m7{ v[6] }, m8{ v[7] }, m9{ v[8] }
{
}

Matrix3 MathClasses::Matrix3::MakeIdentity()
{
	return Matrix3(1, 0, 0,
		0, 1, 0,
		0, 0, 1);
}

Matrix3 MathClasses::Matrix3::MakeEuler(float pitch, float yaw, float roll)
{
	Matrix3 x = x.MakeRotateX(pitch);
	Matrix3 y = y.MakeRotateY(yaw);
	Matrix3 z = z.MakeRotateZ(roll);

	return Matrix3(z * y * x);
}

Matrix3 MathClasses::Matrix3::MakeEuler(Vector3 eulerRot)
{
	Matrix3 x = x.MakeRotateX(eulerRot.x);
	Matrix3 y = y.MakeRotateY(eulerRot.y);
	Matrix3 z = z.MakeRotateZ(eulerRot.z);

	return Matrix3(z * y * x);
}

std::string MathClasses::Matrix3::ToString() const
{
	std::string str = std::to_string(v[0]);
	for (size_t i = 1; i < 9; i++)
	{
		str += ", " + std::to_string(v[i]);
	}
	return str;
}

float& MathClasses::Matrix3::operator[](int dim)
{
	return v[dim];
}

const float& MathClasses::Matrix3::operator[](int dim) const
{
	return v[dim];
}

bool MathClasses::Matrix3::operator==(const Matrix3 rhs) const
{
	const float threshold = 0.00001;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (fabsf(mm[i][j] - rhs.mm[i][j]) > threshold)
			{
				return false;
			}
		}
	}
	return true;
}

bool MathClasses::Matrix3::operator!=(const Matrix3 rhs) const
{
	return !(*this == rhs);
}

Matrix3 MathClasses::Matrix3::MakeRotateX(float rotAmount)
{
	return Matrix3(1, 0, 0,
		0, cos(rotAmount), -sin(rotAmount),
		0, sin(rotAmount), cos(rotAmount));
}

Matrix3 MathClasses::Matrix3::MakeRotateY(float rotAmount)
{
	return Matrix3(cos(rotAmount), 0, sin(rotAmount),
		0, 1, 0,
		-sin(rotAmount), 0, cos(rotAmount));
}

Matrix3 MathClasses::Matrix3::MakeRotateZ(float rotAmount)
{
	return Matrix3(cos(rotAmount), sin(rotAmount), 0,
		-sin(rotAmount), cos(rotAmount), 0,
		0, 0, 1);
}

Matrix3 MathClasses::Matrix3::MakeTranslation2D(float x, float y)
{
	return Matrix3(1, 0, 0,
				   0, 1, 0,
				   x, y, 1);
}

Matrix3 MathClasses::Matrix3::MakeTranslation(const float transX, const float transY, const float transZ)
{
	return Matrix3(1, 0, 0,
		0, 1, 0,
		transX, transY, transZ);
}

Matrix3 MathClasses::Matrix3::MakeTranslation(Vector3 translate)
{
	return Matrix3(1, 0, 0,
		0, 1, 0,
		translate.x, translate.y, translate.z);
}

Matrix3 MathClasses::Matrix3::Transposed() const
{
	return Matrix3(m1, m4, m7, m2, m5, m8, m3, m6, m9);
}

Matrix3 MathClasses::Matrix3::MakeScale(float xScale, float yScale)
{
	return Matrix3(xScale, 0, 0,
		0, yScale, 0,
		0, 0, 1);
}

Matrix3 MathClasses::Matrix3::MakeScale(float xScale, float yScale, float zScale)
{
	return Matrix3(xScale, 0, 0,
		0, yScale, 0,
		0, 0, zScale);
}

Matrix3 MathClasses::Matrix3::MakeScale(Vector3 scale)
{
	return Matrix3(scale.x, 0, 0,
		0, scale.y, 0,
		0, 0, scale.z);
}

MathClasses::Matrix3::operator float* ()
{
	return v;
}

MathClasses::Matrix3::operator const float* () const
{
	return v;
}

MathClasses::Matrix3::operator Vector3* ()
{
	return axis;
}

MathClasses::Matrix3::operator const Vector3* () const
{
	return axis;
}

Matrix3 MathClasses::operator*(Matrix3 lhs, Matrix3 rhs)
{
	Matrix3 sum;
	sum.m1 = lhs.m1 * rhs.m1 + lhs.m4 * rhs.m2 + lhs.m7 * rhs.m3;
	sum.m2 = lhs.m2 * rhs.m1 + lhs.m5 * rhs.m2 + lhs.m8 * rhs.m3;
	sum.m3 = lhs.m3 * rhs.m1 + lhs.m6 * rhs.m2 + lhs.m9 * rhs.m3;

	sum.m4 = lhs.m1 * rhs.m4 + lhs.m4 * rhs.m5 + lhs.m7 * rhs.m6;
	sum.m5 = lhs.m2 * rhs.m4 + lhs.m5 * rhs.m5 + lhs.m8 * rhs.m6;
	sum.m6 = lhs.m3 * rhs.m4 + lhs.m6 * rhs.m5 + lhs.m9 * rhs.m6;

	sum.m7 = lhs.m1 * rhs.m7 + lhs.m4 * rhs.m8 + lhs.m7 * rhs.m9;
	sum.m8 = lhs.m2 * rhs.m7 + lhs.m5 * rhs.m8 + lhs.m8 * rhs.m9;
	sum.m9 = lhs.m3 * rhs.m7 + lhs.m6 * rhs.m8 + lhs.m9 * rhs.m9;

	return sum;
}

Vector3 MathClasses::operator*(Matrix3 lhs, Vector3 rhs)
{
	Vector3 sum;

	sum.x = lhs.m1 * rhs.x + lhs.m4 * rhs.y + lhs.m7 * rhs.z;
	sum.y = lhs.m2 * rhs.x + lhs.m5 * rhs.y + lhs.m8 * rhs.z;
	sum.z = lhs.m3 * rhs.x + lhs.m6 * rhs.y + lhs.m9 * rhs.z;

	return sum;
}
