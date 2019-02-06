// ITP 365 Fall 2018
// HW5 Vector and Poker Hands
// Name: Tae Hwan Yoo
// Email: taehwany@usc.edu
// Platform: Windows

#include "ITPVector.hpp"
#include "Cards.h"
#include <iostream>

int main(int argc, char** argv)
{
	ITPVector<int> testVector;
	int input = 1;
	// Main menu
	while (input == 1 || input == 2)
	{
		std::cout << "Select an option" << std::endl;
		std::cout << "1. Test ITPVector" << std::endl;
		std::cout << "2. Poker Hands" << std::endl;
		std::cout << "> ";
		// Input to select an option
		std::cin >> input;
		// First option
		if (input == 1)
		{
			std::string vectorTest = "y";
			// While loop to reset the test
			while (vectorTest == "y")
			{
				int vectorInput;
				// ITPVector
				std::cout << "***Constructing an ITPVector..." << std::endl;
				// New Vector
				ITPVector<int> testVector;
				// Contents of test
				std::cout << "Contents: {}" << std::endl;
				std::cout << "Capacity: " << testVector.capacity() << ", Size: " << testVector.size() << std::endl;
				std::cout << "Enter a number of elements to add:";
				// Input to create vector
				std::cin >> vectorInput;
				// Update vector with elements
				for (int i = 0; i < vectorInput; i++)
				{
					testVector.insert_back(i * 5);
				}
				// Updated contents of test
				std::cout << "Contents: {" << testVector << "}" << std::endl;
				std::cout << "Capacity: " << testVector.capacity() << ", Size: " << testVector.size() << std::endl;
				std::cout << "The back element is: " << testVector.get_back() << std::endl;
				// Remove the back element
				testVector.remove_back();
				std::cout << "Called remove_back" << std::endl;
				std::cout << "Contents: {" << testVector << "}" << std::endl;
				std::cout << "Capacity: " << testVector.capacity() << ", Size: " << testVector.size() << std::endl;
				std::cout << "***Test Complete" << std::endl;
				std::cout << "Try again? (y/n): ";
				// Resets or quits the test
				std::cin >> vectorTest;
			}
		}
		// Second option
		else if (input == 2)
		{
			std::string retry = "y";
			// While loop to reset the test
			while (retry == "y")
			{
				// New deck
				ITPVector<Card> pokerDeck;
				// Creates deck
				createDeck(pokerDeck);
				// Creates and draws hand
				PokerHand hand(pokerDeck);
				// Content for hand
				std::cout << "You drew: {" << hand << "}" << std::endl;
				std::cout << "You have " << hand.getBestPokerHand() << std::endl;
				std::cout << "Try again? (y/n): ";
				// Resets or quits the poker hand
				std::cin >> retry;
			}
		}
	}
	return 0;
}
