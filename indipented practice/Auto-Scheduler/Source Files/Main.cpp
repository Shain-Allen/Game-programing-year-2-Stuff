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
using std::vector;

int main()
{
	vector<Associate> associates;
	//push_back()
	string name_;
	Time Start_;
	Time End_;
	bool IsMinor_;
	char NewEntry;

	cout << "welcome to the Auto Schedualer" << endl;
	cout << "do you wish to make a new schedual? (y/n): ";
	cin >> NewEntry;
	cout << endl;

	while (NewEntry == 'y')
	{
		cout << "please enter a name: ";
		cin >> name_;
		Associate var(name_);

		cout << "please enter the starting time for this assocuate" << endl;
		cin >> Start_.Hours;
		cin >> Start_.Minutes;
		cout << endl << "please enter the End time for this associate" << endl;
		cin >> End_.Hours;
		cin >> End_.Minutes;


		associates.push_back(var);
	}

}