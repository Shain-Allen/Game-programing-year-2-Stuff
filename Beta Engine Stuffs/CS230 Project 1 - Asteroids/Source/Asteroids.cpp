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
}

void Asteroids::Update(float dt)
{
	UNREFERENCED_PARAMETER(dt);
}

void Asteroids::Shutdown()
{
}

void Asteroids::SpawnAsteroid(void)
{
}

void Asteroids::SpawnAsteroidWave(void)
{
}

void Asteroids::UpdateScore()
{
}

void Asteroids::SwitchLevels()
{
}

