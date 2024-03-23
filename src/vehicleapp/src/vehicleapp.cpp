#include <iostream>
#include <conio.h>
#include "vehicle.h"

using namespace std;

// Function to display the menu
void showMenu(int currentSelection) {
    system("cls");

    cout << "------ MENU ------" << endl;
    cout << (currentSelection == 1 ? "> " : "  ") << "1. Manage Vehicle Details" << endl;
    cout << (currentSelection == 2 ? "> " : "  ") << "2. Mileage Tracker" << endl;
    cout << (currentSelection == 3 ? "> " : "  ") << "3. Fuel Log" << endl;
    cout << (currentSelection == 4 ? "> " : "  ") << "4. Service Reminders" << endl;
    cout << (currentSelection == 5 ? "> " : "  ") << "5. Exit" << endl;
    cout << "-------------------" << endl;
    cout << "Use arrow keys to navigate, Enter to select" << endl;
}

// Function to manage vehicle details
// Function to manage vehicle details
void manageVehicleDetails(vector<Vehicle>& vehicles) {
    int currentSelection = 1;

    while (true) {
        system("cls");
        showMenu(currentSelection);

        int key = _getch();

        switch (key) {
        case 72:
            if (currentSelection > 1)
                currentSelection--;
            break;
        case 80:
            if (currentSelection < 5)
                currentSelection++;
            break;
        case 13:
            switch (currentSelection) {
            case 1: {
                int manageSelection = 1;
                while (true) {
                    system("cls");
                    cout << "------ Manage Vehicle Details ------" << endl;
                    cout << (manageSelection == 1 ? "> " : "  ") << "1. Add Vehicle" << endl;
                    cout << (manageSelection == 2 ? "> " : "  ") << "2. Update Vehicle" << endl;
                    cout << (manageSelection == 3 ? "> " : "  ") << "3. Delete Vehicle" << endl;
                    cout << (manageSelection == 4 ? "> " : "  ") << "4. View Vehicles" << endl;
                    cout << (manageSelection == 5 ? "> " : "  ") << "5. Back to Main Menu" << endl;
                    cout << "------------------------------------" << endl;

                    int manageKey = _getch();
                    switch (manageKey) {
                    case 72:
                        if (manageSelection > 1)
                            manageSelection--;
                        break;
                    case 80:
                        if (manageSelection < 5)
                            manageSelection++;
                        break;
                    case 13:
                        switch (manageSelection) {
                        case 1:
                            addVehicle(vehicles, std::cin, std::cout); // Pass std::cin and std::cout
                            break;
                        case 2:
                            updateVehicle(vehicles);
                            break;
                        case 3:
                            deleteVehicle(vehicles);
                            break;
                        case 4:
                            displayVehicles(vehicles);
                            break;
                        case 5:
                            return; // Return to main menu
                        }
                        break;
                    }
                }
            }
            case 2:
                cout << "Mileage Tracker method has not been added yet!" << endl;
                cout << "Press any key to continue..." << endl;
                _getch();
                break;
            case 3:
                // Implement Fuel Log
                break;
            case 4:
                // Implement Service Reminders
                break;
            case 5:
                return;
            }
            break;
        }
    }
}


int main() {
    vector<Vehicle> vehicles;

    int currentSelection = 1;

    while (true) {
        showMenu(currentSelection);

        int key = _getch();

        switch (key) {
        case 72:
            if (currentSelection > 1)
                currentSelection--;
            break;
        case 80:
            if (currentSelection < 5)
                currentSelection++;
            break;
        case 13:
            switch (currentSelection) {
            case 1:
                manageVehicleDetails(vehicles);
                break;
            case 2:
                cout << "Mileage Tracker method has not been added yet!" << endl;
                cout << "Press any key to continue..." << endl;
                _getch();
            case 3:
                // Call Fuel Log method
                cout << "Fuel Log method has not been added yet!" << endl;
                cout << "Press any key to continue..." << endl;
                _getch(); // Wait for the user to press any key (for Windows)
                break;
                //break break
            case 4:
                // Call Service Reminders method
                cout << "Service Reminders method has not been added yet!" << endl;
                cout << "Press any key to continue..." << endl;
                _getch(); // Wait for the user to press any key (for Windows)
                break;
                //break break
            case 5:
                cout << "Exiting the program..." << endl;
                return 0; // Exit the program
            }
        }
    }

    return 0;
}