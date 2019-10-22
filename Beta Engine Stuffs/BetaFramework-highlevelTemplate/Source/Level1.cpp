//------------------------------------------------------------------------------
//
// File Name:	Level1.cpp
// Author(s):	Jeremy Kings (j.kings)
// Project:		BetaFramework
// Course:		WANIC VGP2 2018-2019
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "stdafx.h"
#include "Level1.h"

//------------------------------------------------------------------------------

using namespace Beta;

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Creates an instance of Level 1.
Level1::Level1()
	: Level("Level 1"), testObject(nullptr)
{
}

// Initialize the memory associated with the Level1 game state.
void Level1::Initialize()
{
	std::cout << "Level1: Initialize" << std::endl;

	// Create a new game object
	testObject = new GameObject("TestObject");

	// Create a transform component at 0,0 with scale 300,300
	Transform* transform = new Transform(0.0f, 0.0f);
	transform->SetRotation(0.0f);
	transform->SetScale(Vector2D(2.0f, 2.0f));
	testObject->AddComponent(transform);

	// Create a sprite component and set its mesh and sprite source
	//retrieve texture using the resource manager
	TexturePtr texture = ResourceGetTexture("Monkey.png");
	//texture, name, number of colums, number of rows
	SpriteSourcePtr spritesource = std::make_shared<SpriteSource>(texture, "Monkey", 3, 5);
	Sprite* sprite = new Sprite();
	sprite->SetSpriteSource(spritesource);
	testObject->AddComponent(sprite);

	//add animator componet
	Animator* animator = new Animator();
	testObject->AddComponent(animator);

	//create animations
	//NOTE:: Animations require the following
	// name, Spritesource, Frame Count, frame start, frameduration
	AnimationPtr walkAnim = std::make_shared<Animation>("monkey walk", spritesource, 8, 0, 0.1f);

	size_t walkIndex = animator->AddAnimation(walkAnim);


	// Initialize the object
	//testObject->Initialize();
	//update, Draw, delete the object for us
	GetSpace()->GetObjectManager().AddObject(*testObject);
	animator->Play(walkIndex);
}

// Update the Level1 game state.
// Params:
//	 dt = Change in time (in seconds) since the last game loop.
void Level1::Update(float dt)
{
	UNREFERENCED_PARAMETER(dt);

	Input* input = EngineGetModule(Input);

	// If the user presses the '1' key, restart the current level
	if (input->CheckTriggered('1'))
		GetSpace()->RestartLevel();

	// If the user presses the 'D' key, delete the object
	if (input->CheckTriggered('D'))
	{
		//delete testObject;
		//testObject = nullptr;
		testObject->Destroy();
		testObject = nullptr;
	}

	// If the object exists
	/*if (testObject)
	{
		// Update and draw
		testObject->Update(dt);
		testObject->Draw();
	}*/

	if (testObject != nullptr)
	{
		Transform* transform = testObject->GetComponent<Transform>();
		Vector2D position = transform->GetTranslation();

		if (input->CheckHeld(VK_RIGHT))
		{
			position.x += 2.0f * dt;
		}
		transform->SetTranslation(position);

	}
	
}

// Shutdown any memory associated with the Level1 game state.
void Level1::Shutdown()
{
	std::cout << "Level1::Shutdown" << std::endl;

	//delete testObject;
}
