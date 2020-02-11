//------------------------------------------------------------------------------
//
// File Name: MonkeyMovement.cpp
// Author(s): Shain Allen
// Project: CS230Project2
// Course: wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#include "stdafx.h"
#include "MonkeyMovement.h"
#include "Component.h"
#include "GameObject.h"
#include "Transform.h"
#include "RigidBody.h"
#include "Animation.h"
#include "Animator.h"

using namespace Beta;

MonkeyMovement::MonkeyMovement()
	:Component("MonkeyMovement"), monkeyWalkSpeed(3.0f), monkeyJumpSpeed(8.0f), gravity(0.0f, -12.0f), transform(nullptr), rigidBody(nullptr), onGround(false)
{
}

Component* MonkeyMovement::Clone() const
{
	return nullptr;
}

void MonkeyMovement::Initialize()
{
	transform = M_GetOwnerComponent(Transform);
	rigidBody = M_GetOwnerComponent(RigidBody);

	M_GetOwnerComponent(Animator)->Play();
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

void MonkeyMovement::MoveVertical()
{
	//get the ability to take input
	Input* input = EngineGetModule(Input);

	//check if the player pressed A or nothing
	if (onGround && rigidBody->GetVelocity().y <= 0)
	{
		if (input->CheckHeld('W'))
		{
			Vector2D upward(rigidBody->GetVelocity().x, monkeyJumpSpeed);
			rigidBody->SetVelocity(upward);
		}
		else
		{
			/*Vector2D upward(rigidBody->GetVelocity().x, 0);
			rigidBody->SetVelocity(upward);
			Vector2D grounded(transform->GetTranslation().x, groundHeight);
			transform->SetTranslation(grounded);*/
		}
	}
	else
	{
		rigidBody->AddForce(gravity);
	}
}
