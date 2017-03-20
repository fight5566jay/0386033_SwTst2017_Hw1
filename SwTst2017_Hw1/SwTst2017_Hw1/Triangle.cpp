#include "Triangle.h"
#include <sstream>

const int iTriangleMinLength = 1;
const int iTriangleMaxLength = 200;
string getTriangleType(const int & iSideA, const int & iSideB, const int & iSideC)
{
	string sAns;
	stringstream ss;

	if (outOfRange(iSideA)) {
		return "Value of the side A is not in the range of " + getRangeMsg();
	}

	if (outOfRange(iSideB)) {
		return "Value of the side B is not in the range of " + getRangeMsg();
	}

	if (outOfRange(iSideC)) {
		return "Value of the side C is not in the range of " + getRangeMsg();
	}
	
	if((iSideA + iSideB <= iSideC) || (iSideA + iSideC <= iSideB) || (iSideB + iSideC <= iSideA))
		return string("Not a triangle");

	if (iSideA == iSideB && iSideA == iSideC)
		return string("Equilateral");
	if (iSideA == iSideB || iSideA == iSideC || iSideB == iSideC)
		return string("Isosceles");
	return string("Scalene");

}

string getRangeMsg()
{
	return "[" + to_string(iTriangleMinLength) + ", " + to_string(iTriangleMaxLength) + "]";
}

bool outOfRange(const int& iVal)
{
	return (iVal < iTriangleMinLength) || (iVal > iTriangleMaxLength);
}
