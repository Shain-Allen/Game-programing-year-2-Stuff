//------------------------------------------------------------------------------
//
// File Name:	Shape_With_Vertices.cpp
// Author(s):	Shain Allen
// Project:		CS170 Project 4 Inheritance
// Course:		wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#include "Point.h"
#include "Shape.h"
#include "Shape_With_Vertices.h"

Shape_With_Vertices::Shape_With_Vertices(Point center_, unsigned int number_of_vertices_)
	: Shape(center_), number_of_vertices(number_of_vertices_)
{
	vertices = new Point[number_of_vertices];
}

Shape_With_Vertices::Shape_With_Vertices(const Shape_With_Vertices& other)
	: Shape(other.GetCenter()), number_of_vertices(other.GetNumVertices())
{
	vertices = new Point[number_of_vertices];

	for (unsigned int i = 0; i < number_of_vertices; i++)
	{
		vertices[i] = other.vertices[i];
	}
}

Shape_With_Vertices::~Shape_With_Vertices()
{
	delete[] vertices;
}

void Shape_With_Vertices::SetCenter(float x_, float y_)
{
	for (unsigned int i = 0; i < number_of_vertices; i++)
	{
		vertices[i].x = vertices[i].x + (x_ - GetCenter().x);
		vertices[i].y = vertices[i].y + (y_ - GetCenter().y);
	}
	Shape::SetCenter(x_, y_);
}

unsigned int Shape_With_Vertices::GetNumVertices() const
{
	return number_of_vertices;
}
