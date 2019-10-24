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
}

Polygon::Polygon(Point center_, const Point* vertices_, unsigned int number_of_vertices_)
	: Shape_With_Vertices(center_, number_of_vertices_)
{
	for (unsigned int i = 0; i < number_of_vertices_; i++)
	{
		vertices[i].x = vertices_[i].x + GetCenter().x;
		vertices[i].y = vertices_[i].y + GetCenter().y;
	}
}

void Polygon::SetVertex(unsigned int index_, float x_, float y_)
{
	if (index_ >= GetNumVertices())
	{
		cout << "Bad vertex index provided" << endl;
	}
	if (index_ < GetNumVertices())
	{
		vertices[index_].x = x_ + GetCenter().x;
		vertices[index_].y = y_ + GetCenter().y;
	}
}

void Polygon::Draw() const
{
	cout << "Drawing a polygon at x = " << GetCenter().x << " y = " << GetCenter().y << endl;
	for (unsigned int i = 0; i < GetNumVertices(); i++)
	{
		cout << "Vertex " << i << " (" << vertices[i].x << ", " << vertices[i].y << ")" << endl;
	}
	cout << endl;
}
