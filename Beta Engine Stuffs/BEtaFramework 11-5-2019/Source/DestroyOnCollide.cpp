#include "stdafx.h"
#include "DestroyOnCollide.h"

DestroyOnCollide::DestroyOnCollide()
	: Component("DestoryOnCollide")
{

}

void DestroyOnCollide::Initialize()
{
	//Register for collision Event
	//Three params:
	//	Source (Where even comes from, Event name,
	//	Event Handler Function
	RegisterEventHandler(GetOwner(), "CollisionStarted", &DestroyOnCollide::OnCollisionStarted);
}

void DestroyOnCollide::OnCollisionStarted(const Beta::Event& event)
{
	//Destory the object that owns this componet
	GetOwner()->Destroy();
}

//extra Componet stuff - DO NOT REMOVE
COMPONENT_SUBCLASS_DEFINITION(DestroyOnCollide);
