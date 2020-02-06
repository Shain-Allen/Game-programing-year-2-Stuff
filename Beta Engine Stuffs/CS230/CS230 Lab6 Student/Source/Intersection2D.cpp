#include "stdafx.h"
#include "Intersection2D.h"

bool PointCircleIntersection(const Beta::Vector2D& point, const Beta::Circle& circle)
{
	if (point.DistanceSquared(circle.center) > (circle.radius * circle.radius))
		return false;
	else
		return true;
}

bool PointRectangleIntersection(const Beta::Vector2D& point, const Beta::BoundingRectangle& rect)
{
	if (point.x < rect.left)
		return false;
	else if (point.x > rect.right)
		return false;
	else if (point.y > rect.top)
		return false;
	else if (point.y < rect.bottom)
		return false;
	else
		return true;
}

bool CircleCircleIntersection(const Beta::Circle& circle1, const Beta::Circle& circle2)
{
	if (circle1.center.DistanceSquared(circle2.center) > (circle1.radius + circle2.radius)* (circle1.radius + circle2.radius))
		return false;
	else
		return true;
}

bool RectangleRectangleIntersection(const Beta::BoundingRectangle& rect1, const Beta::BoundingRectangle& rect2)
{
	return false;
}

bool RectangleCircleIntersection(const Beta::BoundingRectangle& rect, const Beta::Circle& circle)
{
	return false;
}
