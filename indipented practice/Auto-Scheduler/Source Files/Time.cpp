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
	: hours(0), minutes(0)
{
}

Time::Time(int Hours_, int Minutes_)
	: hours(Hours_), minutes(Minutes_)
{
}

void Time::SetHours(int hours_)
{
	hours = hours_;
}

void Time::SetMinutes(int minutes_)
{
	minutes = minutes_;
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

Time& Time::operator+=(const Time& time2)
{
	//new time to be returned
	Time newTime;
	//new Time in minutes format
	int newTimeInMinutes;
	//hours converted to minutes and added to minutes spot for both times
	int timeInMinutes1 = TimeToMinutes(*this);
	int timeInMinutes2 = TimeToMinutes(time2);

	newTimeInMinutes = timeInMinutes1 + timeInMinutes2;

	newTime = MinutesToTime(newTimeInMinutes);

	return newTime;
}

//for converting the time class to a format in minutes
int Time::TimeToMinutes(Time inPutTime)
{
	int timeInMinutes;

	timeInMinutes = (inPutTime.hours * 60) + inPutTime.minutes;

	return timeInMinutes;
}

//for converting minutes back into the time class
Time Time::MinutesToTime(int inPutMinutes)
{
	Time timeFromMinutes;

	timeFromMinutes.hours = inPutMinutes / 60;
	timeFromMinutes.minutes = inPutMinutes % 60;

	return timeFromMinutes;
}
