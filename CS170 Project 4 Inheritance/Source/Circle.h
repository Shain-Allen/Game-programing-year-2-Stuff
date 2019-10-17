//------------------------------------------------------------------------------
//
// File Name:	Circle.h
// Author(s):	Shain Allen
// Project:		CS170 Project 4 Inheritance
// Course:		wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#pragma once

#include "Shape.h"
#include "Point.h"

class Circle : public Shape
{
public:
	Circle(Point center_, unsigned int radius_);
	~Circle();
	void SetCenter(float x_, float y_);
	void Draw() const;

private:
	unsigned int radius;
};