//------------------------------------------------------------------------------
//
// File Name:	Shape.cpp
// Author(s):	Shain Allen
// Project:		CS170 Project 4 Inheritance
// Course:		wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#include "Shape.h"
#include "Point.h"

Shape::Shape(Point Center_)
	: Center(Center_)
{
}

Shape::~Shape()
{
}

const Point Shape::GetCenter() const
{
	return Center;
}

void Shape::SetCenter(float x_, float y_)
{
	Center.x = x_;
	Center.y = y_;
}
