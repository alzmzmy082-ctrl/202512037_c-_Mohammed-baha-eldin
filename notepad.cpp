#include <iostream>
#include <fstream>
#include <string>
#include "notepad.h"

using namespace std;

// Function to create/write a file
void writeFile(string filename) {
    ofstream outFile(filename); 
    string line;
    cout << "Enter text (type END on a new line to save and exit):" << endl;
    
    while (true) {
        getline(cin, line);
        if (line == "END") break;
        outFile << line << endl;
    }
    outFile.close();
    cout << "File saved successfully." << endl;
}

// Function to read/display file contents
void readFile(string filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Error: File not found!" << endl;
        return;
    }
    string line;
    cout << "\n--- File Contents ---" << endl;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    cout << "---------------------" << endl;
    inFile.close();
}

// Function to append text to an existing file
void appendFile(string filename) {
    ofstream outFile(filename, ios::app); 
    string line;
    cout << "Enter text to append (type END on a new line to save and exit):" << endl;
    
    while (true) {
        getline(cin, line);
        if (line == "END") break;
        outFile << line << endl;
    }
    outFile.close();
    cout << "Content appended successfully." << endl;
}