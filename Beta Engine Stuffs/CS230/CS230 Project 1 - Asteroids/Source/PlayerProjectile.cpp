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
#include "PlayerShip.h"
#include "Asteroid.h"

//------------------------------------------------------------------------------

using namespace Beta;


// STUDENT CODE GOES HERE

PlayerProjectile::PlayerProjectile()
	: Component("PlayerProjectile"), player(nullptr)
{
}

void PlayerProjectile::Initialize()
{
	RegisterEventHandler(GetOwner(), "CollisionStarted", &PlayerProjectile::OnCollisionStarted);
}

void PlayerProjectile::SetSpawner(PlayerShip* player_)
{
	player = player_;
}

void PlayerProjectile::OnCollisionStarted(const Beta::Event& event)
{
	auto collision = static_cast<const CollisionEvent&>(event);

	if (collision.otherObject.GetName() == "Asteroid")
	{	
		player->IncreaseScore(collision.otherObject.GetComponent<Asteroid>()->GetPointValue());
	}

	GetOwner()->Destroy();
}

//------------------------------------------------------------------------------

// Extra component stuff - DO NOT REMOVE
COMPONENT_SUBCLASS_DEFINITION(PlayerProjectile)