#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int r{255},g{128},b{50};
    r<<=16;
    g<<=8;

    unsigned int packedColor{r|g|b};
    cout<<packedColor<<endl;
    int extractedGreen{};
    extractedGreen = packedColor>>8;
    cout<<(extractedGreen&0xFF)<<endl;

}