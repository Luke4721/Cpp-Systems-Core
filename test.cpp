#include <iostream>
using namespace std;

struct A {
    char a;   // 1 byte
    int  b;   // 4 bytes
    char c;   // 1 byte
};

struct B {
    int  b;
    char a;
    char c;
};

struct C {
    char a;
    char c;
    int  b;
};

int main() {
    cout << "sizeof(A): " << sizeof(A) << "\n";
    cout << "sizeof(B): " << sizeof(B) << "\n";
    cout << "sizeof(C): " << sizeof(C) << "\n";

    return 0;
}
