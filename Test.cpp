#include <iostream>
#include<cstdlib>

using namespace std;


int main()
{
    int var = 1;
    int foo = 10;

    int* p;
    int& k = foo;
    cout << var << "\n";
    cout << foo << "\n";
    cout << &var << "\n";
    cout << &foo << "\n";
    cout << p << "\n";
    p = &foo;
    cout << p << "\n";
    cout << *p << "\n";
    cout << k << "\n";


    cout << "\n\n\n";

    for (unsigned c = 0;c < 10;c++) {
        cout << c << "\n";
    }
    cout << "\n\n\n";
    for (unsigned c = 0;c < 10;++c) {
        cout << c << "\n";
    }

    cout << rand() << "\n";
    cout << RAND_MAX << "\n";
    return 1;
}