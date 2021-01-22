// Demonstrate object assignment
#include <iostream>
using namespace std;

class Rectangle
{
private:
	double width, length;
public:
	Rectangle(double width, double length)
	{
		this->width = width;
		this->length = length;
	}
	double getWidth() const
	{
		return width;
	}
	double getLength() const
	{
		return length;
	}
	void output() const
	{
		cout << "Width is " << this->getWidth() << ", Length is " << this->getLength() << endl;
	}
};

void DisplayBoxInfo(Rectangle box);

//int main()
//{
//	// Set up two rectangle objects
//	Rectangle box1(10, 20), box2(5, 10);
//
//	// Display the rectangle objects
//	cout << "Before the assignment:\n";
//	cout << "Box 1 data:\t"; 
//	box1.output();
//	cout << "Box 2 data:\t"; 
//	box2.output();
//
//	// Memberwise Assignment
//	box2 = box1;
//
//	Rectangle box3 = box2;	// Default Copy Constructor
//
//	// Display the rectangle objects
//	cout << "After the assignment:\n";
//	cout << "Box 1 data:\t";
//	box1.output();
//	cout << "Box 2 data:\t";
//	box2.output();
//	DisplayBoxInfo(box3);
//
//	cout << &box3;
//	
//
//	return 0;
//}

void DisplayBoxInfo(Rectangle box)
{
	cout << "Box 3 data:\t";
	box.output();
	cout << endl << endl << &box << endl << endl;
}