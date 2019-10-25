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
using namespace Beta;
using std::cout;
using std::endl;

Level1::Level1()
	: Beta::Level("LEVEL1")
{
}

void Level1::Load()
{
	//creating texture for monkey
	textureMonkey = ResourceGetTexture("Monkey.png");
	
	//making sprite source using monkey texture
	spriteSourceMonkey = std::make_shared<SpriteSource>(textureMonkey, "Monkey", 3, 5);

}

void Level1::Initialize()
{
	cout << "Level1::Initialize" << endl;

	//get graphics engine
	GraphicsEngine& graphics = *EngineGetModule(GraphicsEngine);
	graphics.SetBackgroundColor(Colors::White);

	GetSpace()->GetObjectManager().AddObject(CreateMonkey());
}

void Level1::Update(float dt)
{
}

void Level1::Shutdown()
{
}

void Level1::Unload()
{
}

Beta::GameObject* Level1::CreateMonkey(void)
{
	return nullptr;
}
