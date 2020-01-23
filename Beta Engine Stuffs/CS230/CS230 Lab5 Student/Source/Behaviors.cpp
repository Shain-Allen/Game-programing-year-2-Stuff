//------------------------------------------------------------------------------
//
// File Name: Behaviors.cpp
// Author(s): Shain Allen
// Project: CS230Lab5
// Course: wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#include "stdafx.h"
#include "Behaviors.h"
#include "Transform.h"
#include "RigidBody.h"

using namespace Beta;
using std::cout;
using std::endl;

void Behaviors::UpdateShip(Transform* transform, RigidBody* rigidBody)
{
	UNREFERENCED_PARAMETER(transform);
	UNREFERENCED_PARAMETER(rigidBody);

	GraphicsEngine& graphics = *EngineGetModule(GraphicsEngine);
	Camera& camera = graphics.GetDefaultCamera();
	Input& input = *EngineGetModule(Input);
	DebugDraw& debug = *EngineGetModule(DebugDraw);

	Vector2D mousePos = camera.ScreenToWorldPosition(input.GetCursorPosition());
	Vector2D pToMouse = (mousePos - transform->GetTranslation()).Normalized();
	debug.AddLineToList(transform->GetTranslation(), transform->GetTranslation() + pToMouse, Colors::Red);
	Vector2D forwardDir = Vector2D(cos(transform->GetRotation() * static_cast<float>(M_PI) /180.0f), sin(transform->GetRotation() * static_cast<float>(M_PI) / 180.0f));
	debug.AddLineToList(transform->GetTranslation(), transform->GetTranslation() + forwardDir, Colors::Green);
	Vector2D forwardNorm = Vector2D(forwardDir.y, -forwardDir.x);
	debug.AddLineToList(transform->GetTranslation(), transform->GetTranslation() + forwardNorm);
	//debug.EndLineList();
	
	float turningspeed = 3.0f;

	float dot = forwardNorm.DotProduct(pToMouse);
	if (!AlmostEqual(forwardDir, pToMouse, 0.05f))
	{
		if (dot > 0)
		{
			rigidBody->SetAngularVelocity(-turningspeed);
		}
		else
		{
			rigidBody->SetAngularVelocity(turningspeed);
		}
	}
	else
	{
		rigidBody->SetAngularVelocity(0);
	}
	
	//cout << dot << endl;	

	float distanceToMouse = sqrt(squared(mousePos.x - transform->GetTranslation().x))+(squared(mousePos.y - transform->GetTranslation().y));

	//cout << distanceToMouse << endl;
	float approachDistance = 0.5f;
	if (distanceToMouse <= approachDistance)
		rigidBody->SetVelocity(0);

	rigidBody->AddForce(pToMouse / 1.5f);
}

const float gravity = -9.8f;
const float upForce = 500.0f;
const float sidewaysForce = 50;
const float ground = -1.9f;

void Behaviors::UpdateMonkey(Transform* transform, RigidBody* rigidBody)
{
	UNREFERENCED_PARAMETER(transform);
	UNREFERENCED_PARAMETER(rigidBody);

	Input& input = *EngineGetModule(Input);

	bool isGrounded = false;

	if (transform->GetTranslation().y < ground)
	{
		transform->SetTranslation(Vector2D(transform->GetTranslation().x, ground));
		rigidBody->SetVelocity_y(0);
		isGrounded = true;
	}

	if (!isGrounded)
		rigidBody->AddForce_Y(gravity);

	if (isGrounded && input.CheckTriggered(' '))
	{
		rigidBody->AddForce_Y(upForce);
		isGrounded = false;
	}

	float movement = 0;

	if (input.CheckHeld('A'))
		movement -= 1;

	if (input.CheckHeld('D'))
		movement += 1;

	rigidBody->SetVelocity_x(movement);
}

float Behaviors::squared(float number)
{
	return number * number;
}


