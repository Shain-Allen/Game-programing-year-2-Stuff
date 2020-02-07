#include "stdafx.h"
#include "ColliderPoint.h"
#include "Collider.h"
#include "Transform.h"
#include "Intersection2D.h"
#include "ColliderCircle.h"
#include "ColliderRectangle.h"

ColliderPoint::ColliderPoint()
	: Collider(ColliderType::ColliderTypePoint)
{	
}

Component* ColliderPoint::Clone() const
{
	return new ColliderPoint(*this);
}

void ColliderPoint::Draw()
{
	EngineGetModule(Beta::DebugDraw)->AddCircle(transform->GetTranslation(), 0.1f, Beta::Colors::Red);
}

bool ColliderPoint::IsCollidingWith(const Collider& other) const
{

	if (other.GetType() == ColliderType::ColliderTypeCircle)
	{
		auto circleCollider = static_cast<const ColliderCircle&>(other);

		PointCircleIntersection(transform->GetTranslation(), Beta::Circle(other.transform->GetTranslation(), circleCollider.GetRadius()));
	}
	else if (other.GetType() == ColliderType::ColliderTypeRectangle)
	{
		auto rectangleCollider = static_cast<const ColliderRectangle&>(other);
	}
}
