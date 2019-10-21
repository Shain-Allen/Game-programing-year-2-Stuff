#include "Rectangle.h"
//------------------------------------------------------------------------------
//
// File Name:	Rectangle.cpp
// Author(s):	Shain Allen
// Project:		CS170 Project 4 Inheritance
// Course:		wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

Rectangle::Rectangle(Point center_, unsigned int width_, unsigned int height_)
	: Shape_With_Vertices(center_, 4), width(width_), height(height_)
{
}

Rectangle::~Rectangle()
{
}

void Rectangle::SetCenter(float x_, float y_)
{
	Shape_With_Vertices::SetCenter(x_, y_);
}

void Rectangle::Draw() const
{

}
