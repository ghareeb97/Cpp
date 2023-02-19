#include <iostream>
using namespace std;

int main()
{
/*PASS BY VALUE EXAMPLES*/
    int n = 5;
    cout << &n << endl; //printing address
    int* ptr = &n; // (Referencing) creating a pointer that stores an address
    cout << ptr << endl; //printing address
    cout << *ptr << endl; //(Dereferencing) printing Value
    *ptr = 10; // (Dereferencing) to change the value
    cout << *ptr << endl; // to check that the value has changed
    cout << n << endl; // to check that this will affect the variable n

/*the following 2 lines will create an error 
as you cannot create a pointer without pointing/storing to an address */
    // int *ptr2; 
    // *ptr2 = 7;
    
    int v;
    int *ptr2 =&v;
    *ptr2 = 7;
    cout << "v=" << v << endl;
}