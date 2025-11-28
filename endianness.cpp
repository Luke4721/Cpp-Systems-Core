#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int x{1};
    char *cptr {reinterpret_cast<char *>(&x)};
    unsigned char *ucptr{reinterpret_cast<unsigned char *>(&x)};
    cout << "x = " << x << endl;
    cout << "cptr = " << static_cast<int>(*cptr) << endl;
    cout << "ucptr = " << static_cast<int>(*ucptr) << endl;
    if(*ucptr == 1)
    {
        cout << "Little Endian" << endl;
    }
    else
    {
        cout << "Big Endian" << endl;
    }
    return 0;

}