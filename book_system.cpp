#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// 1. Function to read and show C++ history from history.txt
void showHistoryChapter() {
    ifstream myFile("history.txt");
    string line;
    
    cout << "\n--- Chapter 1: History of C++ ---" << endl;
    if (myFile.is_open()) {
        while (getline(myFile, line)) {
            cout << line << endl;
        }
        myFile.close();
    } else {
        cout << "Error: Could not open history.txt file." << endl;
    }
    cout << "---------------------------------" << endl;
}

// 2. Function to show programming concepts using a sub switch-case
void showConceptsChapter() {
    int subChoice;
    cout << "\n--- Chapter 2: Core Concepts ---" << endl;
    cout << "1. Data Types" << endl;
    cout << "2. Control Flow" << endl;
    cout << "3. Loops" << endl;
    cout << "4. Arrays" << endl;
    cout << "5. File Streams" << endl;
    cout << "Enter concept number: ";
    cin >> subChoice;
    
    cout << "\n=================================" << endl;
    switch (subChoice) {
        case 1:
            cout << "Data Types: int, float, double, char, and bool are standard types." << endl;
            break;
        case 2:
            cout << "Control Flow: if, else if, else, and switch make programming decisions." << endl;
            break;
        case 3:
            cout << "Loops: for loop, while loop, and do-while loop repeat code execution." << endl;
            break;
        case 4:
            cout << "Arrays: Used to store multiple values of the same type sequentially." << endl;
            break;
        case 5:
            cout << "File Streams: ifstream is used for reading, ofstream for writing files." << endl;
            break;
        default:
            cout << "Invalid concept selection." << endl;
    }
    cout << "=================================" << endl;
}

int main() {
    int mainChoice;
    
    // Main Menu Loop with Switch-Case
    do {
        cout << "\n=== C++ INTERACTIVE BOOK ===" << endl;
        cout << "1. Read C++ History" << endl;
        cout << "2. Learn C++ Concepts" << endl;
        cout << "3. Exit Book" << endl;
        cout << "Enter your choice: ";
        cin >> mainChoice;
        
        switch (mainChoice) {
            case 1:
                showHistoryChapter(); 
                break;
            case 2:
                showConceptsChapter(); 
                break;
            case 3:
                cout << "Closing the book. Bye!" << endl;
                break;
            default:
                cout << "Invalid choice, try again." << endl;
        }
    } while (mainChoice != 3);
    
    return 0;
}
