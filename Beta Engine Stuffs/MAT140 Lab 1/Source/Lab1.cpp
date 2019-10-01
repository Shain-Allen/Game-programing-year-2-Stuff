#include "stdafx.h"	//precomplied header File
#include "Lab1.h"

using std::endl;
using std::cout;

Lab1::Lab1()
	:BetaObject("Lab1"), pi(float(M_PI)), lineLength(2), rotationalVelocity(1.0/60.0), origin(0,0)
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

	Vector2D end = Vector2D(lineLength * cos(angle1), lineLength * sin(angle1));
	debug.AddLineToList(start, end, Color(0.5, 0, 0));
	Vector2D end2 = Vector2D(lineLength * cos(angle2), lineLength * sin(angle2));
	debug.AddLineToList(start, end2, Color(0.2, 0.8, 0.2));
	Vector2D end3 = Vector2D(lineLength * cos(angle3), lineLength * sin(angle3));
	debug.AddLineToList(start, end3, Color(0.1, 0.43, 0.8));
	debug.EndLineList(camera);

}

void Lab1::Shutdown()
{
	cout << "Lab1:Shutdown" << endl;
}
