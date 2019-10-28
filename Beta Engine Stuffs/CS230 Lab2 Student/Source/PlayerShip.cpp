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

PlayerShip::PlayerShip(Beta::Archetype bulletArchetype, float forwardThrust, float maximumSpeed, float rotationSpeed, float bulletSpeed)
{
}

void PlayerShip::Initialize()
{
}

void PlayerShip::Update(float dt)
{
}

void PlayerShip::Serialize(Beta::FileStream& parser) const
{
}

void PlayerShip::Deserialize(Beta::FileStream& parser)
{
}

void PlayerShip::Move() const
{
}

void PlayerShip::Rotate() const
{
}

void PlayerShip::Shoot() const
{
}
