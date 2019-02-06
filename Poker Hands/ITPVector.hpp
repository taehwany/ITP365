// ITP 365 Fall 2018
// HW5 Vector and Poker Hands
// Name: Tae Hwan Yoo
// Email: taehwany@usc.edu
// Platform: Windows
//
// ITPVector.hpp
// Defines and implements the ITPVector collection
//
#pragma once
#include <sstream>
#include <ostream>
#include "error.h"

template <typename T>
class ITPVector
{
	const unsigned INITIAL_CAPACITY = 10;
	const unsigned CAPACITY_MULTIPLIER = 2;
public:
	// Function: Constructor
	// Purpose: Initializes the ITP vector to have a
	// capacity of INITIAL_SIZE and a size of 0.
	// It also dynamically allocates the underlining array data
	// Input: None
	// Returns: Nothing
	ITPVector()
	{
		theCapacity = INITIAL_CAPACITY;
		theSize = 0;
		theVector = new T[theCapacity];
	}

	// Function: Destructor
	// Purpose: Deletes the underlying array and
	// sets size/capacity to zero
	// Input: None
	// Returns: Nothing
	~ITPVector()
	{
		theCapacity = 0;
		theSize = 0;
		delete[] theVector;
	}

	// Function: capacity
	// Purpose: Returns the current capacity of the underlying array data
	// Input: None
	// Returns: Capacity of underlying array data
	unsigned capacity() const
	{
		return theCapacity;
	}

	// Function: size
	// Purpose: Returns the current size of the vector
	// Input: None
	// Returns: Size of vector
	unsigned size() const
	{
		return theSize;
	}

	// Function: Subscript operator (read/write version)
	// Purpose: Grabs the specified index from vector
	// Causes an error if the index is out of bounds
	// Input: Index to access
	// Returns: Value at index, by reference
	T& operator[](unsigned index)
	{
		// Error check
		if (index > theSize) 
		{
			error("Index is out of bounds!");
		}
		// Returns the value
		else
		{
			return theVector[index];
		}
	}

	// Function: Subscript operator (read-only version)
	// Purpose: Grabs the specified index from vector
	// Causes an error if the index is out of bounds
	// Input: Index to access
	// Returns: Value at index, by reference
	const T& operator[](unsigned index) const
	{
		// Error check
		if (index > theSize)
		{
			error("Index is out of bounds!");
		}
		// Returns the value
		else
		{
			return theVector[index];
		}
	}

	// Function: insert_back
	// Purpose: Adds the specified element to the end of the ITPVector
	// It automatically reallocates the underlying array if we are
	// going over capacity
	// Input: Value to add (by const reference)
	// Returns: Nothing
	void insert_back(const T& value)
	{
		// If there is enough capacity still...
		if (theSize < theCapacity) 
		{
			theVector[theSize] = value;
			theSize++;
		}
		// If there is no more space left...
		else if (theSize == theCapacity) 
		{
			// Double and update capacity
			theCapacity = theCapacity * CAPACITY_MULTIPLIER;
			// New array 
			T* newVector = new T[theCapacity];
			// New array's data
			for (int i = 0; i < theSize; i++) 
			{
				newVector[i] = theVector[i];
			}
			// Delete the old array
			delete[] theVector;
			// The new array uses old array's name
			theVector = newVector;
			// Add the value into the array
			theVector[theSize] = value;
			// Update the size
			theSize++;
		}
	}

	// Function: get_back
	// Purpose: Returns the current last element in the vector
	// Does not remove this element from the vector
	// Causes an error if there are no elements in the vector
	// Input: Nothing
	// Returns: Value at back of vector, by reference
	T& get_back()
	{
		// Error check
		if (theSize == 0) 
		{
			error("No elements in vector!");
		}
		return theVector[theSize - 1];
	}

	// Function: remove_back
	// Purpose: Removes the last element from the ITPVector
	// Causes an error if there are no elements in the vector
	// Input: Nothing
	// Returns: Nothing
	void remove_back()
	{
		// Error check
		if (theSize == 0) 
		{
			error("No elements in vector!");
		}
		theSize--;
	}

	// Function: Output Stream Operator
	// Purpose: Prints the contents of the vector to the provided stream
	// Written in the format of {x, y, ..., z}
	// Input: Stream to write to, vector to write
	// Output: Stream after values are written
	friend std::ostream& operator<<(std::ostream& os, const ITPVector<T>& vector)
	{
		// Prints each element, make sure not to print until the end because we don't want to add ","
		for (int i = 0; i < vector.size() - 1; i++) 
		{
			os << vector[i] << ", ";
		}
		// Prints the last element
		os << vector[vector.size() - 1];
		return os;
	}
private:
	unsigned int theCapacity;
	unsigned int theSize;
	T* theVector;

	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// NOTE: Do not edit code below this line!!!
	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	// Disallow assignment and copy construction
	ITPVector<T>& operator=(const ITPVector<T>& other)
	{

	}

	ITPVector(const ITPVector<T>& other)
	{

	}
};
