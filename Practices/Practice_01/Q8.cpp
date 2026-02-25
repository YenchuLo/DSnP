#include <iostream>
using namespace std;

class C {
    public:
    C(int a = 0, int b = 0) : _a(a), _b(b) {}
        void printData() const {
            cout << "Content of _a: " << _a << endl;
            cout << "Content of _b: " << _b << endl;
        } 
        void printAddr() const {
            cout << "Address of _a: " << &_a << endl;
            cout << "Address of _b: " << &_b << endl;
        }
    private:
        int _a;
        int _b;
};

int main() {
    C c1(10, 20), c2; // default constructor will be called for c2
    c1.printData();
    c1.printAddr();
    cout << "Address of c1: " << &c1 << endl;
    cout << endl;
    c2.printData();
    c2.printAddr();
    cout << "Address of c2: " << &c2 << endl;
    return 0;
}