//------------------------------------------------------------------------------
//
// File Name:	Vector2D.cpp
// Author(s):	Shain Allen
// Project:		project 3
// Course:		wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#include "Vector2D.h"  // Vector2D members
#include <cmath>    // sqrt, atan, sin, cos

namespace CS170
{

///////////////////////////////////////////////////////////////////////////////
// 22 public member functions (2 constructors, 2 accessors, 2 mutators, 7 others, 9 operators) 

// Constructors (2)
Vector2D::Vector2D(float x_, float y_)
  : x(x_), y(y_)
{
}

//default Constructor
Vector2D::Vector2D()
	: x(0), y(0)
{
}

// Accessors (2)
float Vector2D::X()
{
	return x;
}

float Vector2D::Y()
{
	return y;
}

// Mutators (2)
float Vector2D::X(float x_)
{
	return x = x_;
}

float Vector2D::Y(float y_)
{
	return y = y_;
}

// Other functions (7)


// Operators (9)


///////////////////////////////////////////////////////////////////////////////
// 2 non-member, non-friend functions (operators)
std::ostream& operator<<(std::ostream& os, const Vector2D& vector2D)
{
	os << '(' << vector2D.X << ',' << vector2D.Y << ')';
}

} // namespace CS170



