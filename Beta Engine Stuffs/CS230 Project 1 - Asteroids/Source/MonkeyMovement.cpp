//------------------------------------------------------------------------------
//
// File Name:	MonkeyMovement.cpp
// Author(s):	Shain Allen
// Project:	MonkeyMovement.cpp
// Course:	wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#include "stdafx.h"				// Precompiled header
#include "MonkeyMovement.h"	// Class file

using namespace Beta;

// STUDENT CODE GOES HERE

MonkeyMovement::MonkeyMovement()
	:Component("MonkeyMovement"), monkeyWalkSpeed(3.0f), monkeyJumpSpeed(8.0f), groundHeight(-1.5f), gravity(0.0f, -12.0f), transform(nullptr), rigidBody(nullptr)
{
}

void MonkeyMovement::Initialize()
{
	transform = GetOwner()->GetComponent<Transform>();
	rigidBody = GetOwner()->GetComponent<RigidBody>();

	//getting the ground level spot bellow monkey
	Vector2D startingspot(transform->GetTranslation().x, groundHeight);

	//puting the monkey on the ground
	transform->SetTranslation(startingspot);
}

void MonkeyMovement::Update(float dt)
{
	UNREFERENCED_PARAMETER(dt);
	
	MoveHorizontal();
	MoveVertical();
}

void MonkeyMovement::MoveHorizontal() const
{
	//get the ability to take input
	Input* input = EngineGetModule(Input);

	//check if the player pressed d or a or nothing
	if (input->CheckHeld('D'))
	{
		Vector2D sideways(monkeyWalkSpeed, rigidBody->GetVelocity().y);
		rigidBody->SetVelocity(sideways);
	}
	else if (input->CheckHeld('A'))
	{
		Vector2D sideways(-monkeyWalkSpeed, rigidBody->GetVelocity().y);
		rigidBody->SetVelocity(sideways);
	}
	else
	{
		Vector2D sideways(0, rigidBody->GetVelocity().y);
		rigidBody->SetVelocity(sideways);
	}
}

void MonkeyMovement::MoveVertical() const
{
	//get the ability to take input
	Input* input = EngineGetModule(Input);
	
	//check if the player pressed A or nothing
	if (transform->GetTranslation().y <= groundHeight && rigidBody->GetVelocity().y <= 0)
	{
		if (input->CheckHeld('W'))
		{
			Vector2D upward(rigidBody->GetVelocity().x, monkeyJumpSpeed);
			rigidBody->SetVelocity(upward);
		}
		else
		{
			Vector2D upward(rigidBody->GetVelocity().x, 0);
			rigidBody->SetVelocity(upward);
			Vector2D grounded(transform->GetTranslation().x, groundHeight);
			transform->SetTranslation(grounded);
		}
	}
	else
	{
		rigidBody->AddForce(gravity);
	}

}

// Create extra component functions - DO NOT REMOVE
COMPONENT_SUBCLASS_DEFINITION(MonkeyMovement)


