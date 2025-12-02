#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    unsigned long host{192U<<24|168U<<16|1U<<8|0U};
    bitset<32> hostBit{host};
    cout<<hostBit<<endl;
    unsigned long subnet{(255U<<24)|(255U<<16)|(255U<<8)|0U};
    bitset<32> subnetMask{subnet};
    unsigned int a{192},b{168},c{1},d{5};
    unsigned long packedip{a<<24|b<<16|c<<8|d};
    bitset<32> ip{packedip};
    cout<<(subnetMask&ip)<<endl;
    
    if((subnetMask&ip) == hostBit)
    {
        cout<<"Access Granted"<<endl;
    }
    else
    {
        cout<<"Access Denied"<<endl;
    }
    return 0;


}