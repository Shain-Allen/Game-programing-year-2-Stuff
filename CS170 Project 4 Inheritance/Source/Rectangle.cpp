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
#include <iostream>

using std::cout;
using std::endl;

Rectangle::Rectangle(Point center_, unsigned int width_, unsigned int height_)
	: Shape_With_Vertices(center_, 4), width(width_), height(height_)
{
}

Rectangle::Rectangle(const Rectangle& rectangle)
	: Shape_With_Vertices(rectangle.GetCenter(), 4), width(rectangle.width), height(rectangle.height)
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
	cout << "Drawing a rectangle at x = " << GetCenter().x << " y = " << GetCenter().y << " with width = " << width << " and height = " << height << endl;
	
	cout << "vector 0 = " << "(" << GetCenter().x - width * 0.5f << ", " << GetCenter().y + height * 0.5f << ")" << endl;
	cout << "vector 1 = " << "(" << GetCenter().x + width * 0.5f << ", " << GetCenter().y + height * 0.5f << ")" << endl;
	cout << "vector 2 = " << "(" << GetCenter().x + width * 0.5f << ", " << GetCenter().y - height * 0.5f << ")" << endl;
	cout << "vector 3 = " << "(" << GetCenter().x - width * 0.5f << ", " << GetCenter().y - height * 0.5f << ")" << endl;
	cout << endl;
}
