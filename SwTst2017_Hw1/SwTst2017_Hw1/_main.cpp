#include "gtest/gtest.h"
#include "TriangleTest.h"
#include "NextDateTest.h"

using namespace std;

GTEST_API_ int main(int argc, char **argv) {
	printf("Running main() from gtest_main.cc\n");
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

TEST_F(TriangleTest, TriangleTestWeakNormal) {
	//weak normal
	EXPECT_EQ("Equilateral", getTriangleTypeString(5, 5, 5)) << "WN Test 1 failed";
	EXPECT_EQ("Isosceles", getTriangleTypeString(2, 3, 2)) << "WN Test 2 failed";
	EXPECT_EQ("Scalene", getTriangleTypeString(4, 6, 8)) << "WN Test 3 failed";
	EXPECT_EQ("Not a triangle", getTriangleTypeString(7, 4, 1)) << "WR Test 4 failed";
}

TEST_F(TriangleTest, TriangleTestWeakRobust) {
	//weak robust
	string strA = "Value of the side A is not in the range of ";
	EXPECT_EQ(strA + getBoundaryMsg(), getTriangleTypeString(0, 3, 4)) << "SN Test 1-1 failed";
	EXPECT_EQ(strA + getBoundaryMsg(), getTriangleTypeString(201, 3, 4)) << "SN Test 1-2 failed";
	string strB = "Value of the side B is not in the range of ";
	EXPECT_EQ(strB + getBoundaryMsg(), getTriangleTypeString(2, 0, 4)) << "SN Test 2-1 failed";
	EXPECT_EQ(strB + getBoundaryMsg(), getTriangleTypeString(2, 201, 4)) << "SN Test 2-2 failed";
	string strC = "Value of the side C is not in the range of ";
	EXPECT_EQ(strC + getBoundaryMsg(), getTriangleTypeString(2, 3, 0)) << "SN Test 3-1 failed";
	EXPECT_EQ(strC + getBoundaryMsg(), getTriangleTypeString(2, 3, 201)) << "SN Test 3-2 failed";
}

TEST_F(TriangleTest, TriangleTestStrongNormal) {
	//strong normal (boundary check)
	EXPECT_EQ("Not a triangle", getTriangleTypeString(1, 3, 4)) << "SN Test 1-1 failed";
	EXPECT_EQ("Not a triangle", getTriangleTypeString(200, 3, 4)) << "SN Test 1-2 failed";
	EXPECT_EQ("Not a triangle", getTriangleTypeString(2, 1, 4)) << "SN Test 2-1 failed";
	EXPECT_EQ("Not a triangle", getTriangleTypeString(2, 200, 4)) << "SN Test 2-2 failed";
	EXPECT_EQ("Not a triangle", getTriangleTypeString(2, 3, 1)) << "SN Test 3-1 failed";
	EXPECT_EQ("Not a triangle", getTriangleTypeString(2, 3, 200)) << "SN Test 3-2 failed";

	EXPECT_EQ("Not a triangle", getTriangleTypeString(1, 1, 4)) << "SN Test 4-1 failed";
	EXPECT_EQ("Not a triangle", getTriangleTypeString(1, 200, 4)) << "SN Test 4-2 failed";
	EXPECT_EQ("Not a triangle", getTriangleTypeString(200, 1, 4)) << "SN Test 4-3 failed";
	EXPECT_EQ("Isosceles", getTriangleTypeString(200, 200, 4)) << "SN Test 4-4 failed";
	EXPECT_EQ("Not a triangle", getTriangleTypeString(1, 3, 1)) << "SN Test 5-1 failed";
	EXPECT_EQ("Not a triangle", getTriangleTypeString(1, 3, 200)) << "SN Test 5-2 failed";
	EXPECT_EQ("Not a triangle", getTriangleTypeString(200, 3, 1)) << "SN Test 5-3 failed";
	EXPECT_EQ("Isosceles", getTriangleTypeString(200, 3, 200)) << "SN Test 5-4 failed";
	EXPECT_EQ("Not a triangle", getTriangleTypeString(2, 1, 1)) << "SN Test 6-1 failed";
	EXPECT_EQ("Not a triangle", getTriangleTypeString(2, 1, 200)) << "SN Test 6-2 failed";
	EXPECT_EQ("Not a triangle", getTriangleTypeString(2, 200, 1)) << "SN Test 6-3 failed";
	EXPECT_EQ("Isosceles", getTriangleTypeString(2, 200, 200)) << "SN Test 6-4 failed";
	EXPECT_EQ("Equilateral", getTriangleTypeString(1, 1, 1)) << "SN Test 7-1 failed";
	EXPECT_EQ("Not a triangle", getTriangleTypeString(1, 1, 200)) << "SN Test 7-2 failed";
	EXPECT_EQ("Not a triangle", getTriangleTypeString(1, 200, 1)) << "SN Test 7-3 failed";
	EXPECT_EQ("Not a triangle", getTriangleTypeString(200, 1, 1)) << "SN Test 7-4 failed";
	EXPECT_EQ("Isosceles", getTriangleTypeString(1, 200, 200)) << "SN Test 7-5 failed";
	EXPECT_EQ("Isosceles", getTriangleTypeString(200, 1, 200)) << "SN Test 7-6 failed";
	EXPECT_EQ("Isosceles", getTriangleTypeString(200, 200, 1)) << "SN Test 7-7 failed";
	EXPECT_EQ("Equilateral", getTriangleTypeString(200, 200, 200)) << "SN Test 7-8 failed";
}

TEST_F(TriangleTest, TriangleTestStrongRobust) {
	//strong robust (boundary check)
	string strA = "Value of the side A is not in the range of ";
	string strB = "Value of the side B is not in the range of ";
	string strC = "Value of the side C is not in the range of ";
	EXPECT_EQ(strA + getBoundaryMsg(), getTriangleTypeString(0, 3, 4)) << "SR Test 1-1 failed";
	EXPECT_EQ(strA + getBoundaryMsg(), getTriangleTypeString(201, 3, 4)) << "SR Test 1-2 failed";
	EXPECT_EQ(strB + getBoundaryMsg(), getTriangleTypeString(2, 0, 4)) << "SR Test 2-1 failed";
	EXPECT_EQ(strB + getBoundaryMsg(), getTriangleTypeString(2, 201, 4)) << "SR Test 2-2 failed";
	EXPECT_EQ(strC + getBoundaryMsg(), getTriangleTypeString(2, 3, 0)) << "SR Test 3-1 failed";
	EXPECT_EQ(strC + getBoundaryMsg(), getTriangleTypeString(2, 3, 201)) << "SR Test 3-2 failed";

	EXPECT_EQ(strA + getBoundaryMsg(), getTriangleTypeString(0, 0, 4)) << "SR Test 4-1 failed";
	EXPECT_EQ(strA + getBoundaryMsg(), getTriangleTypeString(0, 201, 4)) << "SR Test 4-2 failed";
	EXPECT_EQ(strA + getBoundaryMsg(), getTriangleTypeString(201, 0, 4)) << "SR Test 4-3 failed";
	EXPECT_EQ(strA + getBoundaryMsg(), getTriangleTypeString(201, 201, 4)) << "SR Test 4-4 failed";
	EXPECT_EQ(strA + getBoundaryMsg(), getTriangleTypeString(0, 3, 0)) << "SR Test 5-1 failed";
	EXPECT_EQ(strA + getBoundaryMsg(), getTriangleTypeString(0, 3, 201)) << "SR Test 5-2 failed";
	EXPECT_EQ(strA + getBoundaryMsg(), getTriangleTypeString(201, 3, 0)) << "SR Test 5-3 failed";
	EXPECT_EQ(strA + getBoundaryMsg(), getTriangleTypeString(201, 3, 201)) << "SR Test 5-4 failed";
	EXPECT_EQ(strB + getBoundaryMsg(), getTriangleTypeString(2, 0, 0)) << "SR Test 6-1 failed";
	EXPECT_EQ(strB + getBoundaryMsg(), getTriangleTypeString(2, 0, 201)) << "SR Test 6-2 failed";
	EXPECT_EQ(strB + getBoundaryMsg(), getTriangleTypeString(2, 201, 0)) << "SR Test 6-3 failed";
	EXPECT_EQ(strB + getBoundaryMsg(), getTriangleTypeString(2, 201, 201)) << "SR Test 6-4 failed";
	EXPECT_EQ(strA + getBoundaryMsg(), getTriangleTypeString(0, 0, 0)) << "SR Test 7-1 failed";
	EXPECT_EQ(strA + getBoundaryMsg(), getTriangleTypeString(0, 0, 201)) << "SR Test 7-2 failed";
	EXPECT_EQ(strA + getBoundaryMsg(), getTriangleTypeString(0, 201, 0)) << "SR Test 7-3 failed";
	EXPECT_EQ(strA + getBoundaryMsg(), getTriangleTypeString(201, 0, 0)) << "SR Test 7-4 failed";
	EXPECT_EQ(strA + getBoundaryMsg(), getTriangleTypeString(0, 201, 201)) << "SR Test 7-5 failed";
	EXPECT_EQ(strA + getBoundaryMsg(), getTriangleTypeString(201, 0, 201)) << "SR Test 7-6 failed";
	EXPECT_EQ(strA + getBoundaryMsg(), getTriangleTypeString(201, 201, 0)) << "SR Test 7-7 failed";
	EXPECT_EQ(strA + getBoundaryMsg(), getTriangleTypeString(201, 201, 201)) << "SR Test 7-8 failed";
}
