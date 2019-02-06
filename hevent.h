// ITP 365 Fall 2018
// HW4 – Wedding Planner
// Name: Tae Hwan Yoo	
// Email: taehwany@usc.edu
// Platform: Windows
#pragma once
#ifndef HEVENT_H
#define HEVENT_H
#include <iostream>
#include <fstream>
#include <string>
#include "dateconv.h"
#include "vector.h"
class HEvent 
{
// Private 
private:
	// Epoch and holiday values
	unsigned long long aEpoch;
	std::string aHoliday;
// Public
public:
	// Function: HEvent (Paramaterized Constructor)
	// Purpose: Creates HEvents
	// Input: Unsigned long long Epoch Time and string holiday name
	// Output: None
	HEvent(unsigned long long theEpochTime, std::string theHolidayName);
	// Function: getEpoch
	// Purpose: Gets the Epoch Time
	// Input: None
	// Output: Returns Epoch Time
	unsigned long long getEpoch();
	// Function: getHoliday
	// Purpose: Gets the holiday name
	// Input: None
	// Output: Returns the holiday name
	std::string getHoliday();
	// Function: bool operator<
	// Purpose: Compares two different events' times
	// Input: Two HEvents
	// Output: Returns the < operator
	friend bool operator< (const HEvent& firstEvent, const HEvent& secondEvent);
	// Function: bool operator==
	// Purpose: Compares two different events' times
	// Input: Two HEvents
	// Output: Returns the == operator
	friend bool operator== (const HEvent& firstEvent, const HEvent& secondEvent);
	// Function: bool operator!=
	// Purpose: Compares two different events' times
	// Input: Two HEvents
	// Output: Returns the != operator
	friend bool operator!= (const HEvent& firstEvent, const HEvent& secondEvent);
	// Function: std::ostream& operator<<
	// Purpose: Creates os and implements the line if the date is not good
	// Input: Os and an HEvent
	// Output: Returns the line if the date is not good
	friend std::ostream& operator<< (std::ostream& os, HEvent& anEvent);
};
#endif