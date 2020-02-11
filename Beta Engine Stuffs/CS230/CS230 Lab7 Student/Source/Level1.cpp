//------------------------------------------------------------------------------
//
// File Name: Level1.cpp
// Author(s): Shain Allen
// Project: CS230Lab3
// Course: wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#include "stdafx.h"
#include "Level1.h"
#include "Level2.h"
#include "Space.h"
#include "MeshHelper.h"
#include "Sprite.h"
#include "Transform.h"
#include "RigidBody.h"
#include "GameObject.h"
#include "Archetypes.h"
#include "GameObjectManager.h"
#include "Level3.h"


using std::cout;
using std::endl;
using Beta::Vector2D;

Level1::Level1()
	:Level("Level1"), meshShip(nullptr), meshBullet(nullptr)
{
}

void Level1::Load()
{
	cout << "Level1::Load" << endl;

	using namespace Beta;

	meshShip = CreateTriangleMesh(Colors::Blue, Colors::Green, Colors::Red);
	meshBullet = CreateTriangleMesh(Colors::Red, Colors::Red, Colors::Red);
	GetSpace()->GetObjectManager().AddArchetype(*Archetypes::CreateBulletArchetype(meshBullet));
}

void Level1::Initialize()
{
	cout << "Level1::Initialize" << endl;

	GetSpace()->GetObjectManager().AddObject(*Archetypes::CreateShip(meshShip));
}

void Level1::Update(float dt)
{
	UNREFERENCED_PARAMETER(dt);

	Beta::Input& input = *EngineGetModule(Beta::Input);

	if (input.CheckTriggered('1'))
	{
		GetSpace()->RestartLevel();
	}

	if (input.CheckTriggered('2'))
	{
		GetSpace()->SetLevel(new Level2);
	}

	if (input.CheckTriggered('3'))
	{
		GetSpace()->SetLevel(new Level3);
	}
}

void Level1::Unload()
{
	cout << "Level1::Unload" << endl;
	delete meshShip;
}
