//------------------------------------------------------------------------------
//
// File Name:	ScreenWrap.cpp
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
#include "ScreenWrap.h"

//------------------------------------------------------------------------------

using namespace Beta;
using std::cout;
using std::endl;

// STUDENT CODE GOES HERE

ScreenWrap::ScreenWrap()
	: Component("ScreenWrap"), transform(nullptr), rigidBody(nullptr)
{
}

void ScreenWrap::Initialize()
{
	cout << "ScreenWrap" << endl;
}

void ScreenWrap::Update(float dt)
{
	UNREFERENCED_PARAMETER(dt);

	BoundingRectangle worldsize = GetSpace()->GetCamera().GetScreenWorldDimensions();

	Transform* objectTransform = GetOwner()->GetComponent<Transform>();

	if (objectTransform->GetTranslation().x > worldsize.right + objectTransform->GetScale().x)
	{
		objectTransform->SetTranslationX(worldsize.left - objectTransform->GetScale().x);
	}

	if (objectTransform->GetTranslation().x < worldsize.left - objectTransform->GetScale().x)
	{
		objectTransform->SetTranslationX(worldsize.right + objectTransform->GetScale().x);
	}

	if (objectTransform->GetTranslation().y > worldsize.top + objectTransform->GetScale().y)
	{
		objectTransform->SetTranslationY(worldsize.bottom - objectTransform->GetScale().y);
	}

	if (objectTransform->GetTranslation().y < worldsize.bottom - objectTransform->GetScale().y)
	{
		objectTransform->SetTranslationY(worldsize.top + objectTransform->GetScale().y);
	}
}

//------------------------------------------------------------------------------

// Extra component stuff - DO NOT REMOVE
COMPONENT_SUBCLASS_DEFINITION(ScreenWrap)

