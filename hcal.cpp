// ITP 365 Fall 2018
// HW4 – Wedding Planner
// Name: Tae Hwan Yoo	
// Email: taehwany@usc.edu
// Platform: Windows
#include <iostream>
#include <fstream>
#include <string>
#include "vector.h"
#include "hevent.h"
#include "dateconv.h"
#include "hcal.h"
HCal::HCal() 
{
	Vector<HEvent*> vecEvents;
}
// Adds the event
void HCal::addEvent(HEvent& addedEvent) 
{
	vecEvents.push_back(&addedEvent);
}
// Returns size
int HCal::getSize() 
{
	return (vecEvents.size());
}
// Returns event
HEvent* HCal::getEvent(unsigned int theEvent)
{
	return vecEvents[theEvent];
}
// Starts binarySearchPart
int HCal::search(HEvent* searchDate)
{
	return binarySearchPart(searchDate, 0, (vecEvents.size()) - 1);
}
// Binary searches the event
int HCal::binarySearchPart(HEvent* binaryEvent, int start, int end) 
{
	int theEvent = -1;
	// Finds the middle
	int middle = (start + end) / 2;
	if (start > end) 
	{
		return theEvent;
	}
	// Using middle, if the event is the same as the one in the middle...
	else if (*(vecEvents[middle]) == *(binaryEvent)) 
	{
		theEvent = middle;
		// Updates the event
		return theEvent;
	}
	// If the event's location is less than the binary event
	else if (*(vecEvents[middle]) < *(binaryEvent)) 
	{
		// Uses recursion to start from middle to end
		theEvent = binarySearchPart(binaryEvent, middle + 1, end);
	}
	// If the event's location is more than the binary event
	else if (*(binaryEvent) < *(vecEvents[middle])) 
	{
		// Uses recursion to start from beginning to middle
		theEvent = binarySearchPart(binaryEvent, start, middle - 1);
	}
	return theEvent;
}

