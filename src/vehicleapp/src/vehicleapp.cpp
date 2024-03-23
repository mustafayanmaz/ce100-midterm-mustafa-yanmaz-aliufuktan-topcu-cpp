#include <iostream>
#include <conio.h> // This library is necessary for using getch() function (for Windows)
#include "vehicle.h"

using namespace std;

// Function to display the menu
void showMenu(int currentSelection) {
    system("cls"); // Clear the screen (for Windows)

    cout << "------ MENU ------" << endl;
    cout << (currentSelection == 1 ? "> " : "  ") << "1. Manage Vehicle Details" << endl;
    cout << (currentSelection == 2 ? "> " : "  ") << "2. Mileage Tracker" << endl;
    cout << (currentSelection == 3 ? "> " : "  ") << "3. Fuel Log" << endl;
    cout << (currentSelection == 4 ? "> " : "  ") << "4. Service Reminders" << endl;
    cout << (currentSelection == 5 ? "> " : "  ") << "5. Exit" << endl;
    cout << "-------------------" << endl;
    cout << "Use arrow keys to navigate, Enter to select" << endl;
}

int main() {
    vector<Vehicle> vehicles;

    int currentSelection = 1;

    while (true) {
        showMenu(currentSelection);

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
                manageVehicleDetails(vehicles);
                break;
            case 2:
                // Call Mileage Tracker method
                cout << "Mileage Tracker method has not been added yet!" << endl;
                cout << "Press any key to continue..." << endl;
                _getch(); // Wait for the
            }
        }
    }
}