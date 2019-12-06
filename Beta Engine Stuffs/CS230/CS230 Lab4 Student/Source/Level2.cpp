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
#include "MeshHelper.h"
#include "Sprite.h"
#include "SpriteSource.h"

using std::cout;
using std::endl;

Levels::Level2::Level2()
	:Level("Level2"), mesh(nullptr), texture(nullptr), spriteSource(nullptr), columns(0), rows(0), sprite(nullptr), animator(nullptr), animation(nullptr), animFrameStart(0), animFrameCount(0), animFrameDuration(0), lives(2), maxHealth(2), currentHealth(0)
{
}

void Levels::Level2::Load()
{
	cout << "Level2::Load" << endl;

	using namespace Beta;

	//GraphicsEngine& graphics = *EngineGetModule(GraphicsEngine);

	texture = Texture::CreateTextureFromFile("Monkey.png");

	spriteSource = new SpriteSource(texture, "Monkey", 3, 5);

	Vector2D spriteDimensions(spriteSource->GetTextureDimensions());

	mesh = CreateQuadMesh(Vector2D(1 / spriteDimensions.x, 1 / spriteDimensions.y), Vector2D(0.5f, 0.5f));
}

void Levels::Level2::Initialize()
{
	cout << "Level2::Initialize" << endl;
	currentHealth = maxHealth;

	sprite = new Sprite(mesh, spriteSource);
}

void Levels::Level2::Update(float dt)
{
	//cout << "Level2::Update" << endl;
	UNREFERENCED_PARAMETER(dt);

	sprite->Draw();

	/*
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
	*/
}

void Levels::Level2::Shutdown()
{
	cout << "Level2::Shutdown" << endl;

	delete sprite;
}

void Levels::Level2::Unload()
{
	cout << "Level2::Unload" << endl;

	delete spriteSource;
}
