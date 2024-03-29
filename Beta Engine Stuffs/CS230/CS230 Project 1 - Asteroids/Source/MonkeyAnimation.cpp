//------------------------------------------------------------------------------
//
// File Name:	MonkeyAnimation.cpp
// Author(s):	Shain Allen
// Project:	MonkeyAnimation.cpp
// Course:	wanic GP2
//
// Copyright � 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#include "stdafx.h"				// Precompiled header
#include "MonkeyAnimation.h"	// Class file

using namespace Beta;

// STUDENT CODE GOES HERE

MonkeyAnimation::MonkeyAnimation()
	: Component("MonkeyAnimation"), walkAnimation(0), jumpAnimation(0), idleAnimation(0), currentState(StateIdle), nextState(StateIdle), animator(nullptr), rigidBody(nullptr), transform(0)
{
}

void MonkeyAnimation::Initialize()
{
	//set the pointers
	animator = GetOwner()->GetComponent<Animator>();
	rigidBody = GetOwner()->GetComponent<RigidBody>();
	transform = GetOwner()->GetComponent<Transform>();

	//set the indicies of each animation
	walkAnimation = animator->GetAnimationIndex("animationWalk");
	jumpAnimation = animator->GetAnimationIndex("animationJump");
	idleAnimation = animator->GetAnimationIndex("animationIdle");

	animator->Play(idleAnimation);

	originalScale = transform->GetScale();
}

void MonkeyAnimation::Update(float dt)
{
	UNREFERENCED_PARAMETER(dt);
	ChooseNextState();
	ChangeCurrentState();
	FlipSprite();
}

void MonkeyAnimation::ChooseNextState()
{
	if (rigidBody->GetVelocity().y != 0)
	{
		nextState = StateJump;
	}
	else if (rigidBody->GetVelocity().x != 0)
	{
		nextState = StateWalk;
	}
	else
	{
		nextState = StateIdle;
	}
}

void MonkeyAnimation::ChangeCurrentState()
{
	if (currentState != nextState)
	{
		currentState = nextState;

		switch (currentState)
		{
		case StateIdle:
			animator->Play(idleAnimation);
			break;
		case StateWalk:
			animator->Play(walkAnimation);
			break;
		case StateJump:
			animator->Play(jumpAnimation);
			break;
		}
	}
}

void MonkeyAnimation::FlipSprite() const
{

	Vector2D flipedMonkey(-originalScale.x, originalScale.y);

	if (currentState != StateIdle)
	{
		if (rigidBody->GetVelocity().x < 0)
		{
			transform->SetScale(flipedMonkey);
		}
		else if (rigidBody->GetVelocity().x > 0)
		{
			transform->SetScale(originalScale);
		}
	}
}

// Create extra component functions - DO NOT REMOVE
COMPONENT_SUBCLASS_DEFINITION(MonkeyAnimation)


