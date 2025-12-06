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
    NaiveArray(NaiveArray&& other) noexcept
    {
        ptr = other.ptr;
        other.ptr = nullptr;
        cout<<"Moved!!"<<endl;
    }
    NaiveArray& operator=(NaiveArray&& other) noexcept
    {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
            cout<<"Moved!!"<<endl;
        }
        return *this;
    }
};

int main() {
    {
        NaiveArray a(10); // Allocates memory
        cout<<"----Moving a to b----"<<endl;
        NaiveArray b = move(a);
        cout<<"-----End of Scope-----"<<endl;
        
    } 
    // End of scope:
    
    return 0;
}