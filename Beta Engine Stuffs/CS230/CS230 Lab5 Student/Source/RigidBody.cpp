//------------------------------------------------------------------------------
//
// File Name: RigidBody.cpp
// Author(s): Shain Allen
// Project: CS230Lab5
// Course: wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#include "stdafx.h"
#include "RigidBody.h"
#include "Transform.h"

using Beta::Vector2D;

RigidBody::RigidBody(Transform* transform)
	:velocity(0,0), angularVelocity(0.0f), inverseMass(1.0f), forcesSum(0,0), acceleration(0,0), oldTranslation(0,0), transform(transform)
{
}

void RigidBody::Update(float dt)
{
	UNREFERENCED_PARAMETER(dt);
	acceleration = forcesSum * inverseMass;
	forcesSum = 0;
}

void RigidBody::FixedUpdate(float dt)
{
	velocity += acceleration * dt;
	oldTranslation = transform->GetTranslation();
	transform->SetTranslation(oldTranslation + velocity * dt);
	transform->SetRotation(transform->GetRotation() + angularVelocity);

}

void RigidBody::SetVelocity(const Beta::Vector2D& velocity_)
{
	velocity = velocity_;
}

void RigidBody::SetVelocity_x(const float velocity_x)
{
	velocity.x = velocity_x;
}

void RigidBody::SetVelocity_y(const float velocity_y)
{
	velocity.y = velocity_y;
}

const Beta::Vector2D& RigidBody::GetVelocity() const
{
	return velocity;
}

void RigidBody::SetAngularVelocity(float velocity_)
{
	angularVelocity = velocity_;
}

float RigidBody::GetAngularVelocity() const
{
	return angularVelocity;
}

void RigidBody::SetMass(float mass)
{
	inverseMass = 1 / mass;
}

void RigidBody::AddForce(const Beta::Vector2D& force)
{
	forcesSum += force;
}

void RigidBody::AddForce_Y(const float force_Y)
{
	forcesSum.y += force_Y;
}

void RigidBody::AddForce_X(const float force_X)
{
	forcesSum.x += force_X;
}

const Beta::Vector2D& RigidBody::GetAcceleration() const
{
	return acceleration;
}

const Beta::Vector2D& RigidBody::GetOldTranslation() const
{
	return oldTranslation;
}
