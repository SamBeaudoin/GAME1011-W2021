#include <iostream>
#include <cmath>
using namespace std;

// This is a Circle class
class Circle
{
private:
	double radius;
public:
	void setRadius(double r);
	double calcArea();
};

//int main()
//{
//	Circle circle1, circle2;
//
//	circle1.setRadius(1);
//	circle2.setRadius(2.5);
//
//	// Print out the area
//	cout << "The area of circle 1 is " << circle1.calcArea() << endl;
//	cout << "The area of circle 2 is " << circle2.calcArea() << endl;
//
//	return 0;
//}

void Circle::setRadius(double r)
{
	radius = r;
}

double Circle::calcArea()
{
	return 3.14 * pow(radius, 2);
}