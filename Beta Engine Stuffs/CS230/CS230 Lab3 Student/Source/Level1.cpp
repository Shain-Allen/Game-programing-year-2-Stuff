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

using std::cout;
using std::endl;

Levels::Level1::Level1()
	:Level("Level1"), lives(3)
{
}

void Levels::Level1::Load()
{
	cout << "Level1::Load" << endl;
}

void Levels::Level1::Initialize()
{
	cout << "Level1::Initialize" << endl;
}

void Levels::Level1::Update(float dt)
{
	UNREFERENCED_PARAMETER(dt);

	cout << "Level1:: Update" << endl;
	
	lives--;

	if (lives <= 0)
	{
		GetSpace()->SetLevel(new Level2);
	}
}

void Levels::Level1::Shutdown()
{
	cout << "Level1::Shutdown" << endl;
}

void Levels::Level1::Unload()
{
	cout << "Level1::Unload" << endl;
}
