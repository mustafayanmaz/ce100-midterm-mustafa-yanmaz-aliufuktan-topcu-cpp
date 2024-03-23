#ifndef VEHICLE_H
#define VEHICLE_H

#include <vector>
#include <string>
#include <iostream> // Include for istream and ostream

// Structure to hold vehicle details
struct Vehicle {
    std::string make;
    std::string model;
    int year;
    std::string insuranceInfo;
};


void addVehicle(std::vector<Vehicle>& vehicles, std::istream& input_stream, std::ostream& output_stream);
void displayVehicles(const std::vector<Vehicle>& vehicles);
void updateVehicle(std::vector<Vehicle>& vehicles);
void deleteVehicle(std::vector<Vehicle>& vehicles);

#endif
