/*
	This program demonstrates the deficiencies (and solution)
	of the default copy constructor
*/

#include <iostream>
#include <iomanip>
#include "NumberArray.h"
using namespace std;

int main()
{
	// Create an object
	NumberArray first(3, 10.5);

	// Make a copy of the object (copy constructor)
	NumberArray second = first;

	// Display the values of the two objects
	cout << setprecision(2) << fixed << showpoint;
	cout << "Value stored in first object is ";
	first.print();
	cout << endl << "Value stored in second object is ";
	second.print();

	// Change the value of the second array
	cout << endl << endl << "Changing ONLY second object." << endl << endl;
	second.setValue(20.5);

	// Display the values of the two objects
	cout << "Value stored in first object is ";
	first.print();
	cout << endl << "Value stored in second object is ";
	second.print();
	cout << endl << endl << endl;

	return 0;
}