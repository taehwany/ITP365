// ITP 365 Fall 2018
// HW4 – Wedding Planner
// Name: Tae Hwan Yoo	
// Email: taehwany@usc.edu
// Platform: Windows
#ifndef HCAL_H
#define HCAL_H
#include <iostream>
#include <fstream>
#include <string>
#include "vector.h"
#include "hevent.h"
#include "dateconv.h"
class HCal
{
// Private
private:
	std::vector<HEvent*> vecEvents;
// Public
public:
	// Function: HCal (Default Constructor)
	// Purpose: Creates vector for calenders
	// Input: None
	// Output: None
	HCal();
	// Function: addEvent
	// Purpose: Adds an HEvent into vector
	// Input: HEvent
	// Output: None
	void addEvent(HEvent& addedEvent);
	// Function: getSize
	// Purpose: Gets calender size
	// Input: None
	// Output: Returns size
	int getSize();
	// Function: getEvent
	// Purpose: Gets the event
	// Input: Unsigned int of an event
	// Output: Returns the event
	HEvent* getEvent(unsigned int theEvent);
	//Function: search
	//Purpose: Calls binarySearchPart
	//Input: Pointer to HEvent
	//Output: Returns a binarySearchPart
	int search(HEvent* searchDate);
	// Function: binarySearchPart
	// Purpose: A binary search checker
	// Input: Pointer to HEvent, begin of the event, and end of the event
	// Output: Returns the index of where the event is or the event itself
	int binarySearchPart(HEvent* binaryEvent, int begin, int end);
};
#endif


