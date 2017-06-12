#include "gtest/gtest.h"
#include "Triangle.h"
#include "NextDate.h"
#include "Commision.h"

using namespace std;

GTEST_API_ int main(int argc, char **argv) {
	printf("Running main() from gtest_main.cc\n");
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	system("pause");
	return 0;
}

TEST(TriangleTest, TriangleTestWeakNormal) {
	//weak normal
	EXPECT_EQ("Equilateral", getTriangleType(5, 5, 5)) << "WN Test 1 failed";
	EXPECT_EQ("Isosceles", getTriangleType(2, 3, 2)) << "WN Test 2 failed";
	EXPECT_EQ("Scalene", getTriangleType(4, 6, 8)) << "WN Test 3 failed";
	EXPECT_EQ("Not a triangle", getTriangleType(7, 4, 1)) << "WR Test 4 failed";
}

TEST(TriangleTest, TriangleTestWeakRobust) {
	//weak robust
	string strA = "Value of the side A is not in the range of ";
	EXPECT_EQ(strA + getRangeMsg(), getTriangleType(0, 3, 4)) << "SN Test 1-1 failed";
	EXPECT_EQ(strA + getRangeMsg(), getTriangleType(201, 3, 4)) << "SN Test 1-2 failed";
	string strB = "Value of the side B is not in the range of ";
	EXPECT_EQ(strB + getRangeMsg(), getTriangleType(2, 0, 4)) << "SN Test 2-1 failed";
	EXPECT_EQ(strB + getRangeMsg(), getTriangleType(2, 201, 4)) << "SN Test 2-2 failed";
	string strC = "Value of the side C is not in the range of ";
	EXPECT_EQ(strC + getRangeMsg(), getTriangleType(2, 3, 0)) << "SN Test 3-1 failed";
	EXPECT_EQ(strC + getRangeMsg(), getTriangleType(2, 3, 201)) << "SN Test 3-2 failed";
}

TEST(TriangleTest, TriangleTestStrongNormal) {
	//strong normal (boundary check)
	//class: {1~200}
	EXPECT_EQ("Not a triangle", getTriangleType(1, 3, 4)) << "SN Test 1-1 failed";
	EXPECT_EQ("Not a triangle", getTriangleType(200, 3, 4)) << "SN Test 1-2 failed";
	EXPECT_EQ("Not a triangle", getTriangleType(2, 1, 4)) << "SN Test 2-1 failed";
	EXPECT_EQ("Not a triangle", getTriangleType(2, 200, 4)) << "SN Test 2-2 failed";
	EXPECT_EQ("Not a triangle", getTriangleType(2, 3, 1)) << "SN Test 3-1 failed";
	EXPECT_EQ("Not a triangle", getTriangleType(2, 3, 200)) << "SN Test 3-2 failed";

	EXPECT_EQ("Not a triangle", getTriangleType(1, 1, 4)) << "SN Test 4-1 failed";
	EXPECT_EQ("Not a triangle", getTriangleType(1, 200, 4)) << "SN Test 4-2 failed";
	EXPECT_EQ("Not a triangle", getTriangleType(200, 1, 4)) << "SN Test 4-3 failed";
	EXPECT_EQ("Isosceles", getTriangleType(200, 200, 4)) << "SN Test 4-4 failed";
	EXPECT_EQ("Not a triangle", getTriangleType(1, 3, 1)) << "SN Test 5-1 failed";
	EXPECT_EQ("Not a triangle", getTriangleType(1, 3, 200)) << "SN Test 5-2 failed";
	EXPECT_EQ("Not a triangle", getTriangleType(200, 3, 1)) << "SN Test 5-3 failed";
	EXPECT_EQ("Isosceles", getTriangleType(200, 3, 200)) << "SN Test 5-4 failed";
	EXPECT_EQ("Not a triangle", getTriangleType(2, 1, 1)) << "SN Test 6-1 failed";
	EXPECT_EQ("Not a triangle", getTriangleType(2, 1, 200)) << "SN Test 6-2 failed";
	EXPECT_EQ("Not a triangle", getTriangleType(2, 200, 1)) << "SN Test 6-3 failed";
	EXPECT_EQ("Isosceles", getTriangleType(2, 200, 200)) << "SN Test 6-4 failed";
	EXPECT_EQ("Equilateral", getTriangleType(1, 1, 1)) << "SN Test 7-1 failed";
	EXPECT_EQ("Not a triangle", getTriangleType(1, 1, 200)) << "SN Test 7-2 failed";
	EXPECT_EQ("Not a triangle", getTriangleType(1, 200, 1)) << "SN Test 7-3 failed";
	EXPECT_EQ("Not a triangle", getTriangleType(200, 1, 1)) << "SN Test 7-4 failed";
	EXPECT_EQ("Isosceles", getTriangleType(1, 200, 200)) << "SN Test 7-5 failed";
	EXPECT_EQ("Isosceles", getTriangleType(200, 1, 200)) << "SN Test 7-6 failed";
	EXPECT_EQ("Isosceles", getTriangleType(200, 200, 1)) << "SN Test 7-7 failed";
	EXPECT_EQ("Equilateral", getTriangleType(200, 200, 200)) << "SN Test 7-8 failed";
}

