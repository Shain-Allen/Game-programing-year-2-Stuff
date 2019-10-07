//------------------------------------------------------------------------------
//
// File Name:	Lab1.cpp
// Author(s):	Shain Allen
// Project:		Lab1
// Course:		MAT140
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#include "stdafx.h"	//precomplied header File
#include "Lab1.h"

using std::endl;
using std::cout;

Lab1::Lab1()
	:BetaObject("Lab1"), pi(float(M_PI)), lineLength(2), rotationalVelocity(1.0f/60.0f), origin(0,0)
{
	angle1 = pi / 2;
	angle2 = pi / 2;
	angle3 = pi / 2;
}

void Lab1::Initialize()
{
	cout << "Lab1:Initialize" << endl;
	// Use Beta namespace
	using namespace Beta;
	// Get GraphicsEngine system
	GraphicsEngine& graphics = *EngineGetModule(GraphicsEngine);
	graphics.SetBackgroundColor(Colors::White);

}

void Lab1::Update(float dt)
{
	cout << "Lab1:Update" << dt << endl;
	//use Beta namespace
	using namespace Beta;
	//get GraphicsEngine System
	GraphicsEngine& graphics = *EngineGetModule(GraphicsEngine);

	// Get DebugDraw system
	DebugDraw& debug = *EngineGetModule(DebugDraw);

	// Store reference to default camera
	Camera& camera = graphics.GetDefaultCamera();

	// Draw a aqua circle at 0,0 with linelength
	debug.AddCircle(origin, lineLength, camera, Colors::Aqua);

	// Draw a red line from 0,0 to the edge of the circle
	Vector2D start = Vector2D(0, 0);

	angle1 -= dt * rotationalVelocity * pi * 2;
	angle2 -= (dt * rotationalVelocity * pi * 2)/60;
	angle3 -= ((dt * rotationalVelocity * pi * 2) / 60) / 60;

	Vector2D end = Vector2D((lineLength) * cos(angle1), (lineLength) * sin(angle1));
	debug.AddLineToList(start, end, Color(0.5f, 0.0f, 0.0f));
	Vector2D end2 = Vector2D((lineLength - 0.5f)* cos(angle2), (lineLength - 0.5f)* sin(angle2));
	debug.AddLineToList(start, end2, Color(0.2f, 0.8f, 0.2f));
	Vector2D end3 = Vector2D((lineLength - 0.75f)* cos(angle3), (lineLength - 0.75f)* sin(angle3));
	debug.AddLineToList(start, end3, Color(0.1f, 0.43f, 0.8f));
	debug.EndLineList(camera);

}

void Lab1::Shutdown()
{
	cout << "Lab1:Shutdown" << endl;
}
