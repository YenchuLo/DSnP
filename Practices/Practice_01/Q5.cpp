#include <iostream>
using namespace std;

class C{
    public:
        int num[6];
    private:
};

static_assert(sizeof(C) == 24, "Size of class C should be 24 bytes");

int main() {
    C x, y, z;
    cout << "Address of x: " << &x << endl;
    cout << "Address of y: " << &y << endl;
    cout << "Address of z: " << &z << endl;
    cout << "num[0] of x: " << x.num[0] << endl;
    cout << "num[0] of y: " << y.num[0] << endl;
    cout << "num[0] of z: " << z.num[0] << endl;

    int *a1 = new int;
    int *a2 = new int;
    C *c1 = new C;
    C *c2 = new C;
    C *c3 = new C;

    cout << "Address of a1: " << &(*a1) << endl;
    cout << "Address of a2: " << &(*a2) << endl;
    cout << "Address of c1: " << &(*c1) << endl;
    cout << "Address of c2: " << &(*c2) << endl;
    cout << "Address of c3: " << &(*c3) << endl;
    cout << "Content of a1: " << *a1 << endl;
    cout << "Content of a2: " << *a2 << endl;

    cout << "num[0] of c1: " << (*c1).num[0] << endl;
    cout << "num[0] of c2: " << (*c2).num[0] << endl;
    cout << "num[0] of c3: " << (*c3).num[0] << endl;

    delete a1;
    delete a2;
    delete c1;
    delete c2;
    delete c3;

    return 0;
}