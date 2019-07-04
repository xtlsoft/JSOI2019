#include <iostream>
#define dumpAB() cout << a << " " << b << endl;

using namespace std;

int main() {

    // Test reference

    int a = 0;
    int &b = a;

    dumpAB();

    a = 10;

    dumpAB();

    b = 20;
    dumpAB();

    int c = 5;
    a = c;
    dumpAB();

}