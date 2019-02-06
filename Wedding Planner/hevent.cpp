// ITP 365 Fall 2018
// HW4 – Wedding Planner
// Name: Tae Hwan Yoo	
// Email: taehwany@usc.edu
// Platform: Windows
#include <iostream>
#include <fstream>
#include <string>
#include "dateconv.h"
#include "vector.h"
#include "hevent.h"
// HEvent Paramter
HEvent::HEvent(unsigned long long theEpochTime, std::string theHolidayName) 
{
	aEpoch = theEpochTime;
	aHoliday = theHolidayName;
}
// Gets the Epoch Time
unsigned long long HEvent::getEpoch() 
{
	return aEpoch;
}
// Gets the holiday 
std::string HEvent::getHoliday()
{
	return aHoliday;
}
// Returns the < value
bool operator< (const HEvent& firstEvent, const HEvent& secondEvent)
{
	return firstEvent.aEpoch < secondEvent.aEpoch;
}

// Returns the == value
bool operator== (const HEvent& firstEvent, const HEvent& secondEvent)
{
	return (getMonth(firstEvent.aEpoch) == getMonth(secondEvent.aEpoch) && getMonthDay(firstEvent.aEpoch) == getMonthDay(secondEvent.aEpoch) && getYear(firstEvent.aEpoch) == getYear(secondEvent.aEpoch));
}
// Returns the != value
bool operator!= (const HEvent& firstEvent, const HEvent& secondEvent)
{
	return (getMonth(firstEvent.aEpoch) != getMonth(secondEvent.aEpoch) || getMonthDay(firstEvent.aEpoch) != getMonthDay(secondEvent.aEpoch) || getYear(firstEvent.aEpoch) != getYear(secondEvent.aEpoch));
}
// Writes out the line of code when the date doesn't work
std::ostream& operator<< (std::ostream& os, HEvent& anEvent) 
{
	os << getMonth(anEvent.aEpoch) << "/" << getMonthDay(anEvent.aEpoch) << "/" << getYear(anEvent.aEpoch) << " is " << anEvent.aHoliday;
	return os;
}
