#include <iostream>
#include <string>
#include "notepad.h"

using namespace std;

int main() {
    int choice;
    string filename;

    do {
        cout << "\n===== SIMPLE NOTEPAD =====" << endl;
        cout << "1. Write File" << endl;
        cout << "2. Read File" << endl;
        cout << "3. Append File" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // Clear the input buffer

        if (choice >= 1 && choice <= 3) {
            cout << "Enter filename: ";
            getline(cin, filename);
        }

        switch (choice) {
            case 1:
                writeFile(filename);
                break;
            case 2:
                readFile(filename);
                break;
            case 3:
                appendFile(filename);
                break;
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}