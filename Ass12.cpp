
#include <iostream>
using namespace std;

int main() {
    int choice;
    double value;

    do {
        cout << "\n===== UNIT CONVERSION SYSTEM =====\n";
        cout << "1. Celsius to Fahrenheit (Implicit Casting)\n";
        cout << "2. Kilometers to Meters (Implicit Casting)\n";
        cout << "3. Decimal to Integer (static_cast)\n";
        cout << "4. Double to Integer (Explicit Casting)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Program terminated.\n";
            return 1;
        }

        switch (choice) {
        case 1: {
            cout << "Enter temperature in Celsius: ";

            if (!(cin >> value)) {
                cout << "Invalid temperature input.\n";
                return 1;
            }

            double fahrenheit = value * 9.0 / 5.0 + 32;

            cout << "Temperature in Fahrenheit: "
                 << fahrenheit << " F\n";
            break;
        }

        case 2: {
            cout << "Enter distance in kilometers: ";

            if (!(cin >> value) || value < 0) {
                cout << "Invalid distance.\n";
                return 1;
            }

            double meters = value * 1000;

            cout << "Distance in meters: "
                 << meters << " m\n";
            break;
        }

        case 3: {
            cout << "Enter a decimal value: ";

            if (!(cin >> value)) {
                cout << "Invalid decimal input.\n";
                return 1;
            }

            int result = static_cast<int>(value);

            cout << "Integer value using static_cast: "
                 << result << '\n';
            break;
        }

        case 4: {
            cout << "Enter a decimal value: ";

            if (!(cin >> value)) {
                cout << "Invalid decimal input.\n";
                return 1;
            }

            int result = (int)value;

            cout << "Integer value using C-style cast: "
                 << result << '\n';
            break;
        }

        case 5:
            cout << "Exiting Unit Conversion System.\n";
            break;

        default:
            cout << "Invalid choice. Select 1-5.\n";
        }

    } while (choice != 5);

    return 0;
}
