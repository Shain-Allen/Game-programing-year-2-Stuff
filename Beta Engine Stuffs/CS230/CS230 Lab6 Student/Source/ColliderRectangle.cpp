#include "stdafx.h"
#include "ColliderRectangle.h"
#include "Transform.h"
#include "Intersection2D.h"
#include "ColliderCircle.h"
#include "ColliderPoint.h"

ColliderRectangle::ColliderRectangle(const Beta::Vector2D& extents)
	: Collider(ColliderType::ColliderTypeRectangle), extents()
{
}

Component* ColliderRectangle::Clone() const
{
	return new ColliderRectangle(*this);
}

void ColliderRectangle::Draw()
{
	EngineGetModule(Beta::DebugDraw)->AddRectangle(transform->GetTranslation, extents, Beta::Colors::Red);
}

const Beta::Vector2D& ColliderRectangle::GetExtents() const
{
	// TODO: insert return statement here
}

void ColliderRectangle::SetExtents(const Beta::Vector2D& extents)
{
}

bool ColliderRectangle::IsCollidingWith(const Collider& other) const
{
	return false;
}