TEST(TriangleTest, TriangleTestStrongRobust) {
	//strong robust (boundary check)
	string strA = "Value of the side A is not in the range of ";
	string strB = "Value of the side B is not in the range of ";
	string strC = "Value of the side C is not in the range of ";
	EXPECT_EQ(strA + getRangeMsg(), getTriangleType(0, 3, 4)) << "SR Test 1-1 failed";
	EXPECT_EQ(strA + getRangeMsg(), getTriangleType(201, 3, 4)) << "SR Test 1-2 failed";
	EXPECT_EQ(strB + getRangeMsg(), getTriangleType(2, 0, 4)) << "SR Test 2-1 failed";
	EXPECT_EQ(strB + getRangeMsg(), getTriangleType(2, 201, 4)) << "SR Test 2-2 failed";
	EXPECT_EQ(strC + getRangeMsg(), getTriangleType(2, 3, 0)) << "SR Test 3-1 failed";
	EXPECT_EQ(strC + getRangeMsg(), getTriangleType(2, 3, 201)) << "SR Test 3-2 failed";

	EXPECT_EQ(strA + getRangeMsg(), getTriangleType(0, 0, 4)) << "SR Test 4-1 failed";
	EXPECT_EQ(strA + getRangeMsg(), getTriangleType(0, 201, 4)) << "SR Test 4-2 failed";
	EXPECT_EQ(strA + getRangeMsg(), getTriangleType(201, 0, 4)) << "SR Test 4-3 failed";
	EXPECT_EQ(strA + getRangeMsg(), getTriangleType(201, 201, 4)) << "SR Test 4-4 failed";
	EXPECT_EQ(strA + getRangeMsg(), getTriangleType(0, 3, 0)) << "SR Test 5-1 failed";
	EXPECT_EQ(strA + getRangeMsg(), getTriangleType(0, 3, 201)) << "SR Test 5-2 failed";
	EXPECT_EQ(strA + getRangeMsg(), getTriangleType(201, 3, 0)) << "SR Test 5-3 failed";
	EXPECT_EQ(strA + getRangeMsg(), getTriangleType(201, 3, 201)) << "SR Test 5-4 failed";
	EXPECT_EQ(strB + getRangeMsg(), getTriangleType(2, 0, 0)) << "SR Test 6-1 failed";
	EXPECT_EQ(strB + getRangeMsg(), getTriangleType(2, 0, 201)) << "SR Test 6-2 failed";
	EXPECT_EQ(strB + getRangeMsg(), getTriangleType(2, 201, 0)) << "SR Test 6-3 failed";
	EXPECT_EQ(strB + getRangeMsg(), getTriangleType(2, 201, 201)) << "SR Test 6-4 failed";
	EXPECT_EQ(strA + getRangeMsg(), getTriangleType(0, 0, 0)) << "SR Test 7-1 failed";
	EXPECT_EQ(strA + getRangeMsg(), getTriangleType(0, 0, 201)) << "SR Test 7-2 failed";
	EXPECT_EQ(strA + getRangeMsg(), getTriangleType(0, 201, 0)) << "SR Test 7-3 failed";
	EXPECT_EQ(strA + getRangeMsg(), getTriangleType(201, 0, 0)) << "SR Test 7-4 failed";
	EXPECT_EQ(strA + getRangeMsg(), getTriangleType(0, 201, 201)) << "SR Test 7-5 failed";
	EXPECT_EQ(strA + getRangeMsg(), getTriangleType(201, 0, 201)) << "SR Test 7-6 failed";
	EXPECT_EQ(strA + getRangeMsg(), getTriangleType(201, 201, 0)) << "SR Test 7-7 failed";
	EXPECT_EQ(strA + getRangeMsg(), getTriangleType(201, 201, 201)) << "SR Test 7-8 failed";
}

