//------------------------------------------------------------------------------
//
// File Name: Component.cpp
// Author(s): Shain Allen
// Project: CS230Project2
// Course: wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#include "stdafx.h"
#include "Component.h"
#include "Space.h"
#include "GameObject.h"

Component::Component(const std::string& name)
	:BetaObject(name)
{
}

GameObject* Component::GetOwner() const
{
	return static_cast<GameObject*>(BetaObject::GetOwner());
}
