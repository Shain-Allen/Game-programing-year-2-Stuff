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
	float Vector2D::X() const
	{
		return x;
	}

	float Vector2D::Y() const
	{
		return y;
	}

	// Mutators (2)
	void Vector2D::X(float x_)
	{
		x = x_;
	}

	void Vector2D::Y(float y_)
	{
		y = y_;
	}


	// Other functions (7)
	Vector2D Vector2D::Midpoint(const Vector2D& pt2)
	{
		Vector2D midpoint;

		midpoint.x = (x + pt2.x) / 2;
		midpoint.y = (y + pt2.y) / 2;

		return midpoint;
	}

	float Vector2D::Distance(const Vector2D& pt2)
	{
		return sqrt(DistanceSquared(pt2));
	}

	float Vector2D::DistanceSquared(const Vector2D& pt2)
	{
		return ((pt2.x - x) * (pt2.x - x) + (pt2.y - y) * (pt2.y - y));
	}

	float Vector2D::Magnitude()
	{
		return sqrt(MagnitudeSquared());
	}

	float Vector2D::MagnitudeSquared()
	{
		return ((x*x) + (y*y));
	}

	float Vector2D::DotProduct(const Vector2D& pt2)
	{
		return (x * pt2.x) + (y * pt2.y);
	}

	Vector2D Vector2D::Normalized()
	{
		Vector2D normalized;

		normalized.x = (x / Magnitude());
		normalized.y = (y / Magnitude());

		return normalized;
	}
	
	// Operators (9)
	Vector2D Vector2D::operator+(const Vector2D& pt2) const
	{
		Vector2D pt3;

		pt3.x = x + pt2.x;
		pt3.y = y + pt2.y;

		return pt3;
	}

	Vector2D Vector2D::operator-(const Vector2D& pt2) const
	{
		Vector2D pt3;

		pt3.x = x - pt2.x;
		pt3.y = y - pt2.y;

		return pt3;
	}

	Vector2D Vector2D::operator*(float scaler) const
	{
		Vector2D output;

		output.x = x * scaler;
		output.y = y * scaler;

		return output;
	}

	Vector2D Vector2D::operator/(float scaler) const
	{
		Vector2D output;

		output.x = x / scaler;
		output.y = y / scaler;

		return output;
	}

	Vector2D& Vector2D::operator+=(const Vector2D& pt2)
	{
		x += pt2.x;
		y += pt2.y;

		return *this;
	}

	Vector2D& Vector2D::operator-=(const Vector2D& pt2)
	{
		x -= pt2.x;
		y -= pt2.y;

		return *this;
	}

	Vector2D& Vector2D::operator*=(const float E)
	{
		x *= E;
		y *= E;
		return *this;
	}

	Vector2D& Vector2D::operator/=(const float E)
	{
		x /= E;
		y /= E;
		return *this;
	}

	Vector2D Vector2D::operator-()
	{
		Vector2D negitive;

		negitive.x = -x;
		negitive.y = -y;

		return negitive;
	}

	///////////////////////////////////////////////////////////////////////////////
	// 2 non-member, non-friend functions (operators)
	std::ostream& operator<<(std::ostream& os, const Vector2D& vector2D)
	{
		return os << '(' << vector2D.X() << ',' << vector2D.Y() << ')';
	}

	Vector2D operator*(const float scaler, const Vector2D& vector2D)
	{
		Vector2D output;

		output.X(scaler * vector2D.X());
		output.Y(scaler * vector2D.Y());

		return output;
	}

} // namespace CS170



