#include <iostream>
using namespace std;

int main()
{
    int rows, cols;
    cout << "rows, cols:";
    cin >> rows >> cols;

    int **table = new int*[rows];
    for (int i = 0; i < rows; i++){
        table[i] = new int[cols];
    }

    table[1][2] = 88;

    for (int i = 0; i < rows; i++){ 
        delete[] table[i]; // deallocate the arrays
    }

    delete[] table; // deallocate the pointers to the arrays
    table = NULL;

    return 0;
}