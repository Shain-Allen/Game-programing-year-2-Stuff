//------------------------------------------------------------------------------
//
// File Name:	PlayerShip.cpp
// Author(s):	
// Project:		
// Course:		WANIC VGP2 2018-2019
//
// Copyright © 2019 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "stdafx.h"
#include "PlayerShip.h"

//------------------------------------------------------------------------------

using namespace Beta;

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Student code goes here.

// Extra component functionality - DO NOT REMOVE
COMPONENT_SUBCLASS_DEFINITION(PlayerShip)

//------------------------------------------------------------------------------

PlayerShip::PlayerShip(float forwardThrust, float maximumSpeed, float rotationSpeed, float bulletSpeed, float deathDuration)
	: Component("PlayerShip"), forwardThrust(forwardThrust), maximumSpeed(maximumSpeed), rotationSpeed(rotationSpeed), bulletSpeed(bulletSpeed), bulletArchetype(bulletArchetype), score(0), deathDuration(deathDuration), isDying(false), transform(nullptr), rigidBody(nullptr)
{
}

void PlayerShip::Initialize()
{
	transform = GetOwner()->GetComponent<Transform>();
	rigidBody = GetOwner()->GetComponent<RigidBody>();
}

void PlayerShip::Update(float dt)
{
	UNREFERENCED_PARAMETER(dt);

	Move();
	Rotate();
	Shoot();
}

unsigned PlayerShip::GetScore() const
{
	return 0;
}

void PlayerShip::IncreaseScore(unsigned amount)
{
	UNREFERENCED_PARAMETER(amount);
}

/*void PlayerShip::Serialize(Beta::FileStream& stream) const
{
	UNREFERENCED_PARAMETER(stream);

	stream.WriteVariable("bulletArchtype", bulletArchetype->GetName());
	stream.WriteVariable("forwardThrust", forwardThrust);
	stream.WriteVariable("maxiumSpeed", maximumSpeed);
	stream.WriteVariable("rotationSpeed", rotationSpeed);
	stream.WriteVariable("bulletSpeed", bulletSpeed);
}

void PlayerShip::Deserialize(Beta::FileStream& stream)
{
	UNREFERENCED_PARAMETER(stream);
	std::string bulletName;

	stream.ReadVariable("bulletArchtype", bulletName);
	bulletArchetype = ResourceGetArchetype(bulletName);
	stream.ReadVariable("forwardThrust", forwardThrust);
	stream.ReadVariable("maxiumSpeed", maximumSpeed);
	stream.ReadVariable("rotationSpeed", rotationSpeed);
	stream.ReadVariable("bulletSpeed", bulletSpeed);
}*/

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

void PlayerShip::Shoot()
{
	Input* input = EngineGetModule(Input);

	if (input->CheckTriggered(' '))
	{
		GameObject* bullet = new GameObject(ResourceGetArchetype("Bullet"));

		Vector2D fireingdir = Vector2D::FromAngleRadians(transform->GetRotation());

		bullet->GetComponent<Transform>()->SetTranslation(transform->GetTranslation() + fireingdir / 3);

		bullet->GetComponent<Transform>()->SetRotation(transform->GetRotation());

		Vector2D bulletVelocity = fireingdir * bulletSpeed;

		bullet->GetComponent<RigidBody>()->SetVelocity(bulletVelocity + rigidBody->GetVelocity());

		GetOwner()->GetSpace()->GetObjectManager().AddObject(*bullet);
	}
}

void PlayerShip::DeathSequence(float dt)
{
	UNREFERENCED_PARAMETER(dt);
}

void PlayerShip::OnCollisionStarted(const Beta::Event& event)
{
	UNREFERENCED_PARAMETER(event);
}
