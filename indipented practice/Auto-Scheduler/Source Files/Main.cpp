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
#include "Time.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main()
{
	vector<Associate> associates;
	//push_back()
	string name_;
	Time startTime;
	Time endTime;
	char isMinor_;
	char newschedual;
	int hour;
	int minute;

	cout << "welcome to the Auto Schedualer" << endl;
	cout << "do you wish to make a new schedual? (y/n): ";
	cin >> newschedual;
	cout << endl;

	while (newschedual == 'y')
	{
		cout << "please enter a name: ";
		cin >> name_;
		
		//get the start time in format hh:mm
		cout << "please enter the starting time for this assocuate: ";
		cin >> hour;
		cout << ":";
		cin >> minute;
		startTime.SetHours(hour);
		startTime.SetMinutes(minute);
		cout << endl << "please enter the End time for this associate: ";
		cin >> hour;
		cout << ":";
		cin >> minute;
		endTime.SetHours(hour);
		endTime.SetMinutes(minute);
		cout << "is this associate a minor? (y/n): ";
		cin >> isMinor_;
		//associates.push_back(var);
	}

}