//------------------------------------------------------------------------------
//
// File Name: Transform.cpp
// Author(s): Shain Allen
// Project: CS230Lab5
// Course: wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#include "stdafx.h"
#include "Transform.h"
#include "Matrix2DStudent.h"

using namespace Beta;

Transform::Transform(float x, float y)
	: Component("Transform"), translation(x,y), rotation(0), scale(1,1), matrix(CS230::Matrix2D::IdentityMatrix()), isDirty(true)
{
}

Transform::Transform(Beta::Vector2D translation, Beta::Vector2D scale, float rotation)
	: Component("Transform"), translation(translation), rotation(rotation), scale(scale), matrix(CS230::Matrix2D::IdentityMatrix()), isDirty(true)
{
}

Component* Transform::Clone() const
{
	return new Transform(*this);
}

const CS230::Matrix2D& Transform::GetMatrix() const
{
	using CS230::Matrix2D;

	CalculateMatrices();
	
	return matrix;
}

const CS230::Matrix2D& Transform::GetInverseMatrix() const
{
	using CS230::Matrix2D;

	CalculateMatrices();

	return inverseMatrix;
}

void Transform::SetTranslation(const Beta::Vector2D& translation_)
{
	if (AlmostEqual(translation, translation_))
		return;
	isDirty = true;
	translation = translation_;
}

void Transform::SetTranslationX(float X_)
{
	if (AlmostEqual(translation.x, X_))
		return;
	isDirty = true;
	translation.x = X_;
}

void Transform::SetTranslationY(float Y_)
{
	if (AlmostEqual(translation.y, Y_))
		return;
	isDirty = true;
	translation.y = Y_;
}

const Beta::Vector2D& Transform::GetTranslation() const
{
	return translation;
}

void Transform::SetRotation(float rotation_)
{
	if (rotation == rotation_)
		return;
	isDirty = true;
	rotation = rotation_;
}

float Transform::GetRotation() const
{
	return rotation;
}

void Transform::SetScale(const Beta::Vector2D& scale_)
{
	if (AlmostEqual(scale, scale_))
		return;
	isDirty = true;
	scale = scale_;
}

const Beta::Vector2D& Transform::GetScale() const
{
	return scale;
}

void Transform::CalculateMatrices() const
{
	using CS230::Matrix2D;
	if (isDirty)
	{
		Matrix2D transMat = transMat.TranslationMatrix(translation.x, translation.y);
		Matrix2D rotMat = rotMat.RotationMatrixDegrees(rotation);
		Matrix2D sf = sf.ScalingMatrix(scale.x, scale.y);

		matrix = transMat * rotMat * sf;

		transMat = transMat.TranslationMatrix(-translation.x,
			-translation.y);
		rotMat = rotMat.RotationMatrixDegrees(-rotation);
		sf = sf.ScalingMatrix(1 / scale.x, 1 / scale.y);

		inverseMatrix = sf * rotMat * transMat;

		isDirty = false;
	}
}

