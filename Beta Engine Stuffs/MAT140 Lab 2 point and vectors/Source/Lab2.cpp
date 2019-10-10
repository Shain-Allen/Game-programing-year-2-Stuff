//------------------------------------------------------------------------------
//
// File Name:	Lab2.cpp
// Author(s):	Shain Allen
// Project:		Lab2
// Course:		MAT140
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#include "stdafx.h"
#include "Lab2.h"
#include "Animator.h"

using std::cout;
using std::endl;

const Beta::Vector2D& Lab2::pointP = Animator::GetPointP();
const Beta::Vector2D& Lab2::vectorU = Animator::GetVectorU();
const Beta::Vector2D& Lab2::vectorV = Animator::GetVectorV();

Lab2::ShapeVoidFunctionPtr Lab2::shapeFunctions[ShapeNum] =
{
	CreateTriangle,
	CreateParallelogram,
	CreateTriforce,
	CreateFace,
	CreateHexagon,
	CreateDiamondCut,
	// Add other function names here
};

Lab2::Lab2()
	: BetaObject("Lab2"), shape(0)
{
	
}

void Lab2::Initialize()
{
	cout << "Lab2::Initialize" << endl;
	// Use Beta namespace
	using namespace Beta;
	// Get GraphicsEngine system
	GraphicsEngine& graphics = *EngineGetModule(GraphicsEngine);
	graphics.SetBackgroundColor(Colors::White);
}

void Lab2::Update(float dt)
{
	using namespace Beta;

	Input& input = *EngineGetModule(Input);

	if (input.CheckTriggered())
	{

	}
}

void Lab2::Shutdown()
{
	cout << "Lab2:Shutdown" << endl;
}

void Lab2::DrawLine(const Beta::Vector2D& start, const Beta::Vector2D& end)
{

}

void Lab2::CreateTriangle()
{

}

void Lab2::CreateParallelogram()
{

}

void Lab2::CreateTriforce()
{

}

void Lab2::CreateFace()
{

}

void Lab2::CreateHexagon()
{

}

void Lab2::CreateDiamondCut()
{

}
