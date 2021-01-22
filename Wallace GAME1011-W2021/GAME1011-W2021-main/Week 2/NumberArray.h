#pragma once
#include <iostream>

class NumberArray
{
private:
	double* aPtr;
	int arraySize;
public:
	NumberArray(NumberArray&);	// User-defined copy constructor prototype
	NumberArray(int size, double value);
	~NumberArray();	// Destructor
	void print() const;
	void setValue(double value);
};