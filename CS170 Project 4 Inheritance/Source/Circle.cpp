#include "Circle.h"
//------------------------------------------------------------------------------
//
// File Name:	Circle.cpp
// Author(s):	Shain Allen
// Project:		CS170 Project 4 Inheritance
// Course:		wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#include "Point.h"
#include "Shape.h"
#include <iostream>

using std::cout;
using std::endl;

Circle::Circle(Point center_, unsigned int radius_)
	: Shape(center_), radius(radius_)
{
}

Circle::~Circle()
{
}

void Circle::Draw() const
{
	cout << "Drawing a circle at x = " << GetCenter().x << " y = " << GetCenter().y << " and radius " << radius << endl;
}

void Circle::SetCenter(float x_, float y_)
{
	Shape::SetCenter(x_, y_);
}
