#include <iostream>
#include<stdio.h>
#include <bitset>
using namespace std;

int main()
{
    const int read{4};
    const int write{2};
    const int exec{1};
    int my_permissions = read | write ;
    cout << "My permissions are: " << my_permissions << endl;
    if(my_permissions & exec)
    {
        cout << "I can exec" << endl;
    }
    else
    {
        cout<< "I cant exec"<<endl;
    }

    
    return 0;
}