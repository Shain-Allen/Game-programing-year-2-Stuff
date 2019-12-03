//------------------------------------------------------------------------------
//
// File Name: Space.cpp
// Author(s): Shain Allen
// Project: CS230Lab3
// Course: wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#include "stdafx.h"
#include "Space.h"
#include "Level.h"

Space::Space(const std::string& name)
	: BetaObject("Space"), currentLevel(nullptr), nextLevel(nullptr), paused(false)
{
}

Space::~Space()
{
	Shutdown();
}

void Space::Update(float dt)
{
	std::cout << "Space::Update" << std::endl;

	if (nextLevel != nullptr)
	{
		ChangeLevel();
	}

	if (currentLevel != nullptr)
	{
		currentLevel->Update(dt);
	}
}

void Space::Shutdown()
{
	if (currentLevel != nullptr)
	{
		currentLevel->Shutdown();
		currentLevel->Unload();
		delete currentLevel;
		currentLevel = nullptr;
	}
}

bool Space::IsPaused() const
{
	return paused;
}

const std::string& Space::GetLevelName() const
{
	return currentLevel->GetName();
}

void Space::SetPaused(bool value)
{
	paused = value;
}

void Space::SetLevel(Level* level)
{
	nextLevel = level;
	nextLevel->SetOwner(this);
}

void Space::RestartLevel()
{
	nextLevel = currentLevel;
}

void Space::ChangeLevel()
{
	if (currentLevel != nullptr)
	{
		if (nextLevel == currentLevel)
		{
			currentLevel->Shutdown();
			currentLevel->Initialize();
		}

		if (nextLevel != currentLevel)
		{
			currentLevel->Shutdown();
			currentLevel->Unload();
			nextLevel->Load();
			nextLevel->Initialize();
		}
	}
		currentLevel = nextLevel;
		nextLevel = nullptr;
		std::cout << "Space::ChangeLevel" << std::endl;
}