TEST(NextDateTest, NextDateTestWeakNormal) {
	//weak normal
	EXPECT_EQ("1/16/2000", getNextDate(1, 15, 2000)) << "WN Test 1 failed";
	EXPECT_EQ("3/1/1999", getNextDate(2, 28, 1999)) << "WN Test 2 failed";
	EXPECT_EQ("2/29/2004", getNextDate(2, 28, 2004)) << "WN Test 3 failed";
}

TEST(NextDateTest, NextDateTestWeakRobust) {
	//weak robust
	EXPECT_EQ("Value of the day is not in the range of [1, 31]", getNextDate(1, 32, 2000)) << "WR Test 1 failed";
	EXPECT_EQ("Value of the month is not in the range of [1, 12]", getNextDate(13, 28, 1999)) << "WR Test 2 failed";
	EXPECT_EQ("Value of the year is not in the range of [1812, 2012]", getNextDate(2, 28, 2014)) << "WR Test 3 failed";
}

TEST(NextDateTest, NextDateTestStrongNormal) {
	//strong normal
	//class of month: {month has 30 days, month has 31 days except December, February, December}
	//class of day: {1~27, 28, 29, 30, 31}
	//class of year: {2000, 100x, 4x, else}
	
	EXPECT_EQ("1/2/2000", getNextDate(1, 1, 2000)) << "SN Test 1-1-1 failed";
	EXPECT_EQ("4/2/2000", getNextDate(4, 1, 2000)) << "SN Test 1-1-2 failed";
	EXPECT_EQ("2/2/2000", getNextDate(2, 1, 2000)) << "SN Test 1-1-3 failed";
	EXPECT_EQ("12/2/2000", getNextDate(12, 1, 2000)) << "SN Test 1-1-4 failed";
	EXPECT_EQ("1/29/2000", getNextDate(1, 28, 2000)) << "SN Test 1-2-1 failed";
	EXPECT_EQ("4/29/2000", getNextDate(4, 28, 2000)) << "SN Test 1-2-2 failed";
	EXPECT_EQ("2/29/2000", getNextDate(2, 28, 2000)) << "SN Test 1-2-3 failed";
	EXPECT_EQ("12/29/2000", getNextDate(12, 28, 2000)) << "SN Test 1-2-4 failed";
	EXPECT_EQ("1/30/2000", getNextDate(1, 29, 2000)) << "SN Test 1-3-1 failed";
	EXPECT_EQ("4/30/2000", getNextDate(4, 29, 2000)) << "SN Test 1-3-2 failed";
	EXPECT_EQ("3/1/2000", getNextDate(2, 29, 2000)) << "SN Test 1-3-3 failed";
	EXPECT_EQ("12/30/2000", getNextDate(12, 29, 2000)) << "SN Test 1-3-4 failed";
	EXPECT_EQ("1/31/2000", getNextDate(1, 30, 2000)) << "SN Test 1-4-1 failed";
	EXPECT_EQ("5/1/2000", getNextDate(4, 30, 2000)) << "SN Test 1-4-2 failed";
	EXPECT_EQ("Value of the day is not in the range of [1, 29]", getNextDate(2, 30, 2000)) << "SN Test 1-4-3 failed";
	EXPECT_EQ("12/31/2000", getNextDate(12, 30, 2000)) << "SN Test 1-4-4 failed";
	EXPECT_EQ("2/1/2000", getNextDate(1, 31, 2000)) << "SN Test 1-5-1 failed";
	EXPECT_EQ("Value of the day is not in the range of [1, 30]", getNextDate(4, 31, 2000)) << "SN Test 1-5-2 failed";
	EXPECT_EQ("Value of the day is not in the range of [1, 29]", getNextDate(2, 31, 2000)) << "SN Test 1-5-3 failed";
	EXPECT_EQ("1/1/2001", getNextDate(12, 31, 2000)) << "SN Test 1-5-4 failed";

	EXPECT_EQ("1/2/1900", getNextDate(1, 1, 1900)) << "SN Test 2-1-1 failed";
	EXPECT_EQ("4/2/1900", getNextDate(4, 1, 1900)) << "SN Test 2-1-2 failed";
	EXPECT_EQ("2/2/1900", getNextDate(2, 1, 1900)) << "SN Test 2-1-3 failed";
	EXPECT_EQ("12/2/1900", getNextDate(12, 1, 1900)) << "SN Test 2-1-4 failed";
	EXPECT_EQ("1/29/1900", getNextDate(1, 28, 1900)) << "SN Test 2-2-1 failed";
	EXPECT_EQ("4/29/1900", getNextDate(4, 28, 1900)) << "SN Test 2-2-2 failed";
	EXPECT_EQ("3/1/1900", getNextDate(2, 28, 1900)) << "SN Test 2-2-3 failed";
	EXPECT_EQ("12/29/1900", getNextDate(12, 28, 1900)) << "SN Test 2-2-4 failed";
	EXPECT_EQ("1/30/1900", getNextDate(1, 29, 1900)) << "SN Test 2-3-1 failed";
	EXPECT_EQ("4/30/1900", getNextDate(4, 29, 1900)) << "SN Test 2-3-2 failed";
	EXPECT_EQ("Value of the day is not in the range of [1, 28]", getNextDate(2, 29, 1900)) << "SN Test 2-3-3 failed";
	EXPECT_EQ("12/30/1900", getNextDate(12, 29, 1900)) << "SN Test 2-3-4 failed";
	EXPECT_EQ("1/31/1900", getNextDate(1, 30, 1900)) << "SN Test 2-4-1 failed";
	EXPECT_EQ("5/1/1900", getNextDate(4, 30, 1900)) << "SN Test 2-4-2 failed";
	EXPECT_EQ("Value of the day is not in the range of [1, 28]", getNextDate(2, 30, 1900)) << "SN Test 2-4-3 failed";
	EXPECT_EQ("12/31/1900", getNextDate(12, 30, 1900)) << "SN Test 2-4-4 failed";
	EXPECT_EQ("2/1/1900", getNextDate(1, 31, 1900)) << "SN Test 2-5-1 failed";
	EXPECT_EQ("Value of the day is not in the range of [1, 30]", getNextDate(4, 31, 1900)) << "SN Test 2-5-2 failed";
	EXPECT_EQ("Value of the day is not in the range of [1, 28]", getNextDate(2, 31, 1900)) << "SN Test 2-5-3 failed";
	EXPECT_EQ("1/1/1901", getNextDate(12, 31, 1900)) << "SN Test 2-5-4 failed";

	EXPECT_EQ("1/2/2004", getNextDate(1, 1, 2004)) << "SN Test 3-1-1 failed";
	EXPECT_EQ("4/2/2004", getNextDate(4, 1, 2004)) << "SN Test 3-1-2 failed";
	EXPECT_EQ("2/2/2004", getNextDate(2, 1, 2004)) << "SN Test 3-1-3 failed";
	EXPECT_EQ("12/2/2004", getNextDate(12, 1, 2004)) << "SN Test 3-1-4 failed";
	EXPECT_EQ("1/29/2004", getNextDate(1, 28, 2004)) << "SN Test 3-2-1 failed";
	EXPECT_EQ("4/29/2004", getNextDate(4, 28, 2004)) << "SN Test 3-2-2 failed";
	EXPECT_EQ("2/29/2004", getNextDate(2, 28, 2004)) << "SN Test 3-2-3 failed";
	EXPECT_EQ("12/29/2004", getNextDate(12, 28, 2004)) << "SN Test 3-2-4 failed";
	EXPECT_EQ("1/30/2004", getNextDate(1, 29, 2004)) << "SN Test 3-3-1 failed";
	EXPECT_EQ("4/30/2004", getNextDate(4, 29, 2004)) << "SN Test 3-3-2 failed";
	EXPECT_EQ("3/1/2004", getNextDate(2, 29, 2004)) << "SN Test 3-3-3 failed";
	EXPECT_EQ("12/30/2004", getNextDate(12, 29, 2004)) << "SN Test 3-3-4 failed";
	EXPECT_EQ("1/31/2004", getNextDate(1, 30, 2004)) << "SN Test 3-4-1 failed";
	EXPECT_EQ("5/1/2004", getNextDate(4, 30, 2004)) << "SN Test 3-4-2 failed";
	EXPECT_EQ("Value of the day is not in the range of [1, 29]", getNextDate(2, 30, 2004)) << "SN Test 3-4-3 failed";
	EXPECT_EQ("12/31/2004", getNextDate(12, 30, 2004)) << "SN Test 3-4-4 failed";
	EXPECT_EQ("2/1/2004", getNextDate(1, 31, 2004)) << "SN Test 3-5-1 failed";
	EXPECT_EQ("Value of the day is not in the range of [1, 30]", getNextDate(4, 31, 2004)) << "SN Test 3-5-2 failed";
	EXPECT_EQ("Value of the day is not in the range of [1, 29]", getNextDate(2, 31, 2004)) << "SN Test 3-5-3 failed";
	EXPECT_EQ("1/1/2005", getNextDate(12, 31, 2004)) << "SN Test 3-5-4 failed";

	EXPECT_EQ("1/2/1999", getNextDate(1, 1, 1999)) << "SN Test 4-1-1 failed";
	EXPECT_EQ("4/2/1999", getNextDate(4, 1, 1999)) << "SN Test 4-1-2 failed";
	EXPECT_EQ("2/2/1999", getNextDate(2, 1, 1999)) << "SN Test 4-1-3 failed";
	EXPECT_EQ("12/2/1999", getNextDate(12, 1, 1999)) << "SN Test 4-1-4 failed";
	EXPECT_EQ("1/29/1999", getNextDate(1, 28, 1999)) << "SN Test 4-2-1 failed";
	EXPECT_EQ("4/29/1999", getNextDate(4, 28, 1999)) << "SN Test 4-2-2 failed";
	EXPECT_EQ("3/1/1999", getNextDate(2, 28, 1999)) << "SN Test 4-2-3 failed";
	EXPECT_EQ("12/29/1999", getNextDate(12, 28, 1999)) << "SN Test 4-2-4 failed";
	EXPECT_EQ("1/30/1999", getNextDate(1, 29, 1999)) << "SN Test 4-3-1 failed";
	EXPECT_EQ("4/30/1999", getNextDate(4, 29, 1999)) << "SN Test 4-3-2 failed";
	EXPECT_EQ("Value of the day is not in the range of [1, 28]", getNextDate(2, 29, 1999)) << "SN Test 4-3-3 failed";
	EXPECT_EQ("12/30/1999", getNextDate(12, 29, 1999)) << "SN Test 4-3-4 failed";
	EXPECT_EQ("1/31/1999", getNextDate(1, 30, 1999)) << "SN Test 4-4-1 failed";
	EXPECT_EQ("5/1/1999", getNextDate(4, 30, 1999)) << "SN Test 4-4-2 failed";
	EXPECT_EQ("Value of the day is not in the range of [1, 28]", getNextDate(2, 30, 1999)) << "SN Test 4-4-3 failed";
	EXPECT_EQ("12/31/1999", getNextDate(12, 30, 1999)) << "SN Test 4-4-4 failed";
	EXPECT_EQ("2/1/1999", getNextDate(1, 31, 1999)) << "SN Test 4-5-1 failed";
	EXPECT_EQ("Value of the day is not in the range of [1, 30]", getNextDate(4, 31, 1999)) << "SN Test 4-5-2 failed";
	EXPECT_EQ("Value of the day is not in the range of [1, 28]", getNextDate(2, 31, 1999)) << "SN Test 4-5-3 failed";
	EXPECT_EQ("1/1/2000", getNextDate(12, 31, 1999)) << "SN Test 4-5-4 failed";

}

