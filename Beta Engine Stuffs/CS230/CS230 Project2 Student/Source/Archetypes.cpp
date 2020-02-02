//------------------------------------------------------------------------------
//
// File Name: Archetypes.cpp
// Author(s): Shain Allen
// Project: CS230Project2
// Course: wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#include "stdafx.h"
#include "Archetypes.h"
#include "GameObject.h"
#include "Transform.h"
#include "Sprite.h"
#include "RigidBody.h"
#include "TimedDeath.h"
#include "Animator.h"
#include "PlayerShip.h"
#include "MonkeyMovement.h"

using Beta::Vector2D;

GameObject* Archetypes::CreateShip(Beta::Mesh* mesh)
{
	GameObject* ship = new GameObject("Ship");

	Transform* transform = new Transform();
	transform->SetScale(Vector2D(0.5, 0.5));
	ship->AddComponent(transform);

	Sprite* sprite = new Sprite(mesh);
	ship->AddComponent(sprite);

	RigidBody* rigidBody = new RigidBody();
	ship->AddComponent(rigidBody);

	PlayerShip* playerShip = new PlayerShip();
	ship->AddComponent(playerShip);

	return ship;
}

GameObject* Archetypes::CreateBulletArchetype(Beta::Mesh* mesh)
{
	GameObject* bullet = new GameObject("Bullet");

	Transform* transform = new Transform();
	transform->SetScale(Vector2D(0.07f, 0.07f));
	bullet->AddComponent(transform);

	Sprite* sprite = new Sprite(mesh);
	bullet->AddComponent(sprite);

	RigidBody* rigidBody = new RigidBody();
	bullet->AddComponent(rigidBody);

	TimedDeath* timedDeath = new TimedDeath();
	bullet->AddComponent(timedDeath);

	return bullet;
}

GameObject* Archetypes::CreateMonkey(Beta::Mesh* mesh, SpriteSource* spriteSource, Animation* animation)
{
	GameObject* monkey = new GameObject("Monkey");

	Transform* transform = new Transform();
	transform->SetScale(Vector2D(0.07f, 0.07f));
	monkey->AddComponent(transform);

	Sprite* sprite = new Sprite(mesh, spriteSource);
	monkey->AddComponent(sprite);

	Animator* animator = new Animator();
	animator->AddAnimation(animation);
	monkey->AddComponent(animator);

	RigidBody* rigidBody = new RigidBody();
	monkey->AddComponent(rigidBody);

	MonkeyMovement* monkeyMovement = new MonkeyMovement();
	monkey->AddComponent(monkeyMovement);

	return monkey;
}
