#include <iostream>
#include <vector>
using namespace std;

void printHeap(vector<int>& heap) {
    for (int i = 1; i < heap.size(); ++i) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

