#include <iostream>
#include <memory>

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

struct Node {
    int data;
    //Instead of 'Node* next' use unique_ptr,
    //This means : "I own the next node. If I die, it dies."
    unique_ptr<Node> next;

    //Constructor
    Node(int value) : data(value) {
        cout<<"Node("<<data<<") Created";    
    }
    //Destructor
    ~Node() {
        cout<<"Node("<<data<<") Destroyed";
    }
};
int main() {
    {
        cout<<"-----Start of Scope-----"<<endl;
        unique_ptr<Node> head = make_unique<Node>(10);
        head->next = make_unique<Node>(2);
        head->next->next = make_unique<Node>(3);
        auto p1 = make_shared<Node>(999);
        {
        shared_ptr p2 = p1;
        cout<<"Inside the inner scope, p1 is shared with p2"<<endl;
        cout<<"Reference count :"<<p1.use_count()<<endl;
        }
        cout<<"Reference count out of the inner scope :"<<p1.use_count()<<endl;
        cout<<"-----End of Scope-----"<<endl;
    }
        NaiveArray a(10); // Allocates memory
        cout<<"----Moving a to b----"<<endl;
        NaiveArray b = move(a);
        cout<<"-----End of Scope-----"<<endl;
        
    return 0;
    }