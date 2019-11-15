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

Asteroids::Asteroids()
	: Level("Asteroids"), asteroidSpawnInitial(8), asteroidSpawnMaximum(20), asteroidSpawnCount(0), asteroidWaveCount(0), playerShip(nullptr), asteroidHighScore(0)
{
}

void Asteroids::Load()
{
	asteroidArchetype = Archetypes::CreateAsteroidArchetype();
}

void Asteroids::Initialize()
{
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

