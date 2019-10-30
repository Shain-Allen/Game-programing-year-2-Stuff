//------------------------------------------------------------------------------
//
// File Name:	Level2.cpp
// Author(s):	Shain Allen
// Project:	Level2.cpp
// Course:	wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//-------------------------------------------------------------

#include "stdafx.h"
#include "Level2.h"
#include <iostream>
#include <sstream>
#include "Level1.h"
#include "PlayerShip.h"
#include "TimedDeath.h"

using namespace::Beta;
using std::cout;
using std::endl;

Level2::Level2()
	: Beta::Level("LEVEL2")
{
}

void Level2::Load()
{
	cout << "Level2::Load" << endl;

	//get graphics engine
	GraphicsEngine& graphics = *EngineGetModule(GraphicsEngine);

	graphics.SetBackgroundColor(Colors::Black);

	shipTexture = ResourceGetTexture("ship.png");
	bulletTexture = ResourceGetTexture("bullet.png");
	shipSpriteSource = ResourceGetSpriteSource("Ship");
	bulletSpriteSource = ResourceGetSpriteSource("Bullet");
	bulletArchetype = Archetype(CreateBulletArchetype());
}

void Level2::Initialize()
{
	cout << "Level2::Initialize" << endl;

	GetSpace()->GetObjectManager().AddObject(*CreateShip());
}

void Level2::Update(float dt)
{
	UNREFERENCED_PARAMETER(dt);

	std::stringstream windowTitle;
	
	windowTitle << "Bullets alive: " << GetSpace()->GetObjectManager().GetObjectCount("bullet");

	WindowSystem& windowSystem = *EngineGetModule(WindowSystem);

	windowSystem.SetWindowTitle(windowTitle.str());

	Input* input = EngineGetModule(Input);

	if (input->CheckTriggered('2'))
	{
		GetSpace()->RestartLevel();
	}

	if (input->CheckTriggered('1'))
	{
		GetSpace()->SetLevel<Level1>();
	}
}

Beta::GameObject* Level2::CreateShip(void)
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

	PlayerShip* playerShip = new PlayerShip(bulletArchetype);
	ship->AddComponent(playerShip);

	return ship;
}

Beta::GameObject* Level2::CreateBulletArchetype(void)
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

	return bullet;
}
