#include "stdafx.h"
#include "Collider.h"
#include "Component.h"
#include "GameObject.h"
#include "Transform.h"
#include "RigidBody.h"

Collider::Collider(ColliderType type)
	: Component("Collider"), transform(nullptr), rigidbody(nullptr), type(type), handler(), mapHandler()
{
}

void Collider::Initialize()
{
	transform = M_GetOwnerComponent(Transform);
	rigidbody = M_GetOwnerComponent(RigidBody);
}

void Collider::CheckCollision(const Collider& other)
{
	if (IsCollidingWith(other))
	{
		if (handler != nullptr)
			handler(*GetOwner(), *other.GetOwner());
		if(other.handler != nullptr)
			other.handler(*other.GetOwner(), *GetOwner());
	}
}

ColliderType Collider::GetType() const
{
	return type;
}

void Collider::SetCollisionHandler(CollisionEventHandler handler_)
{
	handler = handler_;
}

void Collider::SetMapCollisionHandler(MapCollisionEventHandler mapHandler_)
{
	mapHandler = mapHandler_;
}

MapCollisionEventHandler Collider::GetMapCollisionHandler() const
{
	return mapHandler;
}

MapCollision::MapCollision(bool bottom, bool top, bool left, bool right)
	: bottom(bottom), top(top), left(left), right(right)
{
}
