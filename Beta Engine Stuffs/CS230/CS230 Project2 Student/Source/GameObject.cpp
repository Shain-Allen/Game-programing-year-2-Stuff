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
	: BetaObject(name), numComponents(0), isDestroyed(false), components()
{
}

GameObject::GameObject(const GameObject& other)
	: BetaObject("GameObject"), numComponents(other.numComponents), isDestroyed(false), components()
{
	for (unsigned int i = 0; i < other.numComponents; i++)
	{
		components[i] = other.components[i];
	}
}

GameObject::~GameObject()
{
	for (unsigned int i = 0; i < numComponents; i++)
	{
		delete components[i];
	}
}

void GameObject::Initialize()
{
	for (unsigned int i = 0; i < numComponents; i++)
	{
		components[i]->Initialize();
	}
}

void GameObject::Update(float dt)
{
	for (unsigned int i = 0; i < numComponents; i++)
	{
		components[i]->Update(dt);
		std::cout << "Updateing" << std::endl;
	}
}

void GameObject::FixedUpdate(float dt)
{
	for (unsigned int i = 0; i < numComponents; i++)
	{
		components[i]->FixedUpdate(dt);
	}
}

void GameObject::Draw()
{
	for (unsigned int i = 0; i < numComponents; i++)
	{
			components[i]->Draw();
	}
}

void GameObject::AddComponent(Component* component)
{
	components[numComponents] = component;
	components[numComponents++]->SetOwner(this);
}

Component* GameObject::GetComponent(const std::string& name_)
{
	for (unsigned int i = 0; i < numComponents; i++)
	{
		if (components[i]->GetName() == name_)
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
