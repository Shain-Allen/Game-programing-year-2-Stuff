#include "stdafx.h"	//precomplied header File
#include "Lab1.h"

using std::endl;
using std::cout;

Lab1::Lab1()
	:BetaObject("Lab1"), pi(float(M_PI)), lineLength(2), rotationalVelocity(2), origin(0,0), angle1(0), angle2(0), angle3(0)
{
	
}

void Lab1::Initialize()
{
	cout << "Lab1:Initialize" << endl;
}

void Lab1::Update(float dt)
{
	cout << "Lab1:Update" << dt << endl;
}

void Lab1::Shutdown()
{
	cout << "Lab1:Shutdown" << endl;
}
