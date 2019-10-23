//------------------------------------------------------------------------------
//
// File Name: associate.h
// Author(s): Shain Allen
// Project: Auto-Scheduler
// Course: personal projects
//
//------------------------------------------------------------------------------
#pragma once

#include <iostream>
#include "Time.h"
using std::string;


class Associate
{
public:
	Associate(string name_, Time Start_, Time End_, char IsMinor_);

	~Associate();

	void SetTime(Time Start_, Time End_);

	void SetMinor(char IsMinor_);

private:
	string name;
	Time Start;
	Time End;
	Time TotalTime;
	char IsMinor;
	Time FirstBreak;
	Time Lunch;
	Time SecondBreak;
};