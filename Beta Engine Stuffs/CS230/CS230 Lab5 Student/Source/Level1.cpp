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

using std::cout;
using std::endl;

Levels::Level1::Level1()
	:Level("Level1"), mesh(nullptr), sprite(nullptr)
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

	sprite = new Sprite(nullptr, mesh);
}

void Levels::Level1::Update(float dt)
{
	UNREFERENCED_PARAMETER(dt);

	sprite->Draw();
}

void Levels::Level1::Shutdown()
{
	cout << "Level1::Shutdown" << endl;

	delete sprite;
}

void Levels::Level1::Unload()
{
	cout << "Level1::Unload" << endl;
	delete mesh;
}
