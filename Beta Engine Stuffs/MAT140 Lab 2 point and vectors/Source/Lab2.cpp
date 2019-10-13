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
using Beta::Vector2D;

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

	//check if the left arrow key is pressed
	if (input.CheckTriggered(VK_LEFT))
	{
		if (shape == 0)
		{
			shape = ShapeNum - 1;
		}
		else
		{
			shape -= 1;
		}
		
	}

	//check if the right arrow key is pressed
	if (input.CheckTriggered(VK_RIGHT))
	{
		if (shape == ShapeNum - 1)
		{
			shape = 0;
		}
		else
		{
			shape += 1;
		}
	}

	shapeFunctions[shape]();
}

void Lab2::Shutdown()
{
	cout << "Lab2:Shutdown" << endl;
}

void Lab2::DrawLine(const Beta::Vector2D& start, const Beta::Vector2D& end)
{
	using namespace Beta;
	// Get GraphicsEngine system
	GraphicsEngine& graphics = *EngineGetModule(GraphicsEngine);

	// Get DebugDraw system
	DebugDraw& debug = *EngineGetModule(DebugDraw);

	// Store reference to default camera
	Camera& camera = graphics.GetDefaultCamera();

	debug.AddLineToList(start, end, Colors::Green);
	debug.EndLineList(camera);
}

void Lab2::CreateTriangle()
{
	Vector2D pPlusV = pointP + vectorV;
	Vector2D pPlusU = pointP + vectorU;

	DrawLine(pointP, pPlusV);
	DrawLine(pointP, pPlusU);
	DrawLine(pPlusV, pPlusU);
}

void Lab2::CreateParallelogram()
{
	Vector2D pointV = pointP + vectorV;
	Vector2D pointU = pointP + vectorU;
	Vector2D pointE = pointP + (vectorV + vectorU);

	DrawLine(pointP, pointV);
	DrawLine(pointP, pointU);
	DrawLine(pointV, pointE);
	DrawLine(pointU, pointE);
}

void Lab2::CreateTriforce()
{
	Vector2D pointV = pointP + vectorV;
	Vector2D pointU = pointP + vectorU;
	Vector2D pointA = pointP + (0.5f * vectorV);
	Vector2D pointE = pointP + (0.5f * vectorU);
	Vector2D pointF = pointP + (vectorV + vectorU) / 2;

	DrawLine(pointP, pointV);
	DrawLine(pointP, pointU);
	DrawLine(pointV, pointU);
	DrawLine(pointA, pointE);
	DrawLine(pointE, pointF);
	DrawLine(pointA, pointF);
}

void Lab2::CreateFace()
{

}

void Lab2::CreateHexagon()
{
	
	Vector2D pointV = pointP + vectorV;
	Vector2D pointU = pointP + vectorU;
	Vector2D pointA = pointP + ((1/3) * vectorV);
	Vector2D pointB = pointP + ((1/3) * vectorU);
	Vector2D pointC = pointP + ((2/3) * vectorU);
	Vector2D pointD;
	Vector2D pointE;
	Vector2D pointF = pointP + ((2/3) * vectorV);

	DrawLine(pointA, pointB);
	DrawLine(pointB, pointC);
	DrawLine(pointC, pointD);
	DrawLine(pointD, pointE);
	DrawLine(pointE, pointF);
	DrawLine(pointF, pointA);
}

void Lab2::CreateDiamondCut()
{

}
