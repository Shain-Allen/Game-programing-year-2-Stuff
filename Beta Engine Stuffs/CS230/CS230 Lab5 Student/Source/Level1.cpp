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

	transform = new Transform(Vector2D(0, 0));

	sprite = new Sprite(transform, mesh);
}

void Levels::Level1::Update(float dt)
{
	UNREFERENCED_PARAMETER(dt);

	sprite->Draw();

	Beta::Input& input = *EngineGetModule(Beta::Input);

	if (input.CheckTriggered('1'))
	{
		GetSpace()->RestartLevel();
	}

	if (input.CheckTriggered('2'))
	{
		GetSpace()->SetLevel(new Level2);
	}
}

void Levels::Level1::Shutdown()
{
	cout << "Level1::Shutdown" << endl;

	delete sprite;
	delete transform;
}

void Levels::Level1::Unload()
{
	cout << "Level1::Unload" << endl;
	delete mesh;
}
