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

	BoundingRectangle boundingRectangle = BoundingRectangle(other.transform->GetTranslation(), static_cast<const ColliderRectangle&>(other).GetExtents());

	MapCollision mc(
		IsSideColliding(boundingRectangle, RectangleSide::SideBottom),
		IsSideColliding(boundingRectangle, RectangleSide::SideTop),
		IsSideColliding(boundingRectangle, RectangleSide::SideLeft),
		IsSideColliding(boundingRectangle, RectangleSide::SideRight));

	if (mc.bottom || mc.top)
	{
		other.transform->SetTranslationY(other.rigidbody->GetOldTranslation().y);

		Vector2D yvelocityreset = Vector2D(other.rigidbody->GetVelocity().x, 0.0f);

		other.rigidbody->SetVelocity(yvelocityreset);
	}

	if (mc.left || mc.right)
	{
		other.transform->SetTranslationX(other.rigidbody->GetOldTranslation().x);

		Vector2D xvelocityreset = Vector2D(0.0f, other.rigidbody->GetVelocity().y);

		other.rigidbody->SetVelocity(xvelocityreset);
	}

	if (mc.left || mc.right || mc.top || mc.bottom)
	{
		if (other.GetMapCollisionHandler() == nullptr)
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
	float leftX = rectangle.center.x - rectangle.extents.x * 0.5f;
	float rightX = rectangle.center.x + rectangle.extents.x * 0.5f;
	float topY = rectangle.center.y + rectangle.extents.y * 0.5f;
	float bottomY = rectangle.center.y - rectangle.extents.y * 0.5f;

	switch (side)
	{
	case RectangleSide::SideBottom:
		//check bottom side Hotspots
		if (
			//left
			IsCollidingAtPosition(leftX, rectangle.bottom)
			||
			//right
			IsCollidingAtPosition(rightX, rectangle.bottom)
			)
		{
			return true;
		}
		break;
	case RectangleSide::SideTop:
		//check top hotspots
		if (
			//left
			IsCollidingAtPosition(leftX, rectangle.top)
			||
			//right
			IsCollidingAtPosition(rightX, rectangle.top)
			)
		{
			return true;
		}
		break;
	case RectangleSide::SideLeft:
		//check left side hotspots
		if(
			//top
				IsCollidingAtPosition(rectangle.left, topY)
			||
			//bottom
				IsCollidingAtPosition(rectangle.left, bottomY)
		  )
		{
			return true;
		}
		break;
	case RectangleSide::SideRight:
		//check right side Hotspots
		if(
			//top
				IsCollidingAtPosition(rectangle.right, topY)
			||
			//bottom
				IsCollidingAtPosition(rectangle.right, bottomY)
			)
		{
			return true;
		}
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

	int columnindex = static_cast<int>(point.x + 0.5f);
	int rowindex = static_cast<int>(-point.y + 0.5f);

	if (map->GetCellValue(columnindex, rowindex) != 0)
	{
		return true;
	}
	return false;
}
