#include <iostream>
#include "vehicle.h"
#include <vector>
#include <limits>

#ifdef _WIN32
#include <conio.h>
#define CLEAR_SCREEN "cls"
#else
#include <unistd.h>
#define CLEAR_SCREEN "clear"
#endif

using namespace std;

// Function prototypes
void showMenu(int currentSelection);
void manageVehicleDetails(vector<Vehicle>& vehicles);

// Function to display the menu
void showMenu(int currentSelection) {
    system(CLEAR_SCREEN);

    cout << "------ MENU ------" << endl;
    cout << (currentSelection == 1 ? "> " : "  ") << "1. Manage Vehicle Details" << endl;
    cout << (currentSelection == 2 ? "> " : "  ") << "2. Mileage Tracker" << endl;
    cout << (currentSelection == 3 ? "> " : "  ") << "3. Fuel Log" << endl;
    cout << (currentSelection == 4 ? "> " : "  ") << "4. Service Reminders" << endl;
    cout << (currentSelection == 5 ? "> " : "  ") << "5. Exit" << endl;
    cout << "-------------------" << endl;
    cout << "Use arrow keys to navigate, Enter to confirm selection" << endl;
}

// Function to manage vehicle details
void manageVehicleDetails(vector<Vehicle>& vehicles) {
    int currentSelection = 1;

    while (true) {
        system(CLEAR_SCREEN);
        showMenu(currentSelection);

        char key = getchar(); // Use getchar() for input

        switch (key) {
        case 'w':
        case 'W':
            if (currentSelection > 1)
                currentSelection--;
            break;
        case 's':
        case 'S':
            if (currentSelection < 5)
                currentSelection++;
            break;
        case '\n': // Enter key pressed
            switch (currentSelection) {
            case 1: {
                int manageSelection = 1;
                while (true) {
                    system(CLEAR_SCREEN);
                    cout << "------ Manage Vehicle Details ------" << endl;
                    cout << (manageSelection == 1 ? "> " : "  ") << "1. Add Vehicle" << endl;
                    cout << (manageSelection == 2 ? "> " : "  ") << "2. Update Vehicle" << endl;
                    cout << (manageSelection == 3 ? "> " : "  ") << "3. Delete Vehicle" << endl;
                    cout << (manageSelection == 4 ? "> " : "  ") << "4. View Vehicles" << endl;
                    cout << (manageSelection == 5 ? "> " : "  ") << "5. Back to Main Menu" << endl;
                    cout << "------------------------------------" << endl;

                    char manageKey = getchar(); // Use getchar() for input
                    switch (manageKey) {
                    case 'w':
                    case 'W':
                        if (manageSelection > 1)
                            manageSelection--;
                        break;
                    case 's':
                    case 'S':
                        if (manageSelection < 5)
                            manageSelection++;
                        break;
                    case '\n': // Enter key pressed
                        switch (manageSelection) {
                        case 1:
                            addVehicle(vehicles, std::cin, std::cout);
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
                            return;
                        }
                        break;
                    }
                }
            }
            case 2:
                cout << "Mileage Tracker method has not been added yet!" << endl;
                cout << "Press any key to continue..." << endl;
                getchar(); // Use getchar() for input
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

        char key = getchar(); // Use getchar() for input

        switch (key) {
        case 'w':
        case 'W':
            if (currentSelection > 1)
                currentSelection--;
            break;
        case 's':
        case 'S':
            if (currentSelection < 5)
                currentSelection++;
            break;
        case '\n': // Enter key pressed
            switch (currentSelection) {
            case 1:
                manageVehicleDetails(vehicles);
                break;
            case 2:
                cout << "Mileage Tracker method has not been added yet!" << endl;
                cout << "Press any key to continue..." << endl;
                getchar(); // Use getchar() for input
                break;
            case 3:
                // Call Fuel Log method
                cout << "Fuel Log method has not been added yet!" << endl;
                cout << "Press any key to continue..." << endl;
                getchar(); // Use getchar() for input
                break;
            case 4:
                // Call Service Reminders method
                cout << "Service Reminders method has not been added yet!" << endl;
                cout << "Press any key to continue..." << endl;
                getchar(); // Use getchar() for input
                break;
            case 5:
                cout << "Exiting the program..." << endl;
                return 0; // Exit the program
            }
            break;
        }
    }
}
