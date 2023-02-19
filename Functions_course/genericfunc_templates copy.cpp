#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
}

int main() {
    stringstream ss("23,4,56");
    char ch;
    int a, b, c;
    ss >> a >> ch >> b >> ch >> c;  // a = 23, b = 4, c = 56
    return 0;
}