TEST(NextDateTest, NextDateTestStrongRobust) {
	//strong robust
	//boundary check
	//month: [1, 12]
	//day: [1, 31]
	//year: [1812, 2012]
	EXPECT_EQ("Value of the month is not in the range of [1, 12]", getNextDate(0, 31, 2000)) << "SR Test 2-1-1 failed";
	EXPECT_EQ("Value of the month is not in the range of [1, 12]", getNextDate(13, 31, 2000)) << "SR Test 3-1-1 failed";

	EXPECT_EQ("Value of the day is not in the range of [1, 31]", getNextDate(12, 0, 2000)) << "SR Test 1-2-1 failed";
	EXPECT_EQ("Value of the day is not in the range of [1, 31]", getNextDate(12, 32, 2000)) << "SR Test 1-3-1 failed";

	EXPECT_EQ("Value of the year is not in the range of [1812, 2012]", getNextDate(12, 31, 1811)) << "SR Test 1-1-2 failed";
	EXPECT_EQ("Value of the year is not in the range of [1812, 2012]", getNextDate(12, 31, 2013)) << "SR Test 1-1-3 failed";

	EXPECT_EQ("Value of the year is not in the range of [1812, 2012]", getNextDate(12, 0, 1811)) << "SR Test 1-2-2 failed";
	EXPECT_EQ("Value of the year is not in the range of [1812, 2012]", getNextDate(12, 32, 1811)) << "SR Test 1-3-2 failed";
	EXPECT_EQ("Value of the year is not in the range of [1812, 2012]", getNextDate(12, 0, 2013)) << "SR Test 1-2-3 failed";
	EXPECT_EQ("Value of the year is not in the range of [1812, 2012]", getNextDate(12, 32, 2013)) << "SR Test 1-3-3 failed";

	EXPECT_EQ("Value of the month is not in the range of [1, 12]", getNextDate(0, 12, 1811)) << "SR Test 2-1-2 failed";
	EXPECT_EQ("Value of the month is not in the range of [1, 12]", getNextDate(13, 12, 1811)) << "SR Test 3-1-2 failed";
	EXPECT_EQ("Value of the month is not in the range of [1, 12]", getNextDate(0, 12, 2013)) << "SR Test 2-1-3 failed";
	EXPECT_EQ("Value of the month is not in the range of [1, 12]", getNextDate(13, 12, 2013)) << "SR Test 3-1-3 failed";

	EXPECT_EQ("Value of the month is not in the range of [1, 12]", getNextDate(0, 0, 2000)) << "SR Test 2-2-1 failed";
	EXPECT_EQ("Value of the month is not in the range of [1, 12]", getNextDate(0, 32, 2000)) << "SR Test 2-3-1 failed";
	EXPECT_EQ("Value of the month is not in the range of [1, 12]", getNextDate(13, 0, 2000)) << "SR Test 3-2-1 failed";
	EXPECT_EQ("Value of the month is not in the range of [1, 12]", getNextDate(13, 32, 2000)) << "SR Test 3-3-1 failed";

	EXPECT_EQ("Value of the month is not in the range of [1, 12]", getNextDate(0, 0, 1811)) << "SR Test 2-2-2 failed";
	EXPECT_EQ("Value of the month is not in the range of [1, 12]", getNextDate(0, 32, 1811)) << "SR Test 2-3-2 failed";
	EXPECT_EQ("Value of the month is not in the range of [1, 12]", getNextDate(13, 0, 1811)) << "SR Test 3-2-2 failed";
	EXPECT_EQ("Value of the month is not in the range of [1, 12]", getNextDate(13, 32, 1811)) << "SR Test 3-3-2 failed";
	EXPECT_EQ("Value of the month is not in the range of [1, 12]", getNextDate(0, 0, 2013)) << "SR Test 2-2-3 failed";
	EXPECT_EQ("Value of the month is not in the range of [1, 12]", getNextDate(0, 32, 2013)) << "SR Test 2-3-3 failed";
	EXPECT_EQ("Value of the month is not in the range of [1, 12]", getNextDate(13, 0, 2013)) << "SR Test 3-2-3 failed";
	EXPECT_EQ("Value of the month is not in the range of [1, 12]", getNextDate(13, 32, 2013)) << "SR Test 3-3-3 failed";
}

