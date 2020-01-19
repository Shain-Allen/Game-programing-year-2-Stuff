//------------------------------------------------------------------------------
//
// File Name: Transform.cpp
// Author(s): Shain Allen
// Project: CS230Lab5
// Course: wanic GP2
//
// Copyright � 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#include "stdafx.h"
#include "Transform.h"
#include "Matrix2DStudent.h"

Transform::Transform(float x, float y)
	: translation(x,y), rotation(0), scale(1,1), matrix(CS230::Matrix2D::IdentityMatrix()), isDirty(false)
{
}

Transform::Transform(Beta::Vector2D translation, Beta::Vector2D scale, float rotation)
	: translation(translation), rotation(rotation), scale(scale), matrix(CS230::Matrix2D::IdentityMatrix()), isDirty(false)
{
}

const CS230::Matrix2D& Transform::GetMatrix() const
{
	using CS230::Matrix2D;

	if (isDirty)
	{
		Matrix2D transMat = transMat.TranslationMatrix(translation.x, translation.y);
		Matrix2D rotMat = rotMat.RotationMatrixDegrees(rotation);
		Matrix2D sf = sf.ScalingMatrix(scale.x, scale.y);

		matrix = transMat * rotMat * sf;

		isDirty = false;
	}
	return matrix;
}

void Transform::SetTranslation(const Beta::Vector2D& translation_)
{
	translation = translation_;
}

const Beta::Vector2D& Transform::GetTranslation() const
{
	return translation;
}

void Transform::SetRotation(float rotation_)
{
	rotation = rotation_;
}

float Transform::GetRotation() const
{
	return rotation;
}

void Transform::SetScale(const Beta::Vector2D& scale_)
{
	scale = scale_;
}

const Beta::Vector2D& Transform::GetScale() const
{
	return scale;
}
