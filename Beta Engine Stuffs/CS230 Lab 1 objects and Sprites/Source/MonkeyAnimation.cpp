//------------------------------------------------------------------------------
//
// File Name:	MonkeyAnimation.cpp
// Author(s):	Student name here
// Project:		BetaFramework
// Course:		WANIC VGP2 2018-2019
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#include "stdafx.h"				// Precompiled header
#include "MonkeyAnimation.h"	// Class file

using namespace Beta;

// STUDENT CODE GOES HERE

MonkeyAnimation::MonkeyAnimation()
	: Component("MonkeyAnimation"), walkAnimation(0), jumpAnimation(0), idleAnimation(0), currentState(StateIdle), nextState(StateIdle), animator(nullptr), physics(nullptr), transform(0)
{
}

void MonkeyAnimation::Initialize()
{
}

void MonkeyAnimation::Update(float dt)
{
	UNREFERENCED_PARAMETER(dt);
}

void MonkeyAnimation::ChooseNextState()
{
}

void MonkeyAnimation::ChangeCurrentState()
{
}

void MonkeyAnimation::FlipSprite() const
{
}

// Create extra component functions - DO NOT REMOVE
COMPONENT_SUBCLASS_DEFINITION(MonkeyAnimation)


