//------------------------------------------------------------------------------
//
// File Name: Asteroids.cpp
// Author(s): Shain Allen
// Project: CS230Project1
// Course: wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#include "stdafx.h"
#include "Asteroids.h"
#include "Archetypes.h"
#include "Level1.h"
#include "Level2.h"
#include "PlayerShip.h"
#include <sstream>

using namespace Beta;

Asteroids::Asteroids()
	: Level("Asteroids"), asteroidSpawnInitial(8), asteroidSpawnMaximum(20), asteroidSpawnCount(0), asteroidWaveCount(0), playerShip(nullptr), asteroidHighScore(0)
{
}

void Asteroids::Load()
{
	asteroidArchetype = Archetypes::CreateAsteroidArchetype();

	GameObject::GetArchetypeManager().Add(asteroidArchetype->GetName(), asteroidArchetype);

	bulletArchetype = Archetypes::CreateBulletArchetype();

	GameObject::GetArchetypeManager().Add(bulletArchetype->GetName(), bulletArchetype);

	//get graphics engine
	GraphicsEngine& graphics = *EngineGetModule(GraphicsEngine);

	graphics.SetBackgroundColor(Colors::Black);
}

void Asteroids::Initialize()
{
	asteroidWaveCount = 0;

	asteroidSpawnCount = asteroidSpawnInitial;

	GameObject* ship = Archetypes::CreateShip();

	playerShip = ship->GetComponent<PlayerShip>();

	GetSpace()->GetObjectManager().AddObject(*ship);

	playerShip = ship->GetComponent<PlayerShip>();
}

void Asteroids::Update(float dt)
{
	UNREFERENCED_PARAMETER(dt);

	if (GetSpace()->GetObjectManager().GetObjectCount("Asteroid") == 0)
	{
		SpawnAsteroidWave();
	}

	UpdateScore();
	SwitchLevels();
}

void Asteroids::Shutdown()
{
	if (playerShip->GetScore() > asteroidHighScore)
	{
		asteroidHighScore = playerShip->GetScore();
	}
}

void Asteroids::SpawnAsteroid(void)
{
	GameObject* flyingRock = new GameObject(asteroidArchetype);

	GetSpace()->GetObjectManager().AddObject(*flyingRock);
}

void Asteroids::SpawnAsteroidWave(void)
{
	asteroidWaveCount++;

	for (unsigned int i = 0; i < asteroidSpawnCount; i++)
	{
		SpawnAsteroid();
	}

	if (asteroidSpawnCount < asteroidSpawnMaximum)
	{
		asteroidSpawnCount++;
	}
}

void Asteroids::UpdateScore()
{
	std::stringstream windowTitle;

	windowTitle << "Asteroids: Wave	= " << asteroidWaveCount << ", Score = " << playerShip->GetScore() << "High score = " << asteroidHighScore;

	WindowSystem& windowSystem = *EngineGetModule(WindowSystem);

	windowSystem.SetWindowTitle(windowTitle.str());
}

void Asteroids::SwitchLevels()
{
	//get the ability to take input
	Input* input = EngineGetModule(Input);

	//check if the player pressed 1 and restart the level
	if (input->CheckTriggered('1'))
	{
		GetSpace()->SetLevel<Level1>();
	}

	if (input->CheckTriggered('2'))
	{
		GetSpace()->SetLevel<Level2>();
	}

	if (input->CheckTriggered('3'))
	{
		GetSpace()->RestartLevel();
	}
}

