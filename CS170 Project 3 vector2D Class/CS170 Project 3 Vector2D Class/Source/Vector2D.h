//------------------------------------------------------------------------------
//
// File Name:	Vector2D.h
// Author(s):	Shain Allen
// Project:		project 3
// Course:		wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////
#ifndef VECTOR2D_H
#define VECTOR2D_H
////////////////////////////////////////////////////////////////////////////////

#include <iostream> // istream, ostream

namespace CS170
{
	class Vector2D
	{
	public:
		// Constructors (2)
		Vector2D(float x, float y);
		Vector2D();
		
		// Accessors (2)
		float X() const;
		float Y() const;
		
		// Mutators (2)
		void X(float x);
		void Y(float y);
		
		// Other functions (7)
		Vector2D Midpoint(const Vector2D& pt2);
		float Distance(const Vector2D& pt2);
		float DistanceSquared(const Vector2D& pt2);
		float Magnitude();
		float MagnitudeSquared();
		Vector2D Normalized();

		// Overloaded operators (9 member functions)
		Vector2D operator+(const Vector2D& pt2);
		Vector2D operator-(const Vector2D& pt2);
		
	private:
		float x; // The x-coordinate of a Vector2D
		float y; // The y-coordinate of a Vector2D
	};
  
	// Overloaded operators (2 non-member, non-friend functions)
	std::ostream& operator<<(std::ostream& os, const Vector2D& vector2D);

} // namespace CS170

#endif
////////////////////////////////////////////////////////////////////////////////
