#include <gtest/gtest.h>
#include <vector>
#include "vehicle.h" // Assuming vehicle.h contains the definition of the Vehicle class


// Test fixture for testing addVehicle function
class VehicleTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Initialize test environment before each test
        vehicles.clear(); // Clear vehicles vector
    }

    void TearDown() override {
        // Clean up test environment after each test
    }

    std::vector<Vehicle> vehicles; // Vector to hold vehicles
};

// Test case for testing addVehicle function
// 
// Test case for addVehicle function
TEST(AddVehicleTest, AddVehicleSuccessfully) {
    std::vector<Vehicle> vehicles;
    std::stringstream input_stream("Honda\nCivic\n2022\nSome insurance info\n");
    std::stringstream output_stream;

    addVehicle(vehicles, input_stream, output_stream);

    ASSERT_EQ(1, vehicles.size());
    ASSERT_EQ("Honda", vehicles[0].make);
    ASSERT_EQ("Civic", vehicles[0].model);
    ASSERT_EQ(2022, vehicles[0].year);
    ASSERT_EQ("Some insurance info", vehicles[0].insuranceInfo);
    ASSERT_EQ("Enter Make: Enter Model: Enter Year: Enter Insurance Info: Vehicle added successfully!\n", output_stream.str());
}


// Main function to run all the tests
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
