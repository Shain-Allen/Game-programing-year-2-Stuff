//------------------------------------------------------------------------------
//
// File Name:	Shape_With_Vertices.h
// Author(s):	Shain Allen
// Project:		CS170 Project 4 Inheritance
// Course:		wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#pragma once
#include "Point.h"
#include "Shape.h"

class Shape_With_Vertices : public Shape
{
public:
	Shape_With_Vertices(Point center_, unsigned int number_of_vertices_);
	Shape_With_Vertices(const Shape_With_Vertices& other);
	virtual ~Shape_With_Vertices();
	virtual void SetCenter(float x_, float y_);
	virtual void Draw() const = 0;
	unsigned int GetNumVertices() const;
	
private: 
	unsigned int number_of_vertices;

protected:
	Point* vertices;
};