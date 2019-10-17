//------------------------------------------------------------------------------
//
// File Name:	Shape_With_Vertices.h
// Author(s):	Shain Allen
// Project:		CS170 Project 4 Inheritance
// Course:		wanic GP2
//
// Copyright � 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#include "Point.h"
#include "Shape.h"

class Shape_With_Vertices : public Shape
{
public:
	Shape_With_Vertices(Point center_, unsigned int number_of_vertices);
	virtual ~Shape_With_Vertices();
	

private:
	Point* vertices; 
	unsigned int number_of_vertices;

protected:
	void SetCenter(float x_, float y_);
};