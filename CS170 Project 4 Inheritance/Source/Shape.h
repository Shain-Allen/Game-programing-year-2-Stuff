//------------------------------------------------------------------------------
//
// File Name:	Shape.h
// Author(s):	Shain Allen
// Project:		CS170 Project 4 Inheritance
// Course:		wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#include "Point.h"

class Shape
{
public:
	Shape(Point Center_);
	virtual ~Shape();
	const Point GetCenter();
	virtual void Draw() = 0;

private:

	Point Center_;

protected:
	void SetCenter(float x_, float y_);
};