// ITP 365 Fall 2018
// HW5 Vector and Poker Hands
// Name: Tae Hwan Yoo
// Email: taehwany@usc.edu
// Platform: Windows
//
// Cards.cpp
// Implements Cards and Poker Hand functionality
#include "Cards.h"
#include <random>
#include <algorithm>

// Function: Constructor
// Purpose: Draws 5 cards from the supplied deck, and sorts them
// by rank
// Input: Takes in a ITPVector of cards for the deck
// Returns: Nothing
PokerHand::PokerHand(ITPVector<Card>& deck)
{
	for (int i = 0; i < 5; i++)
	{
		Card cardDraw = deck.get_back();
		mHand.insert_back(cardDraw);
		deck.remove_back();
	}
	// Sort the hand
	std::sort(&mHand[0], &mHand[0] + mHand.size());
}

// Function: getBestPokerHand
// Purpose: Returns a string describing the poker hand this PokerHand
// contains
// Input: None
// Returns: The name of the best poker hand
std::string PokerHand::getBestPokerHand() const
{
	if (hasStraight() && hasFlush())
	{
		return "straight flush";
	}
	if (hasFourOfAKind())
	{
		return "four of a kind";
	}
	if (hasFullHouse())
	{
		return "full house";
	}
	if (hasFlush())
	{
		return "flush";
	}
	if (hasStraight())
	{
		return "straight";
	}
	if (hasThreeOfAKind())
	{
		return "three of a kind";
	}
	if (hasTwoPairs())
	{
		return "two pairs";
	}
	if (hasPair())
	{
		return "one pair";
	}
	return "high card"; // FIX RETURN VALUE
}

// Function: hasStraight
// Purpose: Determines if the hand has a straight
// Input: None
// Returns: true if there's a straight
bool PokerHand::hasStraight() const
{
	bool retVal = false;
	// First Card
	int firstCard = 0;
	int secondCard = 1;
	int thirdCard = 2;
	int fourthCard = 3;
	int fifthCard = 4;
	// Make a pair of cards and checks if the first card of every pair's rank is less than one than the second one
	if (mHand[firstCard].mRank + 1 == mHand[secondCard].mRank && mHand[secondCard].mRank + 1 == mHand[thirdCard].mRank && mHand[thirdCard].mRank + 1 == mHand[fourthCard].mRank && mHand[fourthCard].mRank + 1 == mHand[fifthCard].mRank)
	{
		retVal = true;
	}
	// If it doesn't work..
	else
	{
		retVal = false;
	}
	return retVal;
}

// Function: hasFlush
// Purpose: Determines if the hand has a flush
// Input: None
// Returns: true if there's a flush
bool PokerHand::hasFlush() const
{
	bool retVal = false;
	int firstCard = 0;
	int secondCard = 1;
	int thirdCard = 2;
	int fourthCard = 3;
	int fifthCard = 4;
	// Checks if everything is the same suit
	if (mHand[firstCard].mSuit == mHand[secondCard].mSuit && mHand[secondCard].mSuit == mHand[thirdCard].mSuit && mHand[thirdCard].mSuit == mHand[fourthCard].mSuit && mHand[fourthCard].mSuit == mHand[fifthCard].mSuit)
	{
		retVal = true;
	}
	// If it doesn't work...
	else
	{
		retVal = false;
	}
	return retVal;
}

// Function: hasFourOfAKind
// Purpose: Determines if the hand has a 4 of a kind
// Input: None
// Returns: true if there's a 4 of a kind
bool PokerHand::hasFourOfAKind() const
{
	// Since it's sorted, there are only two possibilities:
	// x x x x y
	// or
	// x y y y y
	bool retVal = false;
	int firstCard = 0;
	int secondCard = 1;
	int thirdCard = 2;
	int fourthCard = 3;
	int fifthCard = 4;
	// Checks if there are four of the same cards [1st - 4th]
	if (mHand[firstCard].mRank == mHand[secondCard].mRank && mHand[secondCard].mRank == mHand[thirdCard].mRank && mHand[thirdCard].mRank == mHand[fourthCard].mRank)
	{
		retVal = true;
	}
	// Checks if there are four of the same cards [2nd - 5th]
	if (mHand[secondCard].mRank == mHand[thirdCard].mRank && mHand[thirdCard].mRank == mHand[fourthCard].mRank && mHand[fourthCard].mRank == mHand[fifthCard].mRank)
	{
		retVal = true;
	}
	// If it doesn't work...
	else
	{
		retVal = false;
	}
	return retVal;
}

// Function: hasFullHouse
// Purpose: Determines if the hand has a full house
// Input: None
// Returns: true if there's a full house
bool PokerHand::hasFullHouse() const
{
	// Since it's sorted, there are only two possibilities:
	// x x x y y
	// or
	// x x y y y
	bool retVal = false;
	int firstCard = 0;
	int secondCard = 1;
	int thirdCard = 2;
	int fourthCard = 3;
	int fifthCard = 4;
	// Checks if there are three of the same ranks [1st - 3rd]
	if (mHand[firstCard].mRank == mHand[secondCard].mRank && mHand[secondCard].mRank == mHand[thirdCard].mRank)
	{
		// Then checks if there is a pair as well [4th - 5th]
		if (mHand[fourthCard].mRank == mHand[fifthCard].mRank)
		{
			retVal = true;
		}
		// If it doesn't work...
		else
		{
			retVal = false;
		}
	}
	// Checks if there are three of the same ranks [3rd - 5th]
	if (mHand[thirdCard].mRank == mHand[fourthCard].mRank && mHand[fourthCard].mRank == mHand[fifthCard].mRank)
	{
		// Then checks if there is a pair as well [1st - 2nd]
		if (mHand[firstCard].mRank == mHand[secondCard].mRank)
		{
			retVal = true;
		}
		// If it doesn't work...
		else
		{
			retVal = false;
		}
	}
	return retVal;
}

