#include "vehicle.h"
#include <iostream>
#include <conio.h> // This library is necessary for using getch() function (for Windows)

using namespace std;

// Function to add a new vehicle
void addVehicle(vector<Vehicle>& vehicles) {
    system("cls"); // Clear the screen (for Windows)

    Vehicle vehicle;

    cout << "Enter Make: ";
    getline(cin, vehicle.make);

    cout << "Enter Model: ";
    getline(cin, vehicle.model);

    cout << "Enter Year: ";
    cin >> vehicle.year;

    cin.ignore(); // Ignore newline character left in the input buffer

    cout << "Enter Insurance Info: ";
    getline(cin, vehicle.insuranceInfo);

    vehicles.push_back(vehicle);

    cout << "Vehicle added successfully!" << endl;
    cout << "Press any key to continue..." << endl;
    _getch(); // Wait for the user to press any key (for Windows)
}

// Function to display all vehicles
void displayVehicles(const vector<Vehicle>& vehicles) {
    system("cls"); // Clear the screen (for Windows)

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

    cout << "Press any key to continue..." << endl;
    _getch(); // Wait for the user to press any key (for Windows)
}

// Function to manage vehicle details (add, update, delete)
void manageVehicleDetails(vector<Vehicle>& vehicles) {
    int currentSelection = 1;

    while (true) {
        system("cls"); // Clear the screen (for Windows)
        cout << "------ Manage Vehicle Details ------" << endl;
        cout << (currentSelection == 1 ? "> " : "  ") << "1. Add Vehicle" << endl;
        cout << (currentSelection == 2 ? "> " : "  ") << "2. Update Vehicle" << endl;
        cout << (currentSelection == 3 ? "> " : "  ") << "3. Delete Vehicle" << endl;
        cout << (currentSelection == 4 ? "> " : "  ") << "4. View Vehicles" << endl;
        cout << (currentSelection == 5 ? "> " : "  ") << "5. Back to Main Menu" << endl;
        cout << "------------------------------------" << endl;

        int key = _getch(); // Get the key pressed by the user (for Windows)

        switch (key) {
        case 72: // Up arrow key
            if (currentSelection > 1)
                currentSelection--;
            break;
        case 80: // Down arrow key
            if (currentSelection < 5)
                currentSelection++;
            break;
        case 13: // Enter key
            switch (currentSelection) {
            case 1:
                addVehicle(vehicles);
                break;
            case 2:
                // Call update vehicle function
                cout << "Update Vehicle functionality not implemented yet!" << endl;
                cout << "Press any key to continue..." << endl;
                _getch(); // Wait for the user to press any key (for Windows)
                break;
            case 3:
                // Call delete vehicle function
                cout << "Delete Vehicle functionality not implemented yet!" << endl;
                cout << "Press any key to continue..." << endl;
                _getch(); // Wait for the user to press any key (for Windows)
                break;
            case 4:
                displayVehicles(vehicles);
                break;
            case 5:
                return; // Exit the function
            }
            break;
        }
    }
}
