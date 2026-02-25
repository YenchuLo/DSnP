#include <iostream>
using namespace std;

int main() {
    int a = 10;
    cout << "Address of a: " << &a << endl;
    cout << "Content of a: " << a << endl;
    cout << endl;

    int arr[10] = {0};
    for (int i = 0; i < 10; ++i) {
        cout << "Address of arr[" << i << "]: " << &arr[i] << endl;
        cout << "Content of arr[" << i << "]: " << arr[i] << endl;
    }
    cout << endl;

    int *arrP[10];
    for (int i = 0; i < 10; ++i) {
        arrP[i] = &arr[i];
    }

    int *p1 = new int(10);
    int *p2 = new int[10];
    cout << "Address of p2: " << &p2 << endl;
    cout << "Content of p2: " << p2 << endl;
    for (int i = 0; i < 10; ++i) {
        cout << "Address of p2[" << i << "]: " << &p2[i] << endl;
        cout << "Content of p2[" << i << "]: " << p2[i] << endl;
    }
    cout << endl;
    int **p3 = new int*;
    *p3 = new int(20);
    cout << "Address of p3: " << &p3 << endl;
    cout << "Content of p3: " << p3 << endl;
    cout << "Content of *p3: " << *p3 << endl;
    cout << "Content of **p3: " << **p3 << endl;
    cout << endl;
    int **p4 = new int*[10];
    for (int i = 0; i < 10; ++i) {
        p4[i] = new int(i + 2);
    }
    cout << "Address of p4: " << &p4 << endl;
    cout << "Content of p4: " << p4 << endl;
    for (int i = 0; i < 10; ++i) {
        cout << "Address of p4[" << i << "]: " << &p4[i] << endl;
        cout << "Content of p4[" << i << "]: " << p4[i] << endl;
        cout << "Content of *p4[" << i << "]: " << *p4[i] << endl;
    }
    cout << endl;
    int **p5 = new int*[10];
    for (int i = 0; i < 10; ++i) {
        p5[i] = new int[i + 2];
    }
    cout << "Address of p5: " << &p5 << endl;
    cout << "Content of p5: " << p5 << endl;
    for (int i = 0; i < 10; ++i) {
        cout << "Address of p5[" << i << "]: " << &p5[i] << endl;
        cout << "Content of p5[" << i << "]: " << p5[i] << endl;
        cout << "Content of *p5[" << i << "]: " << *p5[i] << endl;
    }
    return 0;
}