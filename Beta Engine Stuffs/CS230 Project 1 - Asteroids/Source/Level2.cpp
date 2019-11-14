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
#include "Archetypes.h"

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

	//shipTexture = ResourceGetTexture("ship.png");
	//bulletTexture = ResourceGetTexture("bullet.png");
	//shipSpriteSource = ResourceGetSpriteSource("Ship");
	//bulletSpriteSource = ResourceGetSpriteSource("Bullet");
	//bulletArchetype = ResourceGetArchetype("Bullet");
	bulletArchetype = Archetypes::CreateBulletArchetype();
}

void Level2::Initialize()
{
	cout << "Level2::Initialize" << endl;

	GameObjectFactory& factory = *EngineGetModule(GameObjectFactory);

	GetSpace()->GetObjectManager().AddObject(*Archetypes::CreateShip());
	//new GameObject(ResourceGetArchetype("ship"));
}

void Level2::Update(float dt)
{
	UNREFERENCED_PARAMETER(dt);

	std::stringstream windowTitle;
	
	windowTitle << "Bullets alive: " << GetSpace()->GetObjectManager().GetObjectCount("Bullet");

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