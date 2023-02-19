#include <iostream>
using namespace std;

int main()
{
    int size;
    cout << "Enter the size:";
    cin >> size;
    // int myArray[size]; // Variable length arrays are not approved by C++ standards but compile with gcc
    // Alternative way is to use dynamic arrays and dynamic memory.
    int* myArray = new int[size]; // dynamic array using pointer and "new" --> to allocate memory

    for (int i = 0; i < size;i++){
        cout << "Array[" << i << "] ";
        cin >> myArray[i];
    }

    for (int i = 0; i < size;i++){
        // cout << myArray[i] << "  ";
        cout << *(myArray+i) << "  "; // same as above just differnet way to write
    }

    delete[]myArray; // deallocate memory
    myArray = NULL; // remove the pointer to avoid getting a wrong address and causing bugs 
}