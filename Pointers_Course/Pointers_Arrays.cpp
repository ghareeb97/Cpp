#include <iostream>
using namespace std;

int main()
{
    int luckyNumbers[5];
    // cout << luckyNumbers << endl; // This will print the address of the first index
    // cout << &luckyNumbers[0] << endl; // to prove the above line
    // cout << luckyNumbers[2] << endl; // print the value
    // cout << *(luckyNumbers+2) << endl; // print the value using dereferencing

    for (int i = 0; i <= 4; i++){
        cout << "Number:";
        cin >> luckyNumbers[i];
    }

    for (int i = 0; i <= 5; i++){ // This will result in accessing a wrong memory as we only have 4 nums not 5
        cout << *(luckyNumbers+i)<<"  ";
    }
        return 0;
}