//------------------------------------------------------------------------------
//
// File Name: Matrix2DStudent.cpp
// Author(s): Shain Allen
// Project: CS230Lab5
// Course: wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#include "stdafx.h"
#include "Matrix2DStudent.h"
namespace CS230
{
	CS230::Matrix2D::Matrix2D()
	{
		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				m[y][x] = 0;
			}
		}
	}

	Matrix2D CS230::Matrix2D::IdentityMatrix()
	{
		Matrix2D identityMatrix;

		identityMatrix.m[0][0] = 1;
		identityMatrix.m[1][1] = 1;
		identityMatrix.m[2][2] = 1;

		return identityMatrix;
	}

	Matrix2D CS230::Matrix2D::Transposed() const
	{
		Matrix2D transposed;

		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				transposed.m[x][y] = m[y][x];
			}
		}

		return transposed;
	}

	Matrix2D CS230::Matrix2D::TranslationMatrix(float x, float y)
	{
		Matrix2D translation = translation.IdentityMatrix();

		translation.m[0][2] = x;
		translation.m[1][2] = y;

		return translation;
	}

	Matrix2D CS230::Matrix2D::ScalingMatrix(float x, float y)
	{
		Matrix2D scaling = scaling.IdentityMatrix();

		scaling.m[0][0] = x;
		scaling.m[1][1] = y;

		return scaling;
	}

	Matrix2D CS230::Matrix2D::RotationMatrixDegrees(float angle)
	{
		Matrix2D rotation = rotation.IdentityMatrix();

		float radian = angle * (M_PI / 180);

		rotation.m[0][0] = cos(radian);
		rotation.m[0][1] = -sin(radian);
		rotation.m[1][0] = sin(radian);
		rotation.m[1][1] = cos(radian);

		return rotation;
	}

	Matrix2D CS230::Matrix2D::RotationMatrixRadians(float angle)
	{
		Matrix2D rotation = rotation.IdentityMatrix();

		rotation.m[0][0] = cos(angle);
		rotation.m[0][1] = -sin(angle);
		rotation.m[1][0] = sin(angle);
		rotation.m[1][1] = cos(angle);

		return rotation;
	}

	Matrix2D CS230::Matrix2D::operator*(const Matrix2D& other) const
	{
		Matrix2D multply;

		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				multply.m[y][x] = m[x][0] * other.m[0][x] + m[x][1] * other.m[1][x] + m[x][2] * other.m[2][x];
			}
		}

		return multply;
	}

	Matrix2D& CS230::Matrix2D::operator*=(const Matrix2D& other)
	{
		// TODO: insert return statement here
	}

	Beta::Vector2D CS230::Matrix2D::operator*(const Beta::Vector2D& vec) const
	{
		return Beta::Vector2D();
	}

	float CS230::Matrix2D::RowColumnMultiply(const Matrix2D& other, unsigned row, unsigned col) const
	{
		return 0.0f;
	}
}