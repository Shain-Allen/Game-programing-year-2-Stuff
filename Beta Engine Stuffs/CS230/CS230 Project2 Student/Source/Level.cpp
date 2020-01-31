//------------------------------------------------------------------------------
//
// File Name: Level.cpp
// Author(s): Shain Allen
// Project: CS230Lab3
// Course: wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#include "stdafx.h"
#include "Level.h"
#include "Space.h"

Level::Level(const std::string& name)
	: BetaObject(name)
{
}

Space* Level::GetSpace() const
{
	return static_cast<Space*>(GetOwner());
}
