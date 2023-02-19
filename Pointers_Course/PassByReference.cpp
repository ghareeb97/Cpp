#include <iostream>
using namespace std;

// functions recieving pointers (address of the variables)
void printNumber(int* numberPtr){
    cout << *numberPtr << endl; // must dereference the address
}
void printLetter(char* charPtr){
    cout << *charPtr << endl;
}
void print(void* ptr, char type){ // void pointer can cause logical error so be careful
    switch(type){
        case 'i':
            cout << *((int *)ptr) << endl; // handle int*
            break;
        case 'c':
            cout << *((char *)ptr) << endl;//handle char*
            break;

    }
}
int main()
{
    int number = 5;
    char letter = 'a';
    // printNumber(&number); // passing the address to function
    // printLetter(&letter);
    print(&number, 'i'); 
    print(&letter, 'c');
    return 0;
}