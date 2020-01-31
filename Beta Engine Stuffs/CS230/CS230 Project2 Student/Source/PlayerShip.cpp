//------------------------------------------------------------------------------
//
// File Name: PlayerShip.cpp
// Author(s): Shain Allen
// Project: CS230Project2
// Course: wanic GP2
//
// Copyright � 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#include "stdafx.h"
#include "PlayerShip.h"
#include "Archetypes.h"
#include "Transform.h"
#include "RigidBody.h"
#include "Component.h"
#include "GameObject.h"

using namespace Beta;

PlayerShip::PlayerShip(float forwardThrust, float maximumSpeed, float rotationSpeed, float bulletSpeed)
	: Component("PlayerShip"), forwardThrust(forwardThrust), maximumSpeed(maximumSpeed), rotationSpeed(rotationSpeed), bulletSpeed(bulletSpeed), bulletArchetype(nullptr), transform(nullptr), rigidBody(nullptr)
{
}

Component* PlayerShip::Clone() const
{
	return new PlayerShip(*this);
}

void PlayerShip::Initialize()
{
	//bulletArchetype = Archetypes::CreateBulletArchetype();
	transform = M_GetComponent(Transform);
	rigidBody = M_GetComponent(RigidBody);
}

void PlayerShip::Update(float dt)
{
	Move();
	Rotate();
	Shoot();
}

void PlayerShip::Move() const
{
	Input* input = EngineGetModule(Input);

	if (input->CheckHeld('W'))
	{
		rigidBody->AddForce(Vector2D::FromAngleRadians(transform->GetRotation()));
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
		Vector2D fireingdir = Vector2D::FromAngleRadians(transform->GetRotation());

		bulletArchetype->GetComponent<Transform>()->SetTranslation(transform->GetTranslation() + fireingdir / 3);

		bulletArchetype->GetComponent<Transform>()->SetRotation(transform->GetRotation());

		Vector2D bulletVelocity = fireingdir * bulletSpeed;

		bulletArchetype->GetComponent<RigidBody>()->SetVelocity(bulletVelocity + rigidBody->GetVelocity());

		GetOwner()->GetSpace()->GetObjectManager().AddObject(*bulletArchetype);

		bullet->GetComponent<PlayerProjectile>()->SetSpawner(this);
	}
}
