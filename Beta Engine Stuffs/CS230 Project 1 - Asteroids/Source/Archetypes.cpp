//------------------------------------------------------------------------------
//
// File Name: Archetypes.cpp
// Author(s): Shain Allen
// Project: CS230Project1
// Course: wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#include "stdafx.h"
#include "Archetypes.h"


Beta::GameObject* Archetypes::CreateShip()
{
	GameObject* ship = new GameObject("ship");

	Transform* transform = new Transform(0.0f, 0.0f);
	transform->SetRotation(0.0f);
	transform->SetScale(Vector2D(0.5f, 0.5f));
	ship->AddComponent(transform);

	Sprite* sprite = new Sprite;
	sprite->SetSpriteSource(shipSpriteSource);
	ship->AddComponent(sprite);

	RigidBody* rigiBody = new RigidBody;
	ship->AddComponent(rigiBody);

	PlayerShip* playerShip = new PlayerShip();
	ship->AddComponent(playerShip);

	EngineGetModule(GameObjectFactory)->SaveObjectToFile(ship);

	return ship;
}

Beta::Archetype Archetypes::CreateBulletArchetype()
{
	GameObject* bullet = new GameObject("bullet");

	Transform* transform = new Transform(0.0f, 0.0f);
	transform->SetRotation(0.0f);
	transform->SetScale(Vector2D(0.07f, 0.07f));
	bullet->AddComponent(transform);

	Sprite* sprite = new Sprite;
	sprite->SetSpriteSource(shipSpriteSource);
	bullet->AddComponent(sprite);

	RigidBody* RigiBody = new RigidBody;
	bullet->AddComponent(RigiBody);

	TimedDeath* timedDeath = new TimedDeath;
	bullet->AddComponent(timedDeath);

	EngineGetModule(GameObjectFactory)->SaveObjectToFile(bullet);

	return bullet;
}

Beta::Archetype Archetypes::CreateAsteroidArchetype()
{
	return Beta::Archetype();
}
