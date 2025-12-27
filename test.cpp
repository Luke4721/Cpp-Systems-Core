#include <iostream>
using namespace std;

void swap_ptr(int* a, int* b) 
{
    cout<<*a;
}

void swap_ref(int& a, int& b) {
}

int main() {
    int x = 5, y = 10;

    cout << "Before: " << x << " " << y << "\n";
    swap_ptr(&x, &y);
    cout << "After pointer swap: " << x << " " << y << "\n";

    // Reset x, y

    cout << "Before: " << x << " " << y << "\n";
    swap_ref(x, y);
    cout << "After reference swap: " << x << " " << y << "\n";

    return 0;
}
