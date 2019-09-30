#include "stdafx.h" //precomplied Header file
#include "Level1.h"

using std::endl;
using std::cout;

level1::level1() 
	: BetaObject("level1")
{

}

void level1::Initialize()
{
	cout << "level1:Initialize" << endl;
}

void level1::Update(float dt)
{
	cout << "level1:Update" << dt << endl;
}

void level1::Shutdown()
{
	cout << "level1:Shutdown" << endl;
}
