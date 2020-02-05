//------------------------------------------------------------------------------
//
// File Name: PlayerShip.cpp
// Author(s): Shain Allen
// Project: CS230Project2
// Course: wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#include "stdafx.h"
#include "PlayerShip.h"
#include "Archetypes.h"
#include "Transform.h"
#include "RigidBody.h"
#include "Component.h"
#include "GameObject.h"
#include "Space.h"
#include "GameObjectManager.h"

using namespace Beta;

PlayerShip::PlayerShip(float forwardThrust, float maximumSpeed, float rotationSpeed, float bulletSpeed)
	: Component("PlayerShip"), forwardThrust(forwardThrust), maximumSpeed(maximumSpeed), rotationSpeed(rotationSpeed), bulletSpeed(bulletSpeed), transform(nullptr), rigidBody(nullptr)
{
}

Component* PlayerShip::Clone() const
{
	return new PlayerShip(*this);
}

void PlayerShip::Initialize()
{
	transform = M_GetOwnerComponent(Transform);
	rigidBody = M_GetOwnerComponent(RigidBody);
}

void PlayerShip::Update(float dt)
{
	UNREFERENCED_PARAMETER(dt);
	Move();
	Rotate();
	Shoot();
}

void PlayerShip::Move() const
{
	Input* input = EngineGetModule(Input);

	if (input->CheckHeld('W'))
	{
		rigidBody->AddForce(Vector2D::FromAngleDegrees(transform->GetRotation()));
	}

	if (rigidBody->GetVelocity().Magnitude() > maximumSpeed)
	{
		rigidBody->SetVelocity(rigidBody->GetVelocity().Normalized() * maximumSpeed);
	}
}

void PlayerShip::Rotate() const
{
	Input* input = EngineGetModule(Input);

	if (input->CheckHeld('A'))
	{
		rigidBody->SetAngularVelocity(rotationSpeed);
	}

	if (input->CheckHeld('D'))
	{
		rigidBody->SetAngularVelocity(-rotationSpeed);
	}

	if (input->CheckHeld('A') && input->CheckHeld('D') || !input->CheckHeld('A') && !input->CheckHeld('D'))
	{
		rigidBody->SetAngularVelocity(0.0f);
	}
}

void PlayerShip::Shoot() const
{
	Input* input = EngineGetModule(Input);

	if (input->CheckTriggered(' '))
	{
		GameObject* bulletArchetype = new GameObject(*GetOwner()->GetSpace()->GetObjectManager().GetArchetypeByName("Bullet"));

		Vector2D fireingdir = Vector2D::FromAngleDegrees(transform->GetRotation());

		M_GetComponent(bulletArchetype, Transform)->SetTranslation(transform->GetTranslation() + fireingdir / 3);

		M_GetComponent(bulletArchetype, Transform)->SetRotation(transform->GetRotation());

		Vector2D bulletVelocity = fireingdir * bulletSpeed;

		M_GetComponent(bulletArchetype, RigidBody)->SetVelocity(bulletVelocity + rigidBody->GetVelocity());

		GetOwner()->GetSpace()->GetObjectManager().AddObject(*bulletArchetype);
	}
}
