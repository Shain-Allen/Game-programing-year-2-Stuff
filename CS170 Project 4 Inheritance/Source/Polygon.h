//------------------------------------------------------------------------------
//
// File Name:	Polygon.h
// Author(s):	Shain Allen
// Project:		CS170 Project 4 Inheritance
// Course:		wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#pragma once
#include "Shape_With_Vertices.h"

class Polygon : public Shape_With_Vertices
{
public:
	Polygon(Point center_, unsigned int number_of_vertices_);
	Polygon(Point center_, const Point* vertices_, unsigned int number_of_vertices_);
	void SetVertex(unsigned int index_, float x_, float y_);
	void Draw() const;

private:
};