#include <iostream>
using namespace std;

class B {
    public:
        B(int bd = 0) : _bd(bd) {}
    private:
        int _bd;
};

class A {
    public:
        A(int ad = 0, int b = 0) : _ad(ad), _b(b) {}
    private:
        int _ad;
        B _b;
};

int main() {
    A a(1, 2);
    return 0;
}