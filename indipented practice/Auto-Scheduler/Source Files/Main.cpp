//------------------------------------------------------------------------------
//
// File Name: Main.cpp
// Author(s): Shain Allen
// Project: Auto-Scheduler
// Course: personal projects
//
//------------------------------------------------------------------------------
#include <iostream>
#include "associate.h"
#include <vector>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	std::vector<Associate> associates;
	//push_back()
	string name_;
	Time Start_;
	Time End_;
	Time Total_;
	bool IsMinor_;
	char NewEntry;

	cout << "welcome to the Auto Schedualer" << endl;
	cout << "do you wish to make a new schedual? (y/n): ";
	cin >> NewEntry;
	cout << endl;

	while (NewEntry == 'y')
	{
		cout << "please enter a name: ";
	}

}