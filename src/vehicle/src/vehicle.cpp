#include "vehicle.h"
#include <iostream>
#include <conio.h>

using namespace std;

// Function to add a new vehicle
void addVehicle(std::vector<Vehicle>& vehicles, std::istream& input_stream = std::cin, std::ostream& output_stream = std::cout) {
    Vehicle vehicle;

    output_stream << "Enter Make: ";
    std::getline(input_stream, vehicle.make);

    output_stream << "Enter Model: ";
    std::getline(input_stream, vehicle.model);

    output_stream << "Enter Year: ";
    input_stream >> vehicle.year;
    input_stream.ignore();

    output_stream << "Enter Insurance Info: ";
    std::getline(input_stream, vehicle.insuranceInfo);

    vehicles.push_back(vehicle);

    output_stream << "Vehicle added successfully!" << std::endl;
}

// Function to display all vehicles
void displayVehicles(const vector<Vehicle>& vehicles) {
    system("cls");

    if (vehicles.empty()) {
        cout << "No vehicles found!" << endl;
    }
    else {
        cout << "---- Vehicle List ----" << endl;
        for (size_t i = 0; i < vehicles.size(); ++i) {
            cout << "Vehicle " << i + 1 << ":" << endl;
            cout << "Make: " << vehicles[i].make << endl;
            cout << "Model: " << vehicles[i].model << endl;
            cout << "Year: " << vehicles[i].year << endl;
            cout << "Insurance Info: " << vehicles[i].insuranceInfo << endl << endl;
        }
    }

    cout << "Press Enter to continue..." << endl;
    cin.ignore();
    cin.get();
}

// Function to update vehicle details
void updateVehicle(vector<Vehicle>& vehicles) {
    system("cls");

    if (vehicles.empty()) {
        cout << "No vehicles found!" << endl;
        cout << "Press Enter to continue..." << endl;
        cin.ignore();
        cin.get();
        return;
    }

    int selection;
    cout << "Select the vehicle to update (Enter vehicle number): ";
    cin >> selection;

    if (selection <= 0 || selection > vehicles.size()) {
        cout << "Invalid selection!" << endl;
        cout << "Press Enter to continue..." << endl;
        cin.ignore();
        cin.get();
        return;
    }

    Vehicle& vehicle = vehicles[selection - 1];

    cout << "Enter Make: ";
    cin.ignore();
    getline(cin, vehicle.make);

    cout << "Enter Model: ";
    getline(cin, vehicle.model);

    cout << "Enter Year: ";
    cin >> vehicle.year;

    cin.ignore();

    cout << "Enter Insurance Info: ";
    getline(cin, vehicle.insuranceInfo);

    cout << "Vehicle details updated successfully!" << endl;
    cout << "Press Enter to continue..." << endl;
    cin.ignore();
    cin.get();
}

// Function to delete a vehicle
void deleteVehicle(vector<Vehicle>& vehicles) {
    system("cls");

    if (vehicles.empty()) {
        cout << "No vehicles found!" << endl;
        cout << "Press Enter to continue..." << endl;
        cin.ignore();
        cin.get();
        return;
    }

    int selection;
    cout << "Select the vehicle to delete (Enter vehicle number): ";
    cin >> selection;

    if (selection <= 0 || selection > vehicles.size()) {
        cout << "Invalid selection!" << endl;
        cout << "Press Enter to continue..." << endl;
        cin.ignore();
        cin.get();
        return;
    }

    vehicles.erase(vehicles.begin() + selection - 1);

    cout << "Vehicle deleted successfully!" << endl;
    cout << "Press Enter to continue..." << endl;
    cin.ignore();
    cin.get();
}