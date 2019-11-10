//------------------------------------------------------------------------------
//
// File Name: Time.h
// Author(s): Shain Allen
// Project: Auto-Scheduler
// Course: personal projects
//
//------------------------------------------------------------------------------
#pragma once


class Time
{
public:
	Time();

	Time(int Hours_, int Minutes);

	Time operator-(const Time& time2);

private:
	//functions
	//takes in a time and converts it into a format of total minutes
	int TimeToMinutes(Time inPutTime);

	//takes in minutes and converts it to an hour:minute formation as time
	Time MinutesToTime(int inPutMinutes);

	//variables
	int Hours;
	int Minutes;
};