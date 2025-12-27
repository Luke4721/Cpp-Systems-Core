#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

int main() {
    const int N = 100'000'000;
    vector<int> arr(N);

    auto start = chrono::high_resolution_clock::now();

    for(int i = 0; i < N; i++) {
        arr[i] += 1;
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "Time taken: " << duration.count() << " seconds\n";

    return 0;
}
