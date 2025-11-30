#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int x{1};
    int flags{0};
    x = x<<4;
    flags^=x;
    cout<<(flags)<<endl;
    flags^=x;
    cout<<flags<<endl;
    return 0;
}