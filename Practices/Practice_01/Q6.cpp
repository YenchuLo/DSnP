#include <iostream>
using namespace std;

void f() {
    int a, b, c;

    cout << "Address of a: " << &a << endl;
    cout << "Address of b: " << &b << endl;
    cout << "Address of c: " << &c << endl;

    int *p = new int;
    int *q = new int;

}

int main() {
    f();
    f();
    f();
    return 0;
}