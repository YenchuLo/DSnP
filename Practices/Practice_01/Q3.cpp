#include <iostream>
using namespace std;
int main() {
    int a;
    int *p;

    cout << "Address of a: " << &a << endl;
    cout << "Address of p: " << &p << endl;

    p = &a;
    cout << "Address of a: " << &a << endl;
    cout << "Address of p: " << &p << endl;

    cout << "Content of &a: " << *(&a) << endl;
    cout << "Content of &p: " << *(&p) << endl;
    
    return 0;
}