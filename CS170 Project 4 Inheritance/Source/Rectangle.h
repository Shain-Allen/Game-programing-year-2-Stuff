//------------------------------------------------------------------------------
//
// File Name:	Rectangle.h
// Author(s):	Shain Allen
// Project:		CS170 Project 4 Inheritance
// Course:		wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#pragma once
#include "Shape_With_Vertices.h"

class Rectangle : public Shape_With_Vertices
{
public:
	Rectangle(Point center_, unsigned int width_, unsigned int height_);
	Rectangle(const Rectangle& rectangle);
	~Rectangle();
	void SetCenter(float x_, float y_);
	void Draw() const;

private:

	unsigned int width;
	unsigned int height;
};