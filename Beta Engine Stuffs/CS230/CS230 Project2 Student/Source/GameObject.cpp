//------------------------------------------------------------------------------
//
// File Name: GameObject.cpp
// Author(s): Shain Allen
// Project: CS230Project2
// Course: wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#include "stdafx.h"
#include "GameObject.h"
#include "Component.h"
#include "Space.h"

GameObject::GameObject(const std::string& name)
	: BetaObject("GameObject"), numComponents(0), isDestroyed(false), components()
{
}

GameObject::GameObject(const GameObject& other)
	: BetaObject("GameObject"), numComponents(other.numComponents), isDestroyed(false), components()
{
	for (int i = 0; i < other.numComponents; i++)
	{
		components[i] = other.components[i];
	}
}

GameObject::~GameObject()
{
	for (int i = 0; i < numComponents; i++)
	{
		delete components[i];
	}
}

void GameObject::Initialize()
{
	for (int i = 0; i < numComponents; i++)
	{
		components[i]->Initialize();
	}
}

void GameObject::Update(float dt)
{
	for (int i = 0; i < numComponents; i++)
	{
		components[i]->Update(dt);
	}
}

void GameObject::FixedUpdate(float dt)
{
	for (int i = 0; i < numComponents; i++)
	{
		components[i]->FixedUpdate(dt);
	}
}

void GameObject::Draw()
{
	for (int i = 0; i < numComponents; i++)
	{
		components[i]->Draw();
	}
}

void GameObject::AddComponent(Component* component)
{
	components[++numComponents] = component;
}

Component* GameObject::GetComponent(const std::string& name)
{
	for (int i = 0; i < numComponents; i++)
	{
		if (components[i]->GetName() == name)
		{
			return components[i];
		}
	}
	
	return nullptr;
}

void GameObject::Destroy()
{
	isDestroyed = true;
}

bool GameObject::IsDestroyed() const
{
	return isDestroyed;
}

Space* GameObject::GetSpace() const
{
	return static_cast<Space*>(GetOwner());
}
