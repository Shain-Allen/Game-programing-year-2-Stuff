#include "stdafx.h"
#include "ColliderTilemap.h"
#include "Collider.h"
#include "ColliderRectangle.h"
#include "Transform.h"
#include "GameObject.h"
#include "GameObjectManager.h"
#include "RigidBody.h"
#include "Tilemap.h"

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
	using namespace Beta;

	BoundingRectangle boundingRectangle = BoundingRectangle(other.transform->GetTranslation(), static_cast<const ColliderRectangle&>(other).GetExtents);

	MapCollision mc(
		IsSideColliding(boundingRectangle, RectangleSide::SideBottom),
		IsSideColliding(boundingRectangle, RectangleSide::SideTop),
		IsSideColliding(boundingRectangle, RectangleSide::SideLeft),
		IsSideColliding(boundingRectangle, RectangleSide::SideRight));

	if (mc.bottom || mc.top)
	{
		M_GetOwnerComponent(Transform)->SetTranslationY(M_GetOwnerComponent(RigidBody)->GetOldTranslation().y);

		Vector2D yvelocityreset = Vector2D(M_GetOwnerComponent(RigidBody)->GetVelocity().x, 0.0f);

		M_GetOwnerComponent(RigidBody)->SetVelocity(yvelocityreset);
	}

	if (mc.left || mc.right)
	{
		M_GetOwnerComponent(Transform)->SetTranslationX(M_GetOwnerComponent(RigidBody)->GetOldTranslation().x);

		Vector2D xvelocityreset = Vector2D(0.0f, M_GetOwnerComponent(RigidBody)->GetVelocity().y);

		M_GetOwnerComponent(RigidBody)->SetVelocity(xvelocityreset);
	}

	if (mc.left || mc.right || mc.top || mc.bottom)
	{
		if (other.GetMapCollisionHandler == nullptr)
			return false;

		other.GetMapCollisionHandler()(*other.GetOwner(), mc);
		return true;
	}
	return false;
}

void ColliderTilemap::SetTilemap(const Tilemap* map_)
{
	map = map_;
}

bool ColliderTilemap::IsSideColliding(const Beta::BoundingRectangle& rectangle, RectangleSide side) const
{
	float leftX = transform->GetTranslation().x - rectangle.extents.x * 0.5f;
	float rightX = transform->GetTranslation().x + rectangle.extents.x * 0.5f;
	float topY = transform->GetTranslation().y + rectangle.extents.y * 0.5f;
	float bottomY = transform->GetTranslation().y - rectangle.extents.y * 0.5f;

	switch (side)
	{
	case RectangleSide::SideBottom:
		//check bottom side Hotspots
			//left
				IsCollidingAtPosition(leftX, rectangle.bottom);
			//right
				IsCollidingAtPosition(leftX, rectangle.bottom);
		break;
	case RectangleSide::SideTop:
		//check top hotspots
			//left
				IsCollidingAtPosition(leftX, rectangle.top);
			//right
				IsCollidingAtPosition(rightX, rectangle.top);
		break;
	case RectangleSide::SideLeft:
		//check left side hotspots
			//top
				IsCollidingAtPosition(rectangle.left, topY);
			//bottom
				IsCollidingAtPosition(rectangle.left, bottomY);
		break;
	case RectangleSide::SideRight:
		//check right side Hotspots
			//top
				IsCollidingAtPosition(rectangle.right, topY);
			//bottom
				IsCollidingAtPosition(rectangle.right, bottomY);
		break;
	default:
		break;
	}		
	return false;
}

bool ColliderTilemap::IsCollidingAtPosition(float x, float y) const
{
	using Beta::Vector2D;

	Vector2D point = M_GetOwnerComponent(Transform)->GetInverseMatrix() * Vector2D(x, y);

	int columnindex = static_cast<int>(point.x);
	int rowindex = static_cast<int>(point.y);

	if (map->GetCellValue(columnindex, rowindex) != 0)
	{
		return true;
	}
	return false;
}

void ColliderTilemap::ResolveCollisions(const Beta::BoundingRectangle& objectRectangle, Transform* objectTransform, RigidBody* objectRigidBody, const MapCollision& collisions) const
{
}

float ColliderTilemap::GetNextTileCenter(RectangleSide side, float sidePosition) const
{
	return 0.0f;
}
