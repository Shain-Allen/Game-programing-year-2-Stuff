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
#include "TimedDeath.h"
#include "PlayerShip.h"
#include "Level2.h"
#include "ScreenWrap.h"
#include "Asteroid.h"
#include "PlayerProjectile.h"

using namespace Beta;

Beta::GameObject* Archetypes::CreateShip()
{
	GameObject* ship = new GameObject("ship");

	Transform* transform = new Transform(0.0f, 0.0f);
	transform->SetRotation(0.0f);
	transform->SetScale(Vector2D(0.5f, 0.5f));
	ship->AddComponent(transform);

	Sprite* sprite = new Sprite;
	sprite->SetSpriteSource(ResourceGetSpriteSource("Ship"));
	ship->AddComponent(sprite);

	RigidBody* rigiBody = new RigidBody;
	ship->AddComponent(rigiBody);

	PlayerShip* playerShip = new PlayerShip();
	ship->AddComponent(playerShip);

	ScreenWrap* screenWrap = new ScreenWrap();
	ship->AddComponent(screenWrap);

	ColliderCircle* collider = new ColliderCircle(transform->GetScale().x / 2);
	ship->AddComponent(collider);

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
	sprite->SetSpriteSource(ResourceGetSpriteSource("Bullet"));
	bullet->AddComponent(sprite);

	RigidBody* RigiBody = new RigidBody;
	bullet->AddComponent(RigiBody);

	TimedDeath* timedDeath = new TimedDeath;
	bullet->AddComponent(timedDeath);

	ColliderCircle* collider = new ColliderCircle(transform->GetScale().x / 2);
	bullet->AddComponent(collider);

	PlayerProjectile* playerProjetile = new PlayerProjectile;
	bullet->AddComponent(playerProjetile);

	EngineGetModule(GameObjectFactory)->SaveObjectToFile(bullet);

	return Beta::Archetype(bullet);
}

Beta::Archetype Archetypes::CreateAsteroidArchetype()
{
	GameObject* asteroids = new GameObject("Asteroid");

	Transform* transform = new Transform(0.0f, 0.0f);
	transform->SetRotation(0.0f);
	transform->SetScale(Vector2D(0.6f, 0.6f));
	asteroids->AddComponent(transform);

	Sprite* sprite = new Sprite;
	sprite->SetSpriteSource(ResourceGetSpriteSource("Asteroid"));
	asteroids->AddComponent(sprite);

	RigidBody* rigidBody = new RigidBody;
	asteroids->AddComponent(rigidBody);

	ColliderCircle* colliderCircle = new ColliderCircle(transform->GetScale().x / 2);
	asteroids->AddComponent(colliderCircle);

	ScreenWrap* screenWrap = new ScreenWrap;
	asteroids->AddComponent(screenWrap);

	Asteroid* asteroid = new Asteroid;
	asteroids->AddComponent(asteroid);

	return Archetype(asteroids);
}
