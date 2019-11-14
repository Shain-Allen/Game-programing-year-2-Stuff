//------------------------------------------------------------------------------
//
// File Name:	Asteroid.cpp
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
#include "Asteroid.h"

//------------------------------------------------------------------------------

using namespace Beta;
using std::cout;
using std::endl;


// STUDENT CODE GOES HERE

Asteroid::Asteroid(float speedMin, float speedMax, unsigned basePointsValue, float sizePointsModifier, float spawnScaleModifier)
	: Component("Asteroid"), speedMin(speedMin), speedMax(speedMax), basePointsValue(basePointsValue), sizePointsModifier(sizePointsModifier), spawnScaleModifier(spawnScaleModifier), size(Size::SizeLarge), location(Location::LocationTopLeft), rigidBody(nullptr), transform(nullptr)
{
}

void Asteroid::Initialize()
{
	cout << "Asteroid" << endl;

	Transform* transform = new Transform();
	RigidBody* rigidBody = new RigidBody();

	RegisterEventHandler(GetOwner(), "CollisionStarted", &Asteroid::OnCollisionStarted);

	SetPosition();
	SetVelocity();
}

unsigned Asteroid::GetPointValue() const
{
	if (size == Size::SizeSmall)
	{
		return basePointsValue * sqrt(sizePointsModifier);
	}
}

void Asteroid::OnCollisionStarted(const Beta::Event& event)
{
	UNREFERENCED_PARAMETER(event);
}

void Asteroid::SetPosition()
{
}

void Asteroid::SetVelocity()
{
}

void Asteroid::SpawnNewAsteroids()
{
}



//------------------------------------------------------------------------------

// Extra component stuff - DO NOT REMOVE
COMPONENT_SUBCLASS_DEFINITION(Asteroid)