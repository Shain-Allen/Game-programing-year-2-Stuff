//------------------------------------------------------------------------------
//
// File Name:	Level1.cpp
// Author(s):	Shain Allen
// Project:	Level1.cpp
// Course:	wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#include "stdafx.h"
#include "Level1.h"
#include "MonkeyMovement.h"
#include "MonkeyAnimation.h"

using namespace Beta;
using std::cout;
using std::endl;

Level1::Level1()
	: Beta::Level("LEVEL1"), monkey(nullptr)
{
}

void Level1::Load()
{
	//creating texture for monkey
	textureMonkey = ResourceGetTexture("Monkey.png");
	
	//making sprite source using monkey texture
	spriteSourceMonkey = std::make_shared<SpriteSource>(textureMonkey, "Monkey", 3, 5);

	//add animation ptr's
	animationWalk = std::make_shared<Animation>("animationWalk", spriteSourceMonkey, 8, 0, 0.15f);
	animationJump = std::make_shared<Animation>("animationJump", spriteSourceMonkey, 1, 9);
	animationIdle = std::make_shared<Animation>("animationIdle", spriteSourceMonkey, 1, 12);
}

void Level1::Initialize()
{
	cout << "Level1::Initialize" << endl;

	//get graphics engine
	GraphicsEngine& graphics = *EngineGetModule(GraphicsEngine);
	graphics.SetBackgroundColor(Colors::White);

	GetSpace()->GetObjectManager().AddObject(*CreateMonkey());
}

void Level1::Update(float dt)
{
	UNREFERENCED_PARAMETER(dt);

	//get the ability to take input
	Input* input = EngineGetModule(Input);

	//check if the player pressed 1 and restart the level
	if (input->CheckTriggered('1'))
	{
		GetSpace()->RestartLevel();
	}


}

void Level1::Shutdown()
{
	cout << "Level1::Shutdown" << endl;
}

void Level1::Unload()
{
	cout << "Level1::Unload" << endl;
}

Beta::GameObject* Level1::CreateMonkey(void)
{
	//make the monkey a game object
	monkey = new GameObject("monkey");

	//give the monkey a transform
	Transform* transform = new Transform(0.0f, 0.0f);
	transform->SetRotation(0.0f);
	transform->SetScale(Vector2D(2.0f, 2.0f));
	monkey->AddComponent(transform);

	//make the sprite
	Sprite* sprite = new Sprite;
	sprite->SetSpriteSource(spriteSourceMonkey);
	monkey->AddComponent(sprite);

	//add animator
	Animator* animator = new Animator();
	monkey->AddComponent(animator);
	animator->AddAnimation(animationWalk);
	animator->AddAnimation(animationJump);
	animator->AddAnimation(animationIdle);

	//add Rigidbody
	RigidBody* rigidBody = new RigidBody;
	monkey->AddComponent(rigidBody);

	//add monkey movement 
	MonkeyMovement* monkeyMovement = new MonkeyMovement;
	monkey->AddComponent(monkeyMovement);

	//add monkey animation
	MonkeyAnimation* monkeyAnimation = new MonkeyAnimation;
	monkey->AddComponent(monkeyAnimation);

	return monkey;
}
