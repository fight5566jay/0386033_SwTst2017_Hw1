#pragma once
#include <string>
#include "gtest/gtest.h"
#include "Triangle.h"

using namespace std;
class TriangleTest :	public ::testing::Test{
public:
	TriangleTest() {};
	~TriangleTest() {};

	virtual void SetUp() {}
	virtual void TearDown() {}

	inline string getTriangleTypeString(const int & iSideA, const int & iSideB, const int & iSideC) const { return getTriangleType(iSideA, iSideB, iSideC); };
	inline string getBoundaryMsg() const { return getRangeMsg(); };

};

