//------------------------------------------------------------------------------
//
// File Name: GameObjectManager.cpp
// Author(s): Shain Allen
// Project: CS230Project2
// Course: wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#include "stdafx.h"
#include "GameObjectManager.h"
#include "GameObject.h"
#include "Space.h"
#include "Component.h"

GameObjectManager::GameObjectManager(Space* space)
	: BetaObject("GameObjectManager", space), gameObjectActiveList(), numObjects(0), gameObjectArchetypes(), numArchetypes(0), fixedUpdateDt(1 / 60), timeAccumulator(0)
{
}

GameObjectManager::~GameObjectManager()
{
	Shutdown();
	Unload();
}

void GameObjectManager::Update(float dt)
{
	if (!static_cast<Space*>(GetOwner())->IsPaused)
	{
		VariableUpdate(dt);
		FixedUpdate(dt);
	}

	DestroyObjects();
	Draw();
}

void GameObjectManager::Shutdown(void)
{
	for (int i = 0; i < numObjects; i++)
	{
		delete gameObjectActiveList[i];
	}
}

void GameObjectManager::Unload(void)
{
	for (int i = 0; i < numArchetypes; i++)
	{
		delete gameObjectArchetypes[i];
	}
}

void GameObjectManager::AddObject(GameObject& gameObject)
{
	if (numObjects < maxObjects)
	{
		gameObject.SetOwner(static_cast<Space*>(GetOwner()));
		gameObject.Initialize();
		*gameObjectActiveList[++numObjects] = gameObject;
	}
	else
	{
		return;
	}
}

void GameObjectManager::AddArchetype(GameObject& gameObject)
{
	if (numArchetypes < maxArchetypes)
	{
		gameObjectArchetypes[++numArchetypes];
	}
	else
	{
		return;
	}
}

GameObject* GameObjectManager::GetObjectByName(const std::string& objectName) const
{
	for (int i = 0; i < numObjects; i++)
	{
		if (gameObjectActiveList[i]->GetName() == objectName)
		{
			return gameObjectActiveList[i];
		}
	}
	return;
}

GameObject* GameObjectManager::GetArchetypeByName(const std::string& objectName) const
{
	for (int i = 0; i < numArchetypes; i++)
	{
		if (gameObjectArchetypes[i]->GetName() == objectName)
		{
			return gameObjectArchetypes[i];
		}
	}
	return;
}

size_t GameObjectManager::GetObjectCount(const std::string& objectName) const
{
	size_t objectCount = 0;

	for (int i = 0; i < numObjects; i++)
	{
		if (gameObjectActiveList[i]->GetName() == objectName)
		{
			objectCount++;
		}
	}
	return objectCount;
}

void GameObjectManager::VariableUpdate(float dt)
{
	for (int i = 0; i < numObjects; i++)
	{
		gameObjectActiveList[i]->Update;
	}
}

void GameObjectManager::FixedUpdate(float dt)
{
	timeAccumulator += dt;

	while (timeAccumulator >= fixedUpdateDt)
	{
		for (int i = 0; i < numObjects; i++)
		{
			gameObjectActiveList[i]->FixedUpdate(fixedUpdateDt);
			timeAccumulator -= fixedUpdateDt;
		}
	}
}

void GameObjectManager::DestroyObjects()
{
	for (int i = 0; i < numObjects; i++)
	{
		if (gameObjectActiveList[i]->IsDestroyed)
		{
			delete gameObjectActiveList[i];
			gameObjectActiveList[i] = gameObjectActiveList[--numObjects];
		}
	}
}

void GameObjectManager::Draw(void)
{
	for (int i = 0; i < numObjects; i++)
	{
		gameObjectActiveList[i]->Draw();
	}
}