// Function: hasThreeOfAKind
// Purpose: Determines if the hand has a three of a kind
// Input: None
// Returns: true if there's a three of a kind
bool PokerHand::hasThreeOfAKind() const
{
	// There are three possibilities:
	// x x x y z
	// x y y y z
	// x y z z z

	bool retVal = false;
	int firstCard = 0;
	int secondCard = 1;
	int thirdCard = 2;
	int fourthCard = 3;
	int fifthCard = 4;
	// Checks if there are 3 of the same ranks [1st - 3rd]
	if (mHand[firstCard].mRank == mHand[secondCard].mRank && mHand[secondCard].mRank == mHand[thirdCard].mRank)
	{
		retVal = true;
	}
	// Checks if there are 3 of the same ranks [2nd - 4th]
	if (mHand[secondCard].mRank == mHand[thirdCard].mRank && mHand[thirdCard].mRank == mHand[fourthCard].mRank)
	{
		retVal = true;
	}
	// Checks if there are 3 of the same ranks [3rd - 5th]
	if (mHand[thirdCard].mRank == mHand[fourthCard].mRank && mHand[fourthCard].mRank == mHand[fifthCard].mRank)
	{
		retVal = true;
	}
	// If it doesn't work...
	else
	{
		retVal = false;
	}
	return retVal;
}

// Function: hasTwoPairs
// Purpose: Determines if the hand has two pairs
// Input: None
// Returns: true if there's two pairs
bool PokerHand::hasTwoPairs() const
{
	// There are three possibilities:
	// x x y y z
	// x y y z z
	// x x y z z
	bool retVal = false;
	int firstCard = 0;
	int secondCard = 1;
	int thirdCard = 2;
	int fourthCard = 3;
	int fifthCard = 4;
	// Checks if there are 2 of the same ranks [1st - 2nd]
	if (mHand[firstCard].mRank == mHand[secondCard].mRank)
	{
		// Then checks if there 2 of the same ranks again [3rd - 4th]
		if (mHand[thirdCard].mRank == mHand[fourthCard].mRank)
		{
			retVal = true;
		}
	}
	// Checks if there are 2 of the same ranks [2nd - 3rd]
	if (mHand[secondCard].mRank == mHand[thirdCard].mRank)
	{
		// Then checks if there 2 of the same ranks again [4th - 5th]
		if (mHand[fourthCard].mRank == mHand[fifthCard].mRank)
		{
			retVal = true;
		}
	}
	// Checks if there are 2 of the same ranks [1st - 3rd]
	if (mHand[firstCard].mRank == mHand[secondCard].mRank)
	{
		// Then checks if there 2 of the same ranks again [4th - 5th]
		if (mHand[fourthCard].mRank == mHand[fifthCard].mRank)
		{
			retVal = true;
		}
	}
	return retVal;
}

// Function: hasPair
// Purpose: Determines if there's a pair
// Input: None
// Returns: true if there's a pair
bool PokerHand::hasPair() const
{
	// There's a pair if any neighbors are equal to each other
	bool retVal = false;
	// Checks every card to see if there are any cards that have the same rank
	for (int i = 0; i < 4; i++)
	{
		if (mHand[i].mRank == mHand[i + 1].mRank)
		{
			retVal = true;
		}
	}
	return retVal;
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// NOTE: Do not edit code below this line!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


// Function: createDeck
// Purpose: Given an empty ITPVector of Cards, inserts a
// standard 52 card deck and shuffles it
// Input: An ITPVector of Cards (by reference)
// Returns: nothing
void createDeck(ITPVector<Card>& deck)
{
	for (int i = 0; i < 4; i++)
	{
		Suit suit = Suit(i);
		for (int value = 2; value <= 14; value++)
		{
			deck.insert_back(Card(value, suit));
		}
	}

	// Shuffle the deck
	std::shuffle(&deck[0], &deck[0] + deck.size(), std::random_device());
}

// Function: << operator for Card
// Purpose: Outputs the name and suit of the card
// Input: ostream and card
// Returns: ostream, with card data output to it
std::ostream& operator<<(std::ostream& os, const Card& card)
{
	// Output value
	if (card.mRank < 11) // Number card
	{
		os << card.mRank;
	}
	else // Face card
	{
		switch (card.mRank)
		{
		case 11:
			os << "Jack";
			break;
		case 12:
			os << "Queen";
			break;
		case 13:
			os << "King";
			break;
		case 14:
			os << "Ace";
			break;
		default:
			os << "Invalid";
			break;
		}
	}

	// Output suit
	os << " of ";
	switch (card.mSuit)
	{
	case CLUBS:
		os << "Clubs";
		break;
	case DIAMONDS:
		os << "Diamonds";
		break;
	case HEARTS:
		os << "Hearts";
		break;
	case SPADES:
		os << "Spades";
		break;
	default:
		os << "Invalid";
		break;
	}

	return os;
}


// Function: < comparison operator for Card
// Purpose: Compares the value of the left and right card
// Input: Two cards to compare
// Returns: true if left < right
bool operator<(const Card& left, const Card& right)
{
	// If their values are the same, compare the suits
	if (left.mRank == right.mRank)
	{
		return left.mSuit < right.mSuit;
	}
	else
	{
		return left.mRank < right.mRank;
	}
}

// Function: << operator
// Purpose: Prints out the hand
std::ostream& operator<<(std::ostream& os, const PokerHand& hand)
{
	os << hand.mHand;
	return os;
}
