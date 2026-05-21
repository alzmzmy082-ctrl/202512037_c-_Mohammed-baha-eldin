#include <iostream>
using namespace std;

int main()
{
    // 2D Array with 4 rows and 3 columns as shown in your sheet
    int rollNumbers[4][3] = { {1, 1, 1}, {2, 2, 2}, {3, 3, 3}, {4, 4, 4} };
    
    // Nested loops to print the array elements
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            cout << rollNumbers[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
