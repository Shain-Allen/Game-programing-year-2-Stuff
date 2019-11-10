//------------------------------------------------------------------------------
//
// File Name: Time.cpp
// Author(s): Shain Allen
// Project: Auto-Scheduler
// Course: personal projects
//
//------------------------------------------------------------------------------
#include "Time.h"

Time::Time()
	: Hours(0), Minutes(0)
{
}

Time::Time(int Hours_, int Minutes_)
	: Hours(Hours_), Minutes(Minutes_)
{
}

Time Time::operator-(const Time& time2)
{
	//total hours worked for the day
	Time totalHours;
	int totalHoursInMinutes;
	
	//hours converted to minutes and added to minutes spot for both times
	int timeInMinutes1 = TimeToMinutes(*this);
	int timeInMinutes2 = TimeToMinutes(time2);

	totalHoursInMinutes = timeInMinutes1 - timeInMinutes2;

	totalHours = MinutesToTime(totalHoursInMinutes);

	return totalHours;
}

int Time::TimeToMinutes(Time inPutTime)
{
	int timeInMinutes;

	timeInMinutes = (inPutTime.Hours * 60) + inPutTime.Minutes;

	return timeInMinutes;
}

Time Time::MinutesToTime(int inPutMinutes)
{
	Time timeFromMinutes;

	timeFromMinutes.Hours = inPutMinutes / 60;
	timeFromMinutes.Minutes = inPutMinutes % 60;

	return timeFromMinutes;
}
