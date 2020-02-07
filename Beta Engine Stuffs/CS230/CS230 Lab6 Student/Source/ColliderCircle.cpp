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
	return false;
}
