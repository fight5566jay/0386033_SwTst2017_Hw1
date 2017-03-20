#pragma once
#include <string>
#include "gtest/gtest.h"
#include "NextDate.h"

using namespace std;
class NextDateTest :	public ::testing::Test
{
public:
	NextDateTest() {};
	~NextDateTest() {};

	virtual void SetUp() {}
	virtual void TearDown() {}

	inline string getNextDateString(const int& iMonth, const int& iDay, const int& iYear) const { return getNextDate(iMonth, iDay, iYear); };
};

