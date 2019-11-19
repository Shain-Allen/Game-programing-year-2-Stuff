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

	transform = GetOwner()->GetComponent<Transform>();
	rigidBody = GetOwner()->GetComponent<RigidBody>();

	RegisterEventHandler(GetOwner(), "CollisionStarted", &Asteroid::OnCollisionStarted);

	SetPosition();
	SetVelocity();
}

unsigned Asteroid::GetPointValue() const
{
	if (size == Size::SizeSmall)
	{
		return basePointsValue * static_cast<unsigned>((sizePointsModifier * sizePointsModifier));
	}
	else if (size == Size::SizeMedium)
	{
		return basePointsValue * static_cast<unsigned>(sizePointsModifier);
	}
	else
	{
		return basePointsValue;
	}
}

void Asteroid::OnCollisionStarted(const Beta::Event& event)
{
	auto ce = static_cast<const CollisionEvent&>(event);

	if (ce.otherObject.GetName() == "bullet" || ce.otherObject.GetName() == "ship")
	{
		SpawnNewAsteroids();
		GetOwner()->Destroy();
	}
}

void Asteroid::SetPosition()
{
	if (size == Size::SizeLarge)
	{
		Location corner = static_cast<Location>(Random::Range(0, 3));

		BoundingRectangle worldsize = GetSpace()->GetCamera().GetScreenWorldDimensions();

		if (corner == Location::LocationTopLeft)
		{
			GetOwner()->GetComponent<Transform>()->SetTranslationY(worldsize.top);
			GetOwner()->GetComponent<Transform>()->SetTranslationX(worldsize.left);
		}

		if (corner == Location::LocationTopRight)
		{
			GetOwner()->GetComponent<Transform>()->SetTranslationY(worldsize.top);
			GetOwner()->GetComponent<Transform>()->SetTranslationX(worldsize.right);
		}

		if (corner == Location::LocationBottomRight)
		{
			GetOwner()->GetComponent<Transform>()->SetTranslationY(worldsize.bottom);
			GetOwner()->GetComponent<Transform>()->SetTranslationX(worldsize.right);
		}

		if (corner == Location::LocationBottomLeft)
		{
			GetOwner()->GetComponent<Transform>()->SetTranslationY(worldsize.bottom);
			GetOwner()->GetComponent<Transform>()->SetTranslationX(worldsize.left);
		}
	}
}

void Asteroid::SetVelocity()
{
	float angle = Random::Range(0.0f, 359.0f);

	Vector2D velocity = Vector2D::FromAngleDegrees(angle);

	GetOwner()->GetComponent<RigidBody>()->SetVelocity(velocity);
}

void Asteroid::SpawnNewAsteroids()
{
	int newAsteroids = 0;

	if (size == Size::SizeSmall)
	{
		newAsteroids = 0;
	}

	if (size == Size::SizeMedium)
	{
		newAsteroids = Random::Range(1, 2);
	}

	if (size == Size::SizeLarge)
	{
		newAsteroids = Random::Range(2, 3);
	}

	for (int i = 0; i < newAsteroids; i++)
	{
		GameObject* smallerAsteroids = new GameObject(*GetOwner());
		Vector2D scale = GetOwner()->GetComponent<Transform>()->GetScale();
		float colldierRadius = GetOwner()->GetComponent<ColliderCircle>()->GetRadius();

		if (GetOwner()->GetComponent<Asteroid>()->size == Size::SizeLarge)
		{
			smallerAsteroids->GetComponent<Asteroid>()->size = Size::SizeMedium;
		}
		else
		{
			smallerAsteroids->GetComponent<Asteroid>()->size = Size::SizeSmall;
		}

		GetSpace()->GetObjectManager().AddObject(*smallerAsteroids);
		GetOwner()->GetComponent<Transform>()->SetScale(scale * spawnScaleModifier);
		GetOwner()->GetComponent<ColliderCircle>()->SetRadius(colldierRadius * spawnScaleModifier);	
	}
}



//------------------------------------------------------------------------------

// Extra component stuff - DO NOT REMOVE
COMPONENT_SUBCLASS_DEFINITION(Asteroid)