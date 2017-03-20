#include "NextDate.h"
#include <sstream>

string getNextDate(const int & iMonth, const int & iDay, const int & iYear)
{
	string sAns;
	const int	FINAL_DAY[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int iNextYear = iYear;
	int iNextMonth = iMonth;
	//int iNextDay = iDay;
	int iNextDay = iDay + 1;
	stringstream ss;

	

	if (iMonth < 1 || iMonth > 12) {
		return string("Value of the month is not in the range of [1, 12]");
	}

	if (iYear < 1812 || iYear > 2012) {
		return string("Value of the year is not in the range of [1812, 2012]");
	}

	int iMaxDay = (iMonth == 2 && isLeapYear(iYear)) ? 29 : FINAL_DAY[iMonth];
	if (iDay < 1 || iDay > iMaxDay) {
		return string("Value of the day is not in the range of [1, " + to_string(iMaxDay)+ "]");
	}

	


	if (iMonth == 2 && iDay == 28 && isLeapYear(iYear)) {//special case
		return "2/29/" + to_string(iYear);
	}

	//iNextDay++;
	if (iNextDay > FINAL_DAY[iMonth]) {
		iNextDay = 1;
		iNextMonth++;
		if (iNextMonth > 12) {
			iNextMonth = 1;
			iNextYear++;
		}
	}

	ss << iNextMonth << "/" << iNextDay << "/" << iNextYear;
	ss >> sAns;
	return sAns;
}

bool isLeapYear(const int& iYear)
{
	if (iYear % 400 == 0)
		return true;
	if (iYear % 100 == 0)
		return false;
	return iYear % 4 == 0;
}
