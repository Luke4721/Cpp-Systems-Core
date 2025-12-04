#include <iostream>
#include <stdio.h>
#include <bitset>

using namespace std;
char heap[10240];
int heapOffset{0};
void* MyMalloc(size_t size);
void MyFree(void* ptr);
struct BlockHeader
{
    size_t size;
    bool is_free;
};
int main()
{
    int x{0};
    double y{0};
    void* ptr1 = (void*)MyMalloc(sizeof(x));
    cout<<ptr1;
    void* ptr2 = (void*)MyMalloc(sizeof(y));
    cout<<ptr2;
    MyFree(ptr1);
    MyFree(ptr2);
}

void* MyMalloc(size_t size)
{
    //Implementing an implicit list
    size_t total_size{size+sizeof(BlockHeader)};
    //Check for OOM {if the current offset is going out of the available(in this case allocated) space}
    if(heapOffset + total_size > 10240)
    {
        heapOffset = 0;
        cout<<"OOM"<<endl;
        return nullptr;  
    }
    //Creating a new pointer to the new block
    BlockHeader* header = (BlockHeader*)&heap[heapOffset];
    //setting the size of the header and the is_free flag
    header->size = total_size;
    header->is_free = false;
    //adjusting the heapOffset
    heapOffset += total_size;
    //returning the pointer value
    return (void*)(header+1);
}
void MyFree(void* ptr)
{
    //Moving the pointer backwards to find the header
    BlockHeader* header = (BlockHeader*)(char*)(ptr- sizeof(BlockHeader));
    //setting the is_free flag
    header->is_free = true;
    cout<<"Freed block. Size = "<<header->size<<endl;
}