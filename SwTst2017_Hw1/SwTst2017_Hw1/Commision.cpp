#include "Commision.h"
#include <sstream>

using namespace std;
string getCommision(const string& sInput)
{
	stringstream ss;
	string sResult;
	ss << sInput;
	const int iLockPrice = 45;
	const int iStockPrice = 30;
	const int iBarrelPrice = 25;
	int iTotalLocks = 0;
	int iTotalStocks = 0;
	int iTotalBarrels = 0;
	int iLocks;
	int iStocks;
	int iBarrels;
	float fCommision;

	ss >> iLocks;
	while (iLocks != -1) {
		if (iLocks < 0 || iLocks > 70) {
			return "Out of range: Locks must be in range [0, 70]";
		}
		ss >> iStocks >> iBarrels;
		if (iStocks < 0 || iStocks > 80) {
			return "Out of range: Stocks must be in range [0, 80]";
		}
		if (iBarrels < 0 || iBarrels > 90) {
			return "Out of range: Barrels must be in range [0, 90]";
		}
		iTotalLocks += iLocks;
		iTotalStocks += iStocks;
		iTotalBarrels += iBarrels;
		ss >> iLocks;
	}

	float fLockSales = iLockPrice * iTotalLocks;
	float fStockSales = iStockPrice * iTotalStocks;
	float fBarrelSales = iBarrelPrice * iTotalBarrels;
	float fSales = fLockSales + fStockSales + fBarrelSales;

	if (fSales > 1800.0) {
		fCommision = 0.1 * 1000.0;
		fCommision += 0.15 * 800.0;
		fCommision += 0.2 * (fSales - 1800.0);
	}
	else if (fSales > 1000.0) {
		fCommision = 0.1 * 1000.0;
		fCommision += 0.15 * (fSales - 1000.0);
	}
	else
		fCommision = 0.1 * fSales;

	ss.clear();
	ss << fCommision;
	ss >> sResult;
	return sResult;
}
