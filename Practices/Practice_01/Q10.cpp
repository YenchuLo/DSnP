#include <iostream>
using namespace std;

class C;

class B{
    int _bd;
};

class A{
    public:
        void printAddr() {
            cout << "Address of B: " << &_b << endl;
            cout << "Address of C: " << _c << endl;
        }
    //private:
        B _b;
        C *_c;
};

int main() {
    A a;
    a.printAddr();
    cout << "Address of A: " << &a << endl;
    cout << "Content of a._c: " << a._c << endl;
    return 0;
}