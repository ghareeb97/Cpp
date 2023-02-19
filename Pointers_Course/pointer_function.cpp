#include <iostream>
using namespace std;

int add(int a, int b){
    return a + b;
}

int main(){

    int (*funcPtr)(int, int) = add;
    cout << add(2, 3) << endl;
    cout << funcPtr(3, 4) << endl;
}