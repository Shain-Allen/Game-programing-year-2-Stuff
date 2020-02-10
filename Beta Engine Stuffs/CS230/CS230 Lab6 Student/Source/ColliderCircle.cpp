#include "stdafx.h"
#include "ColliderCircle.h"
#include "Transform.h"
#include "Intersection2D.h"
#include "ColliderRectangle.h"
#include "ColliderPoint.h"

ColliderCircle::ColliderCircle(float radius)
	:Collider(ColliderType::ColliderTypeCircle), radius(radius)
{
}

Component* ColliderCircle::Clone() const
{
	return new ColliderCircle(*this);
}

void ColliderCircle::Draw()
{
	EngineGetModule(Beta::DebugDraw)->AddCircle(transform->GetTranslation, radius, Beta::Colors::Red);
}

float ColliderCircle::GetRadius() const
{
	return radius;
}

void ColliderCircle::SetRadius(float radius)
{
	radius = radius;
}

bool ColliderCircle::IsCollidingWith(const Collider& other) const
{
	Beta::Circle self = Beta::Circle(transform->GetTranslation(), GetRadius());

	if (other.GetType() == ColliderType::ColliderTypePoint)
	{
		other.IsCollidingWith(*this);
	}
	else if (other.GetType() == ColliderType::ColliderTypeCircle)
	{
		auto circleCollider = static_cast<const ColliderCircle&>(other);

		CircleCircleIntersection(self, Beta::Circle(other.transform->GetTranslation(), circleCollider.GetRadius()));
	}
	else if (other.GetType() == ColliderType::ColliderTypeRectangle)
	{
		auto rectangleCollider = static_cast<const ColliderRectangle&>(other);

		RectangleCircleIntersection(Beta::BoundingRectangle(rectangleCollider.transform->GetTranslation(), rectangleCollider.GetExtents), self);
	}
	else
		return false;
}
