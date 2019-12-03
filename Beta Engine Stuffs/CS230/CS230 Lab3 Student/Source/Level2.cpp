//------------------------------------------------------------------------------
//
// File Name: Level2.cpp
// Author(s): Shain Allen
// Project: CS230Lab3
// Course: wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#include "stdafx.h"
#include "Level2.h"
#include "Space.h"

using std::cout;
using std::endl;

Levels::Level2::Level2()
	:Level("Level2"), lives(2), maxHealth(2), currentHealth(0)
{
}

void Levels::Level2::Load()
{
	cout << "Level2::load" << endl;
}

void Levels::Level2::Initialize()
{
	cout << "Level2::Initialize" << endl;
	currentHealth = maxHealth;
}

void Levels::Level2::Update(float dt)
{
	cout << "Level2::Update" << endl;

	currentHealth--;
	
	if (currentHealth <= 0)
	{
		lives--;
		
		if (lives <= 0)
		{
			Beta::EngineCore::GetInstance().Stop();
		}
		else
		{
			GetSpace()->RestartLevel();
		}
	}
}

void Levels::Level2::Shutdown()
{
	cout << "Level2::Shutdown" << endl;
}

void Levels::Level2::Unload()
{
	cout << "Level2::Unload" << endl;
}
