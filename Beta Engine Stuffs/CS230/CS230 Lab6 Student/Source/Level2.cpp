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
#include "Animation.h"
#include "Animator.h"
#include "Level1.h"
#include "Transform.h"
#include "RigidBody.h"
#include "GameObject.h"
#include "Component.h"
#include "GameObjectManager.h"
#include "Archetypes.h"
#include "Level3.h"

using std::cout;
using std::endl;
using Beta::Vector2D;

Level2::Level2()
	:Level("Level2"), mesh(nullptr), texture(nullptr), spriteSource(nullptr), columns(0), rows(0), animation(nullptr), animFrameStart(0), animFrameCount(8), animFrameDuration(0.2f)
{
}

void Level2::Load()
{
	cout << "Level2::Load" << endl;

	using namespace Beta;

	//GraphicsEngine& graphics = *EngineGetModule(GraphicsEngine);

	texture = Texture::CreateTextureFromFile("Monkey.png");

	spriteSource = new SpriteSource(texture, "Monkey", 3, 5);

	Vector2D spriteDimensions(spriteSource->GetTextureDimensions());

	mesh = CreateQuadMesh(Vector2D(1 / spriteDimensions.x, 1 / spriteDimensions.y), Vector2D(0.5f, 0.5f));

	animation = new Animation("Animation", nullptr, animFrameCount, animFrameStart, animFrameDuration);
}

void Level2::Initialize()
{
	cout << "Level2::Initialize" << endl;

	GetSpace()->GetObjectManager().AddObject(*Archetypes::CreateMonkey(mesh, spriteSource, animation));
}

void Level2::Update(float dt)
{
	UNREFERENCED_PARAMETER(dt);
	Beta::Input& input = *EngineGetModule(Beta::Input);

	if (input.CheckTriggered('1'))
	{
		GetSpace()->SetLevel(new Level1);
	}

	if (input.CheckTriggered('2'))
	{
		GetSpace()->RestartLevel();
	}

	if (input.CheckTriggered('3'))
	{
		GetSpace()->SetLevel(new Level3);
	}
}

void Level2::Unload()
{
	cout << "Level2::Unload" << endl;

	delete animation;
	delete spriteSource;
}
