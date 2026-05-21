#include <iostream>
#include <string>

using namespace std;

// Simple global variables just like the ones used in class
int myBalance = 0;
string myHistory[50];
int myCounter = 0;
int myPin = 12345;

// 1. Simple function to check balance
void showMyBalance() {
    cout << "\nYour Balance is: " << myBalance << " FRW" << endl;
}

// 2. Simple function to deposit money
void doDeposit() {
    int amount;
    cout << "\nEnter amount to deposit: ";
    cin >> amount;
    
    if (amount > 0) {
        myBalance = myBalance + amount;
        cout << "Deposit Successful!" << endl;
        
        // Save to history array
        myHistory[myCounter] = "Deposited: " + to_string(amount) + " FRW";
        myCounter++;
    }
}

// 3. Simple function to withdraw money
void doWithdraw() {
    int amount;
    cout << "\nEnter amount to withdraw: ";
    cin >> amount;
    
    if (amount > myBalance) {
        cout << "Error: No enough money!" << endl;
    } else {
        myBalance = myBalance - amount;
        cout << "Withdraw Successful!" << endl;
        
        // Save to history array
        myHistory[myCounter] = "Withdrew: " + to_string(amount) + " FRW";
        myCounter++;
    }
}

// 4. Simple function to print history using a for loop
void showMyHistory() {
    cout << "\n--- Your Transactions ---" << endl;
    if (myCounter == 0) {
        cout << "No history found." << endl;
    } else {
        for (int i = 0; i < myCounter; i++) {
            cout << i + 1 << ". " << myHistory[i] << endl;
        }
    }
}

int main() {
    int inputPin;
    int tries = 3;
    bool loggedIn = false;
    
    // PIN Authentication system
    while (tries > 0) {
        cout << "Enter PIN code: ";
        cin >> inputPin;
        
        if (inputPin == myPin) {
            cout << "Login Success!" << endl;
            loggedIn = true;
            break;
        } else {
            tries--;
            cout << "Wrong PIN. Remaining tries: " << tries << endl;
        }
    }
    
    if (loggedIn == false) {
        cout << "ATM Blocked!" << endl;
        return 0; 
    }
    
    // Main Menu Loop with Switch-Case
    int choice;
    do {
        cout << "\n=== ATM MENU ===" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. History" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                showMyBalance(); 
                break;
            case 2:
                doDeposit(); 
                break;
            case 3:
                doWithdraw(); 
                break;
            case 4:
                showMyHistory(); 
                break;
            case 5:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice, try again." << endl;
        }
    } while (choice != 5);
    
    return 0;
}
