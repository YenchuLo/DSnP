#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    while (cin >> a >> b) {
        c = a + b;
        cout << "Address of a: " << &a << endl;
        cout << "Address of b: " << &b << endl;
        cout << "Address of c: " << &c << endl << endl;

        cout << "Content of &a: " << *(&a) << endl;
        cout << "Content of &b: " << *(&b) << endl;
        cout << "Content of &c: " << *(&c) << endl << endl;

        a = b + c;
        cout << "Address of a: " << &a << endl;
        cout << "Content of &a: " << *(&a) << endl << endl;

        int* p = &a;
        cout << "Address of p: " << &p << endl;
        cout << "Content of p: " << p << endl << endl;

        *p = c - b; //*p = a
        cout << "Address of a: " << &a << endl;
        cout << "Content of a: " << a << endl;
    }

    return 0;
}