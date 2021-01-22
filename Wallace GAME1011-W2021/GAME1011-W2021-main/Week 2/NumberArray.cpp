#include <iostream>
#include "NumberArray.h"
using namespace std;

/*
	Copy constructor allocates a new 
	array and copies into it the entries
	of the array in the other object
*/
NumberArray::NumberArray(NumberArray &obj)
{
	arraySize = obj.arraySize;
	// aPtr = obj.aPtr;	// WRONG!
	aPtr = new double[arraySize];	// Allocate a NEW array given an arraySize
	for (int i = 0; i < arraySize; i++)
	{
		aPtr[i] = obj.aPtr[i];
	}
}

/*
	Constructor allocates an array of the
	given size and sets all its entries to the
	given value.
*/
NumberArray::NumberArray(int size, double value)
{
	arraySize = size;
	aPtr = new double[arraySize];
	setValue(value);
}

NumberArray::~NumberArray()
{
	if (arraySize > 0)
	{
		delete[] aPtr;
	}
}

// Prints all the entries of the array
void NumberArray::print() const
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << aPtr[i] << " ";
	}
}

// Sets all the entries of the array to the same value
void NumberArray::setValue(double value)
{
	for (int i = 0; i < arraySize; i++)
	{
		aPtr[i] = value;
	}
}
