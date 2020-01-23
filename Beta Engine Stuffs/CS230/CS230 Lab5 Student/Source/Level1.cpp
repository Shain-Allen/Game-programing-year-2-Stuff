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
#include "Behaviors.h"

using std::cout;
using std::endl;
using Beta::Vector2D;

Levels::Level1::Level1()
	:Level("Level1"), mesh(nullptr), sprite(nullptr), transform(nullptr), rigidBody(nullptr)
{
}

void Levels::Level1::Load()
{
	cout << "Level1::Load" << endl;

	using namespace Beta;

	mesh = CreateTriangleMesh(Colors::Blue, Colors::Green, Colors::Red);
}

void Levels::Level1::Initialize()
{
	cout << "Level1::Initialize" << endl;

	transform = new Transform(Vector2D(0, 0), Vector2D(1,1));

	rigidBody = new RigidBody(transform);

	sprite = new Sprite(transform, mesh);
}

void Levels::Level1::Update(float dt)
{
	Beta::Input& input = *EngineGetModule(Beta::Input);

	if (input.CheckTriggered('1'))
	{
		GetSpace()->RestartLevel();
	}

	if (input.CheckTriggered('2'))
	{
		GetSpace()->SetLevel(new Level2);
	}

	Behaviors::UpdateShip(transform, rigidBody);
	sprite->Draw();
	rigidBody->Update(dt);
	rigidBody->FixedUpdate(dt);
}

void Levels::Level1::Shutdown()
{
	cout << "Level1::Shutdown" << endl;

	delete sprite;
	delete rigidBody;
	delete transform;
}

void Levels::Level1::Unload()
{
	cout << "Level1::Unload" << endl;
	delete mesh;
}
