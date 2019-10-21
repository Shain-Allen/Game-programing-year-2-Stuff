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
	Associate(string name_);

	~Associate();

	void SetTime(Time Start_, Time End_);

	bool SetMinor(bool IsMinor_);

private:
	string name;
	Time Start;
	Time End;
	Time Total;
	bool IsMinor;
	Time FirstBreak;
	Time Lunch;
	Time SecondBreak;
};