TEST(CommisionTest, CommisionTestWeakNormal) {
	EXPECT_EQ("10", getCommision("1 1 1 -1")) << "WN Test 1 failed";
	EXPECT_EQ("139", getCommision("3 3 3 12 9 6 -1")) << "WN Test 2 failed";
	EXPECT_EQ("280", getCommision("7 7 7 7 7 7 7 7 7 -1")) << "WN Test 3 failed";
}

TEST(CommisionTest, CommisionTestStrongRobust) {
	//class: {Commision<1000, 1000<=Commision<1800, Commision>=1800}
	//boundary test:
	// - Locks: [0, 70]
	// - Stocks: [0, 80]
	// - Barrels: [0, 90]
	EXPECT_EQ("Out of range: Barrels must be in range [0, 90]", getCommision("1 1 -50 -1")) << "SR Test 1-1-1-1 failed";
	EXPECT_EQ("10", getCommision("1 1 1 -1")) << "SR Test 1-1-1-2 failed";
	EXPECT_EQ("Out of range: Barrels must be in range [0, 90]", getCommision("1 1 91 -1")) << "SR Test 1-1-1-3 failed";
	EXPECT_EQ("Out of range: Stocks must be in range [0, 80]", getCommision("1 -50 -50 -1")) << "SR Test 1-1-2-1 failed";
	EXPECT_EQ("Out of range: Stocks must be in range [0, 80]", getCommision("1 -50 1 -1")) << "SR Test 1-1-2-2 failed";
	EXPECT_EQ("Out of range: Stocks must be in range [0, 80]", getCommision("1 -50 91 -1")) << "SR Test 1-1-2-3 failed";
	EXPECT_EQ("Out of range: Stocks must be in range [0, 80]", getCommision("1 81 -50 -1")) << "SR Test 1-1-3-1 failed";
	EXPECT_EQ("Out of range: Stocks must be in range [0, 80]", getCommision("1 81 1 -1")) << "SR Test 1-1-3-2 failed";
	EXPECT_EQ("Out of range: Stocks must be in range [0, 80]", getCommision("1 81 91 -1")) << "SR Test 1-1-3-3 failed";
	EXPECT_EQ("Out of range: Locks must be in range [0, 70]", getCommision("-50 1 -50 -1")) << "SR Test 1-2-1-1 failed";
	EXPECT_EQ("Out of range: Locks must be in range [0, 70]", getCommision("-50 1 1 -1")) << "SR Test 1-2-1-2 failed";
	EXPECT_EQ("Out of range: Locks must be in range [0, 70]", getCommision("-50 1 91 -1")) << "SR Test 1-2-1-3 failed";
	EXPECT_EQ("Out of range: Locks must be in range [0, 70]", getCommision("-50 -50 -50 -1")) << "SR Test 1-2-2-1 failed";
	EXPECT_EQ("Out of range: Locks must be in range [0, 70]", getCommision("-50 -50 1 -1")) << "SR Test 1-2-2-2 failed";
	EXPECT_EQ("Out of range: Locks must be in range [0, 70]", getCommision("-50 -50 91 -1")) << "SR Test 1-2-2-3 failed";
	EXPECT_EQ("Out of range: Locks must be in range [0, 70]", getCommision("-50 81 -50 -1")) << "SR Test 1-2-3-1 failed";
	EXPECT_EQ("Out of range: Locks must be in range [0, 70]", getCommision("-50 81 1 -1")) << "SR Test 1-2-3-2 failed";
	EXPECT_EQ("Out of range: Locks must be in range [0, 70]", getCommision("-50 81 91 -1")) << "SR Test 1-2-3-3 failed";
	EXPECT_EQ("Out of range: Locks must be in range [0, 70]", getCommision("71 1 -50 -1")) << "SR Test 1-3-1-1 failed";
	EXPECT_EQ("Out of range: Locks must be in range [0, 70]", getCommision("71 1 1 -1")) << "SR Test 1-3-1-2 failed";
	EXPECT_EQ("Out of range: Locks must be in range [0, 70]", getCommision("71 1 91 -1")) << "SR Test 1-3-1-3 failed";
	EXPECT_EQ("Out of range: Locks must be in range [0, 70]", getCommision("71 -50 -50 -1")) << "SR Test 1-3-2-1 failed";
	EXPECT_EQ("Out of range: Locks must be in range [0, 70]", getCommision("71 -50 1 -1")) << "SR Test 1-3-2-2 failed";
	EXPECT_EQ("Out of range: Locks must be in range [0, 70]", getCommision("71 -50 91 -1")) << "SR Test 1-3-2-3 failed";
	EXPECT_EQ("Out of range: Locks must be in range [0, 70]", getCommision("71 81 -50 -1")) << "SR Test 1-3-3-1 failed";
	EXPECT_EQ("Out of range: Locks must be in range [0, 70]", getCommision("71 81 1 -1")) << "SR Test 1-3-3-2 failed";
	EXPECT_EQ("Out of range: Locks must be in range [0, 70]", getCommision("71 81 91 -1")) << "SR Test 1-3-3-3 failed";

	EXPECT_EQ("139", getCommision("15 12 9 -1")) << "SR Test 2 failed";
	EXPECT_EQ("280", getCommision("7 7 7 7 7 7 7 7 7 -1")) << "SR Test 3 failed";
}