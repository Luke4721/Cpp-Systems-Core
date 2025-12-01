#include <iostream>
#include <stdio.h>

using namespace std;
void Spy(int depth);
int main()
{
    Spy(1);
    return 0;
}

void Spy(int depth)
{
    if(depth%1000==0)
    {
        cout<<"Depth: "<<depth<<endl;
    }
    int x{depth};
    cout<<x<<endl;
    cout<<&x<<endl;
    Spy(depth+1);
}