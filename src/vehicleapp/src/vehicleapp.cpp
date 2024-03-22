#include <iostream>
#include <conio.h> // This library is necessary for using getch() function (for Windows)

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
    int currentSelection = 1; // Initially selected option

    while (true) {
        showMenu(currentSelection); // Display the menu with current selection

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
                // Call Manage Vehicle Details method
                cout << "Manage Vehicle Details method has not been added yet!" << endl;
                cout << "Press any key to continue..." << endl;
                _getch(); // Wait for the user to press any key (for Windows)
                break;
            case 2:
                // Call Mileage Tracker method
                cout << "Mileage Tracker method has not been added yet!" << endl;
                cout << "Press any key to continue..." << endl;
                _getch(); // Wait for the user to press any key (for Windows)
                break;
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
            break;
        }
    }

    return 0;
}
