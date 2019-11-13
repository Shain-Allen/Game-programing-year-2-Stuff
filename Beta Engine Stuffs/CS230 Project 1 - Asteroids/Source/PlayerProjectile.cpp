//------------------------------------------------------------------------------
//
// File Name:	PlayerProjectile.cpp
// Author(s):	Jeremy Kings (j.kings)
// Project:		BetaFramework
// Course:		WANIC VGP2 2018-2019
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "stdafx.h"
#include "PlayerProjectile.h"

//------------------------------------------------------------------------------

using namespace Beta;


// STUDENT CODE GOES HERE

PlayerProjectile::PlayerProjectile()
	: Component("PlayerProjectile"), player(nullptr)
{
}

void PlayerProjectile::Initialize()
{
}

void PlayerProjectile::SetSpawner(PlayerShip* player)
{
	UNREFERENCED_PARAMETER(player);
}

void PlayerProjectile::OnCollisionStarted(const Beta::Event& event)
{
	UNREFERENCED_PARAMETER(event);
}

//------------------------------------------------------------------------------

// Extra component stuff - DO NOT REMOVE
COMPONENT_SUBCLASS_DEFINITION(PlayerProjectile)