//------------------------------------------------------------------------------
//
// File Name:	Polygon.cpp
// Author(s):	Shain Allen
// Project:		CS170 Project 4 Inheritance
// Course:		wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#include "Polygon.h"
#include <iostream>

using std::cout;
using std::endl;

Polygon::Polygon(Point center_, unsigned int number_of_vertices_)
	: Shape_With_Vertices(center_, number_of_vertices_)
{
	vertices = new Point[number_of_vertices_];
}

Polygon::Polygon(Point center_, const Point* vertices_, unsigned int number_of_vertices_)
	: Shape_With_Vertices(center_, number_of_vertices_)
{
	vertices = new Point[number_of_vertices_];

	for (int i = 0; i < number_of_vertices_; i++)
	{
		vertices[i] = vertices_[i];
	}
}

Polygon::~Polygon()
{
	delete[] vertices;
}

void Polygon::SetVertex(unsigned int index_, float x_, float y_)
{
	if (GetNumVertices() > index_)
	{
		vertices[index_].x = x_;
		vertices[index_].y = y_;
	}
}

void Polygon::Draw() const
{
	cout << "Drawing a polygon at x = " << GetCenter().x << " y = " << GetCenter().y << endl;
}
