#ifndef VEHICLE_H
#define VEHICLE_H

#include <vector>
#include <string>

using namespace std;

// Structure to hold vehicle details
struct Vehicle {
    string make;
    string model;
    int year;
    string insuranceInfo;
};

void manageVehicleDetails(vector<Vehicle>& vehicles);

#endif
