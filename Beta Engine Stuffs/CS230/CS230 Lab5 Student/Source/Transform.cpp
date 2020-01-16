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

Transform::Transform(float x, float y)
	: translation(x,y), rotation(0), scale(x,y), matrix(CS230::Matrix2D::IdentityMatrix()), isDirty(false)
{
}

Transform::Transform(Beta::Vector2D translation, Beta::Vector2D scale, float rotation)
	: translation(translation), rotation(rotation), scale(scale), matrix(CS230::Matrix2D::IdentityMatrix()), isDirty(false)
{
}

const CS230::Matrix2D& Transform::GetMatrix() const
{
	// TODO: insert return statement here
}

void Transform::SetTranslation(const Beta::Vector2D& translation)
{
}

const Beta::Vector2D& Transform::GetTranslation() const
{
	// TODO: insert return statement here
}

void Transform::SetRotation(float rotation)
{
}

float Transform::GetRotation() const
{
	return 0.0f;
}

void Transform::SetScale(const Beta::Vector2D& scale)
{
}

const Beta::Vector2D& Transform::GetScale() const
{
	// TODO: insert return statement here
}
