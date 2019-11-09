#include "associate.h"
//------------------------------------------------------------------------------
//
// File Name: associate.cpp
// Author(s): Shain Allen
// Project: Auto-Scheduler
// Course: personal projects
//
//------------------------------------------------------------------------------

Associate::Associate(string name_, Time start_, Time end_, char isMinor_)
	: name(name_), start(start_), end(end_), isMinor(isMinor_), firstBreak(0, 0), lunch(0, 0), secondBreak(0, 0)
{
}

Associate::~Associate()
{

}
