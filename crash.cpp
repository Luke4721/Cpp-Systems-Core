#include <iostream>
#include <stdio.h>

using namespace std;
void CauseCrash()
{
    int *ptr = nullptr;
    *ptr = 10;
}
int main()
{
    cout<<"About to Crash";
    CauseCrash();
    return 0;
}