#include <gtest/gtest.h>
#include <vector>
#include "vehicle.h" // Assuming vehicle.h contains the definition of the Vehicle class
#include <iostream>
#include <sstream>


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


// Define a testing fixture for displayVehicles function
class DisplayVehiclesTest : public ::testing::Test {
protected:
    // Define test setup
    void SetUp() override {

        // Redirect cout to a stringstream
        testing_stream.str(""); // Clear the stream
        original_cout_buffer = std::cout.rdbuf(); // Save the original buffer
        std::cout.rdbuf(testing_stream.rdbuf()); // Redirect cout to testing_stream
    }

    // Define test teardown
    void TearDown() override {
        // Restore the original cout buffer
        std::cout.rdbuf(original_cout_buffer);
    }

    // Define variables for testing
    std::stringstream testing_stream; // Stream to capture output
    std::streambuf* original_cout_buffer; // Original cout buffer
};

// Test case for displayVehicles function
TEST_F(DisplayVehiclesTest, DisplayVehiclesOutput) {
    // Create some test vehicles
    std::vector<Vehicle> test_vehicles = {
        {"Toyota", "Camry", 2020, "ABC123"},
        {"Honda", "Accord", 2019, "DEF456"}
    };

    // Call the function to be tested
    displayVehicles(test_vehicles);

    // Define the expected output
    std::string expected_output =
        "---- Vehicle List ----\n"
        "Vehicle 1:\n"
        "Make: Toyota\n"
        "Model: Camry\n"
        "Year: 2020\n"
        "Insurance Info: ABC123\n\n"
        "Vehicle 2:\n"
        "Make: Honda\n"
        "Model: Accord\n"
        "Year: 2019\n"
        "Insurance Info: DEF456\n\n"
        "Press Enter to continue...\n";

    // Compare the expected output with the actual output
    ASSERT_EQ(testing_stream.str(), expected_output);
}
void updateVehicle(std::vector<Vehicle>& vehicles);

// Test case for updateVehicle function
TEST(UpdateVehicleTest, UpdatesVehicleSuccessfully) {
    // Create a test vector of vehicles
    std::vector<Vehicle> test_vehicles = {
        {"Toyota", "Camry", 2015, "ABC123"},
        {"Honda", "Accord", 2018, "DEF456"}
    };

    // Prepare input stream
    std::stringstream input_stream;
    input_stream << "1\n" // Selecting the first vehicle
        << "Updated Make\n"
        << "Updated Model\n"
        << "2022\n"
        << "Updated Insurance\n";

    // Redirect cin and cout
    std::stringstream output_stream;
    std::streambuf* orig_cin = std::cin.rdbuf(input_stream.rdbuf());
    std::streambuf* orig_cout = std::cout.rdbuf(output_stream.rdbuf());

    // Call the function to be tested
    updateVehicle(test_vehicles);

    // Restore cin and cout
    std::cin.rdbuf(orig_cin);
    std::cout.rdbuf(orig_cout);

    // Check if the vehicle details are updated correctly
    ASSERT_EQ("Updated Make", test_vehicles[0].make);
    ASSERT_EQ("Updated Model", test_vehicles[0].model);
    ASSERT_EQ(2022, test_vehicles[0].year);
    ASSERT_EQ("Updated Insurance", test_vehicles[0].insuranceInfo);

    // Check if the output stream contains the expected message
    std::string expected_output =
        "Select the vehicle to update (Enter vehicle number): "
        "Enter Make: Enter Model: Enter Year: Enter Insurance Info: "
        "Vehicle details updated successfully!\nPress Enter to continue...\n";
    ASSERT_EQ(expected_output, output_stream.str());
}
void deleteVehicle(std::vector<Vehicle>& vehicles);

// Test case for deleteVehicle function
TEST(DeleteVehicleTest, DeletesVehicleSuccessfully) {
    // Create a test vector of vehicles
    std::vector<Vehicle> test_vehicles = {
        {"Toyota", "Camry", 2015, "ABC123"},
        {"Honda", "Accord", 2018, "DEF456"}
    };

    // Prepare input stream
    std::stringstream input_stream;
    input_stream << "2\n"; // Selecting the second vehicle

    // Redirect cin and cout
    std::stringstream output_stream;
    std::streambuf* orig_cin = std::cin.rdbuf(input_stream.rdbuf());
    std::streambuf* orig_cout = std::cout.rdbuf(output_stream.rdbuf());

    // Call the function to be tested
    deleteVehicle(test_vehicles);

    // Restore cin and cout
    std::cin.rdbuf(orig_cin);
    std::cout.rdbuf(orig_cout);

    // Check if the vehicle is deleted successfully
    ASSERT_EQ(1, test_vehicles.size());
    ASSERT_EQ("Toyota", test_vehicles[0].make);

    // Check if the output stream contains the expected message
    std::string expected_output =
        "Select the vehicle to delete (Enter vehicle number): "
        "Vehicle deleted successfully!\nPress Enter to continue...\n";
    ASSERT_EQ(expected_output, output_stream.str());
}

// Main function to run all the tests
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}