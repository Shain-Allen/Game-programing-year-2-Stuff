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

using std::cout;
using std::endl;
using Beta::Vector2D;

Levels::Level2::Level2()
	:Level("Level2"), mesh(nullptr), texture(nullptr), spriteSource(nullptr), columns(0), rows(0), sprite(nullptr), transform(nullptr), rigidBody(nullptr), animator(nullptr), animation(nullptr), animFrameStart(0), animFrameCount(8), animFrameDuration(0.2f)
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

	animFrameDuration = 0.0f;

	animation = new Animation("Animation", nullptr, animFrameCount, animFrameStart, animFrameDuration);
}

void Levels::Level2::Initialize()
{
	cout << "Level2::Initialize" << endl;

	transform = new Transform(Vector2D(0, 0));

	sprite = new Sprite(transform, mesh, spriteSource);

	animator = new Animator(sprite);

	animator->SetPlaybackSpeed(0.2f);

	animator->AddAnimation(animation);
	animator->Play(animFrameStart);
}

void Levels::Level2::Update(float dt)
{
	sprite->Draw();

	animator->Update(dt);

	if (!animator->IsDone())
		return;

	Beta::Input& input = *EngineGetModule(Beta::Input);

	if (input.CheckTriggered('1'))
	{
		GetSpace()->SetLevel(new Level1);
	}

	if (input.CheckTriggered('2'))
	{
		GetSpace()->RestartLevel();
	}
}

void Levels::Level2::Shutdown()
{
	cout << "Level2::Shutdown" << endl;
	delete animator;
	delete sprite;
	delete transform;
}

void Levels::Level2::Unload()
{
	cout << "Level2::Unload" << endl;

	delete animation;
	delete spriteSource;
}
