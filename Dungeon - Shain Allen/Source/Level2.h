//------------------------------------------------------------------------------
//
// File Name:	Level2.h
// Author(s):	Shain Allen
// Project:		Dungeon
// Course:		VGP2
//
// Copyright � 2019 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Function Declarations:
//------------------------------------------------------------------------------

// Initialize the memory associated with Level1.
void Level2Init(void);

// Update the Level1 game state.
// Params:
//	 dt = Change in time (in seconds) since the last game loop.
void Level2Update(float dt);

// Free any memory associated with Level1.
void Level2Shutdown(void);

