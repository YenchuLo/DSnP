#include <iostream>
using namespace std;

class C {
    public:
        void printAddr() const {
            cout << "Address of _a: " << &_a << endl;
            cout << "Address of _b: " << &_b << endl;
        }
    private:
        int _a;
        int _b;
};

int main() {
    C c1, c2;
    c1.printAddr();
    cout << "Address of c1: " << &c1 << endl;
    cout << endl;
    c2.printAddr();
    cout << "Address of c2: " << &c2 << endl;
    return 0;
}