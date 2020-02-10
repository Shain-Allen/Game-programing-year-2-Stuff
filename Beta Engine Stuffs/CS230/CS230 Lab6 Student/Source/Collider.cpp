#include "stdafx.h"
#include "Collider.h"
#include "Component.h"
#include "GameObject.h"
#include "Transform.h"
#include "RigidBody.h"

Collider::Collider(ColliderType type)
	: Component("Collider"), transform(nullptr), rigidbody(nullptr), type(type), handler()
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
		handler(*GetOwner(), *other.GetOwner());
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
