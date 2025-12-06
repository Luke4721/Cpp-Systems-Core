#include <iostream>

using namespace std;
class NaiveArray {
public:
    int* ptr;

    // Constructor: Allocates memory
    NaiveArray(int value) {
        ptr = new int(value);
        cout << "Allocated at: " << ptr << "\n";
    }

    // Destructor: Cleans up
    ~NaiveArray() {
        cout << "Deleting: " << ptr << "\n";
        delete ptr;
    }
    NaiveArray(const NaiveArray& other) {
        ptr = new int{};
        *ptr = *other.ptr;
        cout << "Copied at: " << ptr << "\n";
        cout<<"Deep Copy Created"<<endl;
    }
    NaiveArray& operator=(const NaiveArray& other) {
        if (this != &other) {
            delete ptr;
            ptr = new int{};
            *ptr = *other.ptr;
            cout << "Copied at: " << ptr << "\n";
            cout<<"Deep Copy Created"<<endl;
        }
        return *this;
    }
};

int main() {
    {
        NaiveArray a(10); // Allocates memory
        NaiveArray b = a; // <--- DANGER! Default Copy Constructor runs.
        
        // 'b' is now a CLONE of 'a'.
        // b.ptr and a.ptr are IDENTICAL.
    } 
    // End of scope:
    // 1. 'b' is destroyed. calls delete ptr. (Fine)
    // 2. 'a' is destroyed. calls delete ptr... AGAIN. (CRASH)
    
    return 0;
}