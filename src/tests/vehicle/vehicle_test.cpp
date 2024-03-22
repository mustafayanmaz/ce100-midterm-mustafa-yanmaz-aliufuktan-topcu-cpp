//#define ENABLE_VEHICLE_TEST  // Uncomment this line to enable the Vehicle tests

#include "gtest/gtest.h"
#include "../../vehicle/header/vehicle.h"  // Adjust this include path based on your project structure

using namespace Coruh::Vehicle;

class VehicleTest : public ::testing::Test {
protected:
	void SetUp() override {
		// Setup test data
	}

	void TearDown() override {
		// Clean up test data
	}
};

TEST_F(VehicleTest, TestAdd) {
	double result = Vehicle::add(5.0, 3.0);
	EXPECT_DOUBLE_EQ(result, 8.0);
}

TEST_F(VehicleTest, TestSubtract) {
	double result = Vehicle::subtract(5.0, 3.0);
	EXPECT_DOUBLE_EQ(result, 2.0);
}

TEST_F(VehicleTest, TestMultiply) {
	double result = Vehicle::multiply(5.0, 3.0);
	EXPECT_DOUBLE_EQ(result, 15.0);
}

TEST_F(VehicleTest, TestDivide) {
	double result = Vehicle::divide(6.0, 3.0);
	EXPECT_DOUBLE_EQ(result, 2.0);
}

TEST_F(VehicleTest, TestDivideByZero) {
	EXPECT_THROW(Vehicle::divide(5.0, 0.0), std::invalid_argument);
}

/**
 * @brief The main function of the test program.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line argument strings.
 * @return int The exit status of the program.
 */
int main(int argc, char** argv) {
#ifdef ENABLE_VEHICLE_TEST
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
#else
	return 0;
#endif
}