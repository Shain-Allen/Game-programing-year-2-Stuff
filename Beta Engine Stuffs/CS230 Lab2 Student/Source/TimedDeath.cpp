//------------------------------------------------------------------------------
//
// File Name:	TimedDeath.cpp
// Author(s):	
// Project:		
// Course:		WANIC VGP2 2018-2019
//
// Copyright � 2019 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "stdafx.h"
#include "TimedDeath.h"

//-------------------------------------------------------------------------------

using namespace Beta;

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Student code goes here.

// Extra component functionality - DO NOT REMOVE
COMPONENT_SUBCLASS_DEFINITION(TimedDeath)

//------------------------------------------------------------------------------

TimedDeath::TimedDeath(float timeUntilDeath)
	: Beta::Component("timedDeath"), timeUntilDeath(timeUntilDeath)
{
}

void TimedDeath::Update(float dt)
{
	UNREFERENCED_PARAMETER(dt);

	timeUntilDeath -= dt;

	if (timeUntilDeath < 0)
	{
		GetOwner()->Destroy();
	}
}

void TimedDeath::Serialize(Beta::FileStream& parser) const
{
	UNREFERENCED_PARAMETER(parser);
}

void TimedDeath::Deserialize(Beta::FileStream& parser)
{
	UNREFERENCED_PARAMETER(parser);
}