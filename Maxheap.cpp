#include <iostream>
#include <vector>
using namespace std;

void printHeap(vector<int>& heap) {
    for (int i = 1; i < heap.size(); ++i) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

void buildMaxHeapTopDown(vector<int>& heap) {
    for (int i = 2; i < heap.size(); ++i) {
        int current = i;
        while (current > 1 && heap[current] > heap[current / 2])
        {
            swap(heap[current], heap[current / 2]);
            current /= 2;
        }
        
    }
}



