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
    int x{16};
    double y{16};
    void* ptr1 = (void*)MyMalloc(sizeof(x));
    cout<<ptr1;
    void* ptr2 = (void*)MyMalloc(sizeof(y));
    cout<<ptr2;
    MyFree(ptr2);
    MyFree(ptr1);
}

void* MyMalloc(size_t size)
{
    //Implementing an implicit list
    size_t total_size{size+sizeof(BlockHeader)+sizeof(BlockHeader)};
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
    //adding footer to the block to implement the Go-Back funcitonality
    BlockHeader* footer = (BlockHeader*)((char*)header+total_size-sizeof(BlockHeader));
    footer->size = total_size;
    footer->is_free = false;
    cout<<footer->size<<endl;
    //adjusting the heapOffset
    heapOffset += total_size;
    //returning the pointer value
    return (void*)(header+1);
}
void MyFree(void* ptr)
{
    if(!ptr) return;
    //Moving the pointer backwards to find the header
    BlockHeader* header = (BlockHeader*)((char*)ptr - sizeof(BlockHeader));
    //setting the is_free flag
    header->is_free = true;
    //Moving the pointer backwards to find the footer
    BlockHeader* footer = (BlockHeader*)((char*)header+header->size-sizeof(BlockHeader));
    //setting the is_free flag
    footer ->is_free = true;
    //updating the footer size
    footer->size = header->size;
    //---COALESC RIGHT (Merge with Next Block)---
    //Finding the next header.(It is exactly at (Current Header + Current Size))
    BlockHeader* nextHeader = (BlockHeader*)((char*)header+header->size);
    //Checking if the next block is in heap range
    if((char*)nextHeader < heap+10240)
    {
        //Checking if the next block is free
        if(nextHeader->is_free)
        {
            cout<<"Merging Right with blocks of size "<<nextHeader->size<<endl;
            //Updating the current header size
            header->size += nextHeader->size;
            //Updating the current footer size
            footer = (BlockHeader*)((char*)header+header->size-sizeof(BlockHeader));
        }
    cout<<"Freed block. Size = "<<header->size<<endl;
}
}