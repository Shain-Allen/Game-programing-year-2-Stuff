//------------------------------------------------------------------------------
//
// File Name:	Level3.c
// Author(s):	Shain Allen
// Project:		Dungeon
// Course:		VGP2
//
// Copyright © 2019 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "stdafx.h"
#include "Level3.h"

#include "curses.h" // Colors

#include "GameObject.h" // GameObject
#include "Vector2D.h" // Vector2D

#include "Player.h" // Update, Collisions
#include "Enemy.h" // Update
#include "Wall.h" // Collisions
#include "Engine.h" // DrawText
#include "ObjectManager.h" // AddObject, DestroyAllObjects

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Consts:
//------------------------------------------------------------------------------

#define NUM_WALLS 22

static const float levelWidth = 49.0f;
static const float levelHeight = 19.0f;

static const Vector2D levelCenter = { 0.0f, 0.0f };

//------------------------------------------------------------------------------
// Private Function Declarations:
//------------------------------------------------------------------------------

void Level3CreateWalls(GameObject** walls);

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Initialize the memory associated with the Level3 game state.
void Level3Init(void)
{
	// Create the player object
	Vector2D startPosition;
	startPosition.x = 3.0f;
	startPosition.y = 3.0f;
	GameObject* player = GameObjectCreate(startPosition.x, startPosition.y, 'o', COLOR_YELLOW, PlayerUpdate, NULL);

	// Create other game objects
	GameObject* door = GameObjectCreate(levelCenter.x + 40.0f, levelCenter.y + 14.0f, 'G', COLOR_GREEN, NULL, NULL);
	GameObject* enemy = GameObjectCreate(levelCenter.x + 13.0f, levelCenter.y + 17.0f, 'X', COLOR_RED, EnemyUpdate, NULL);
	GameObject* walls[NUM_WALLS];
	Level3CreateWalls(walls);

	// Check for player collision with walls
	for (int i = 0; i < NUM_WALLS; ++i)
		GameObjectAddCollisionPair(player, walls[i], WallCollision);

	// Check other collisions
	GameObjectAddCollisionPair(player, door, PlayerCollisionGoal);
	GameObjectAddCollisionPair(player, enemy, PlayerCollisionEnemy);

	// Register objects with Object Manager to ensure they are updated
	ObjectManagerAddObject(player);
	ObjectManagerAddObject(door);
	ObjectManagerAddObject(enemy);

	// Create a color pair to use later
	EngineSetColorPair(0, COLOR_WHITE, COLOR_RED);
}

// Update the Level3 game state.
// Params:
//	 dt = Change in time (in seconds) since the last game loop.
void Level3Update(float dt)
{
	UNREFERENCED_PARAMETER(dt);

	// Draw level title
	EngineDrawTextColorPair("DUNGEON", 0, levelCenter.x - 3.0f, levelCenter.y - 14.0f);
	EngineDrawText("LEVEL 2", COLOR_YELLOW, levelCenter.x - 3.0f, levelCenter.y - 12.0f);
}

// Free any memory associated with the Level3 game state.
void Level3Shutdown(void)
{
	ObjectManagerDestroyAllObjects();
}

//------------------------------------------------------------------------------
// Private Function Declarations:
//------------------------------------------------------------------------------

void Level3CreateWalls(GameObject** walls)
{
	// Top
	walls[0] = WallCreate(levelCenter.x + (levelWidth / 2), levelCenter.y + 1.0f, levelWidth, 1.0f);

	// Bottom
	walls[1] = WallCreate(levelCenter.x + (levelWidth / 2), levelCenter.y + 19.0f, levelWidth, 1.0f);

	// Left
	walls[2] = WallCreate(levelCenter.x + 1.0f, levelCenter.y + (levelHeight / 2), 1.0f, levelHeight + 1.0f);

	// Right
	walls[3] = WallCreate(levelCenter.x + 50.0f, levelCenter.y + (levelHeight / 2), 1.0f, levelHeight);

	//vertical part of the plus
	walls[4] = WallCreate(levelCenter.x + 25.0f, levelCenter.y + 10.0f, 1.0f, 9.0f);

	//flat part of the plus
	walls[5] = WallCreate(levelCenter.x + 25.0f, levelCenter.y + 10.0f, 15.0f, 1.0f);

	//backslash grabage
	walls[6] = WallCreate(levelCenter.x + 10, levelCenter.y + 4, 1.0f, 1.0f);

	walls[7] = WallCreate(levelCenter.x + 9, levelCenter.y + 5, 1.0f, 1.0f);

	walls[8] = WallCreate(levelCenter.x + 8, levelCenter.y + 6, 1.0f, 1.0f);

	walls[9] = WallCreate(levelCenter.x + 7, levelCenter.y + 7, 1.0f, 1.0f);

	walls[10] = WallCreate(levelCenter.x + 6, levelCenter.y + 8, 1.0f, 1.0f);

	walls[11] = WallCreate(levelCenter.x + 31, levelCenter.y + 3, 1.0f, 1.0f);

	walls[12] = WallCreate(levelCenter.x + 33, levelCenter.y + 4, 1.0f, 1.0f);

	walls[13] = WallCreate(levelCenter.x + 35, levelCenter.y + 5, 1.0f, 1.0f);

	walls[14] = WallCreate(levelCenter.x + 37, levelCenter.y + 6, 1.0f, 1.0f);

	walls[15] = WallCreate(levelCenter.x + 39, levelCenter.y + 7, 1.0f, 1.0f);

	walls[16] = WallCreate(levelCenter.x + 41, levelCenter.y + 8, 1.0f, 1.0f);

	walls[17] = WallCreate(levelCenter.x + 12, levelCenter.y + 12, 1.0f, 1.0f);

	walls[18] = WallCreate(levelCenter.x + 11, levelCenter.y + 13, 1.0f, 1.0f);

	walls[19] = WallCreate(levelCenter.x + 10, levelCenter.y + 14, 1.0f, 1.0f);

	walls[20] = WallCreate(levelCenter.x + 9, levelCenter.y + 15, 1.0f, 1.0f);

	walls[21] = WallCreate(levelCenter.x + 8, levelCenter.y + 16, 1.0f, 1.0f);

	// Register objects with Object Manager to ensure they are updated
	for (int i = 0; i < NUM_WALLS; ++i)
		ObjectManagerAddObject(walls[i]);
}