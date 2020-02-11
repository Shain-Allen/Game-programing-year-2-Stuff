#include "stdafx.h"
#include "ColliderRectangle.h"
#include "Transform.h"
#include "Intersection2D.h"
#include "ColliderCircle.h"
#include "ColliderPoint.h"

ColliderRectangle::ColliderRectangle(const Beta::Vector2D& extents)
	: Collider(ColliderType::ColliderTypeRectangle), extents(extents)
{
}

Component* ColliderRectangle::Clone() const
{
	return new ColliderRectangle(*this);
}

void ColliderRectangle::Draw()
{
	EngineGetModule(Beta::DebugDraw)->AddRectangle(transform->GetTranslation(), extents, Beta::Colors::Red);
}

const Beta::Vector2D& ColliderRectangle::GetExtents() const
{
	return extents;
}

void ColliderRectangle::SetExtents(const Beta::Vector2D& extents_)
{
	extents = extents_;
}

bool ColliderRectangle::IsCollidingWith(const Collider& other) const
{
	Beta::BoundingRectangle self = Beta::BoundingRectangle(transform->GetTranslation(), GetExtents());

	if (other.GetType() == ColliderType::ColliderTypePoint)
	{
		return other.IsCollidingWith(*this);
	}
	else if (other.GetType() == ColliderType::ColliderTypeCircle)
	{
		return other.IsCollidingWith(*this);
	}
	else if (other.GetType() == ColliderType::ColliderTypeRectangle)
	{
		auto rectangle = static_cast<const ColliderRectangle&>(other);

		return RectangleRectangleIntersection(self, Beta::BoundingRectangle(rectangle.transform->GetTranslation(), rectangle.GetExtents()));
	}
	else
		return false;
}
