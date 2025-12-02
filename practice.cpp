#include <iostream>
#include <stdio.h>
#include <bitset>
using namespace std;
int my_abs(int a);
int main()
{
    int x{};
    cin>>x;
    cout<<x<<endl;
    cout<<"Bit value: "<<bitset<4>(x)<<endl;
    x= my_abs(x);
    cout<<x<<endl;
    cout<<"Bit value: "<<bitset<4>(x)<<endl;
    return 0;
}
int my_abs(int a)
{
    unsigned int oddMask = 0XAAAAAAAA;
    unsigned int evenMask = 0X55555555;
    unsigned int result = ((a & oddMask) >> 1) | ((a & evenMask) << 1);
    return result;
}