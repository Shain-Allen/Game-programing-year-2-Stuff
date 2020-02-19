#include "stdafx.h"
#include "ColliderTilemap.h"
#include "Collider.h"
#include "ColliderRectangle.h"
#include "Transform.h"
#include "GameObject.h"
#include "GameObjectManager.h"

ColliderTilemap::ColliderTilemap()
	:Collider(ColliderType::ColliderTypeTilemap), map()
{
}

Component* ColliderTilemap::Clone() const
{
	return new ColliderTilemap(*this);
}

void ColliderTilemap::Draw()
{

}

bool ColliderTilemap::IsCollidingWith(const Collider& other) const
{
	return false;
}

void ColliderTilemap::SetTilemap(const Tilemap* map_)
{
	map = map_;
}

bool ColliderTilemap::IsSideColliding(const Beta::BoundingRectangle& rectangle, RectangleSide side) const
{
	using namespace Beta;

	BoundingRectangle boundingRectangle = BoundingRectangle(rectangle.center, rectangle.extents);

	MapCollision mc(
		IsSideColliding(boundingRectangle, RectangleSide::SideBottom),
		IsSideColliding(boundingRectangle, RectangleSide::SideTop),
		IsSideColliding(boundingRectangle, RectangleSide::SideLeft),
		IsSideColliding(boundingRectangle, RectangleSide::SideRight));

	if (mc.bottom || mc.top)
	{
		
	}
}

bool ColliderTilemap::IsCollidingAtPosition(float x, float y) const
{
	return false;
}

void ColliderTilemap::ResolveCollisions(const Beta::BoundingRectangle& objectRectangle, Transform* objectTransform, RigidBody* objectRigidBody, const MapCollision& collisions) const
{
}

float ColliderTilemap::GetNextTileCenter(RectangleSide side, float sidePosition) const
{
	return 0.0f;
}
