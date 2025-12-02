#include <iostream>
#include <stdio.h>
#include <bitset>

using namespace std;

auto x{bitset<64>(0)};
int add(int x);
bool might_exist(int value);
int main()
{
    add(100);
    return 0;
}

int add(int value)
{
    int position1{value%64};
    int position2{(value*7)%64};
    x.set(position1);
    x.set(position2);
    cout<<"Bit value: "<<x<<endl;
    cout<<"Might exist: "<<might_exist(value)<<endl;
    return 0;

}
bool might_exist(int value)
{
    int position1{value%64};
    int position2{(value*7)%64};
    return x.test(position1) && x.test(position2);
}