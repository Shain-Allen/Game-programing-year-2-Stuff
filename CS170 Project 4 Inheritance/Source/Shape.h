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
#pragma once

#include "Point.h"

class Shape
{
public:
	Shape(Point Center_);
	virtual ~Shape();
	const Point GetCenter() const;
	virtual void SetCenter(float x_, float y_);
	virtual void Draw() const = 0;

private:
	Point Center;

protected:
	
};