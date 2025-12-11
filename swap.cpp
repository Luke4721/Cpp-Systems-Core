#include <iostream>
#include <string>

using namespace std;
// --- THE BLUEPRINT (Template) ---
// 'template <typename T>' tells C++: 
// "I am about to write a function, but I don't know the type yet.
// Call the type 'T'. When someone uses this function, 
// replace 'T' with whatever they passed in."

template <typename T>
void Swap(T& a, T& b) {
    T temp = a; // 1. Copy 'a' into a temporary variable
    a = b;      // 2. Overwrite 'a' with 'b'
    b = temp;   // 3. Overwrite 'b' with the temp
}

int main() {
    // --- Test 1: Integers ---
    int x = 10;
    int y = 99;
    cout << "Before Int Swap: " << x << ", " << y << "\n";
    
    Swap<int>(x, y); // Explicitly telling the compiler: T = int
    
    cout << "After Int Swap:  " << x << ", " << y << "\n\n";

    // --- Test 2: Floats ---
    float f1 = 1.5f;
    float f2 = 5.5f;
    cout << "Before Float Swap: " << f1 << ", " << f2 << "\n";
    
    Swap(f1, f2); // Implicit: Compiler guesses T = float automatically
    
    cout << "After Float Swap:  " << f1 << ", " << f2 << "\n\n";

    // --- Test 3: Strings ---
    string s1 = "Cyber";
    string s2 = "Security";
    cout << "Before String Swap: " << s1 << " " << s2 << "\n";
    
    Swap(s1, s2); // Implicit: Compiler guesses T = string
    
    cout << "After String Swap:  " << s1 << " " << s2 << "\n";

    return 0;
}