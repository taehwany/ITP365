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
#include "hcal.h"
#include "dateconv.h"
// Function: mergeCal
// Purpose: Takes two calenders and merges them
// Input: Two calender pointers
// Output: Returns the merged calender
HCal* mergeCal(HCal* firstCal, HCal* secondCal)
{
	// The merged calender
	HCal* thirdCal = new HCal;
	int i = 0;
	int j = 0;
	// Until the both calenders are done...
	while ((i < firstCal->getSize()) && (j < secondCal->getSize()))
	{
		// If the first event is earlier...
		if (*firstCal->getEvent(i) < *secondCal->getEvent(j))
		{
			// Add the event
			thirdCal->addEvent(*firstCal->getEvent(i));
			i++;
		}
		else
		// If the second sevent is earlier
		{
			// Add the event
			thirdCal->addEvent(*secondCal->getEvent(j));
			j++;
		}
	}
	// For the leftover portion of first calender
	if (i + 1 < firstCal->getSize())
	{
		for (int k = i; k < firstCal->getSize(); k++)
		{
			thirdCal->addEvent(*firstCal->getEvent(k));
		}
	}
	// For the leftover portion of second calender
	if (j + 1 < secondCal->getSize())
	{
		for (int k = j; k < secondCal->getSize(); k++)
		{
			thirdCal->addEvent(*secondCal->getEvent(k));
		}
	}
	return thirdCal;
}
// Function: loadCal
// Purpose: To take each event and put into a calender
// Input: The csv files
// Output: Returns a pointer to the calender made from each file
HCal* loadCal(std::string theFile)
{
	// The calender to be made
	HCal* newCal = new HCal;
	std::string temp;
	// Reads the file
	std::ifstream fileInput(theFile);
	// Erase the first line since it reads, "EpochGMT,Weekday,Holiday name"
	std::getline(fileInput, temp);
	// Until end of file...
	while (!fileInput.eof())
	{
		// Obtains each line
		std::getline(fileInput, temp);
		// Find the first instance of a comma
		int commaIndex = int(temp.find(","));
		// Until first instance of comma...
		if (commaIndex != std::string::npos)
		{
			std::string holiday;
			// Date is from beginning to first instance of comma
			std::string date = temp.substr(0, commaIndex);
			// To find second comma, must skip first instance of comma and next string
			int commaSkip = (commaIndex + 1);
			// Updates temp
			temp = temp.substr(commaSkip);
			commaIndex = int(temp.find(","));
			// Until second instance of comma...
			if (commaIndex != std::string::npos)
			{
				// Print anything after second comma because we want only holiday
				holiday = temp.substr(commaIndex + 1);
			}
			// Checks if string date can become integer
			if (stringToInteger(date))
			{
				// Sets string into integer
				unsigned long long num = std::stoull(date);
				HEvent* newEvent = new HEvent(num, holiday);
				newCal->addEvent(*newEvent);
			}
		}
	}
	return newCal;
}
int main(int argc, char** argv)
{
	// The first two calenders
	HCal* a = loadCal("CHholiday2016.csv");
	HCal* b = loadCal("BRholiday2016.csv");
	// Merges the calender
	HCal* tempCal = mergeCal(a, b);
	// The third calender
	HCal* c = loadCal("USholiday2016.csv");
	// Merges the merged calender with the third calender
	HCal*allCal = mergeCal(tempCal, c);
	// Message tp welcome user
	std::cout << "Welcome to the wedding planner!" << std::endl;
	// Input
	std::string inputDate;
	// While input is not q or Q...
	while (inputDate != "q" && inputDate != "Q") 
	{
		// Set to -2
		int result = -2;   
        // Question to integer                                   
		std::cout << "Please enter a date (MM/DD/YYYY) or 'Q'/'q' to QUIT: ";
		// Gets input
		std::cin >> inputDate;
		// Strings and integers of values
		std::string month;
		unsigned int numberMonth;
		std::string day;
		unsigned int numberDay;
		std::string year;
		unsigned int numberYear;
		// Find first instance of slash
		int slashFind = int(inputDate.find("/")); 
		// Until find first instance of slash...
		if (slashFind != std::string::npos) 
		{
			// Month is beginning to index of first instance of slash
			month = inputDate.substr(0, slashFind);
			// Skip over the first instance of slash
			int slashSkip = slashFind + 1;
			// Update inputDate to find second instance of slash
			inputDate = inputDate.substr(slashSkip);
			// Find second instance of slash
			slashFind = int(inputDate.find("/"));
				// Until find second instance of slash...
				if (slashFind != std::string::npos) 
				{
					// Day is slashskip index to second instance of slash
					day = inputDate.substr(0, slashFind);
					// Update inputDate once more to find the year
					inputDate = inputDate.substr(slashSkip);
					// Anything after second instance of slash to year
					year = inputDate;	
				}
		}
		// If the month is an integer and its size is 1 or 2...
		if (stringIsInteger(month) && (month.size() == 1 || month.size() == 2))
		{
			// Swtich into integer
			numberMonth = std::stoi(month);
			// If the day is an integer and its size is 1 or 2...
			if (stringIsInteger(day) && (day.size() == 1 || day.size() == 2)) 
			{ 
				// Switch into integer
				numberDay = std::stoi(day);
				// If the year is an integer and its size is 4...
				if (stringIsInteger(year) && year.size() == 4) 
				{
					// Switch into integer
					numberYear = std::stoi(year);
					// Accounts daylight savings
					if ((numberMonth == 3 && numberDay > 12) || (numberMonth == 11 && numberDay < 6) || (numberMonth > 3 && numberMonth < 11))
					{
						HEvent test(getEpochSecs(numberMonth, numberDay, numberYear) + 25200, "");
						// Searches if there is a day that is similar
						result = allCal->search(&test);
					}
					// Accounts for any other day
					else 
					{
						HEvent test(getEpochSecs(numberMonth, numberDay, numberYear) + 28800, "");
						// Searches if there is a day that is similar...
						result = allCal->search(&test);
					}
				}
			}
		}
		// If search has no similarity...
		if (result == -1) 
		{
			std::cout << "This date works!" << std::endl;
		}
		// If search has similarity...
		else if (result != -2) 
		{
			std::cout << *(allCal->getEvent(result)) << std::endl;
		}
	}
	// Exit while loop and thank the user
	std::cout << "Thank you for using the wedding planner!" << std::endl;
	return 0;
}




