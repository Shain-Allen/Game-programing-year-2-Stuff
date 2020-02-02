//------------------------------------------------------------------------------
//
// File Name: TimedDeath.cpp
// Author(s): Shain Allen
// Project: CS230Project2
// Course: wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#include "stdafx.h"
#include "TimedDeath.h"
#include "Component.h"
#include "GameObject.h"

TimedDeath::TimedDeath(float timeUntilDeath)
	: Component("TimedDeath"), timeUntilDeath(timeUntilDeath)
{
}

Component* TimedDeath::Clone() const
{
	return new TimedDeath(*this);
}

void TimedDeath::Update(float dt)
{
	timeUntilDeath -= dt;

	if (timeUntilDeath < 0)
	{
		GetOwner()->Destroy();
	}
}
