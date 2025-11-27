#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

/*************  ✨ Windsurf Command 🌟  *************/
/**
 * @brief Test the latency of stack and heap allocations
 * 
 * This test program measures the time taken to perform 10 million stack and heap allocations
 * 
 * @return int Return 0 if successful
 */
int main()
{
    const int ITERATIONS {1000000}; //10 Million Ops
    cout<<"Starting Latency Test"<<endl;
    auto startStack = chrono::high_resolution_clock::now();
    volatile int stackVal {0};
    //Perform 10 million stack allocations
    for(int i=0; i<ITERATIONS; i++)
    {
        int x {10};
        stackVal = x;
    }
    auto endStack{chrono::high_resolution_clock::now()};
    auto startHeap{chrono::high_resolution_clock::now()};
    //Perform 10 million heap allocations
    for(int i=0; i<ITERATIONS; i++)
    {
        int *y = new int(10);
        *y = 10;
        delete y;
    }
    auto endHeap {chrono::high_resolution_clock::now()};

    auto stackTime{chrono::duration_cast<::chrono::milliseconds>(endStack - startStack)};
    auto heapTime{chrono::duration_cast<::chrono::milliseconds>(endHeap - startHeap)};
    cout<<"Stack Latency: "<<stackTime.count()<<"ms"<<endl;
    cout<<"Heap Latency: "<<heapTime.count()<<"ms"<<endl;
    return 0;
}