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
	Associate(string name_, Time start_, Time end_, char isMinor_);

	~Associate();

private:
	string name;
	Time start;
	Time end;
	Time totalTime;
	char isMinor;
	Time firstBreak;
	Time lunch;
	Time secondBreak;
};