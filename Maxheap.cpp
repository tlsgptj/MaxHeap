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

void heapify(vector<int>& heap, int index, int heapSize) {
    int largest = index;
    int left = 2 * index;
    int right = 2 * index + 1;

    if (left <= heapSize && heap[left] > heap[largest]) largest = left;
    if (right <= heapSize && heap[right] > heap[largest]) largest = right;

    if (largest != index) {
        swap(heap[index], heap[largest]);
        heapify(heap, largest, heapSize);
    }
}

void buildMaxHeapBottomUp(vector<int>& heap) {
    int heapSize = heap.size() - 1;
    for (int i = heapSize / 2; i >= 1; --i) {
        heapify(heap, i, heapSize);
    }
}

void deleteRoot(vector<int>& heap) {
    int heapSize = heap.size() - 1;
    if (heapSize == 0) return;

    swap(heap[1], heap[heapSize]);
    heap.pop_back();
    heapify(heap, 1, heapSize - 1);
}

int main() {
    vector<int> data = {0, 3, 2, 5, 7, 4, 8, 6, 9, 1};

    vector<int> topDownHeap = data;
    buildMaxHeapTopDown(topDownHeap);
    cout << "Top-Down MaxHeap: ";
    printHeap(topDownHeap);

    deleteRoot(topDownHeap);
    cout << "After Root Deletion(Top-Down): ";
    printHeap(topDownHeap);

    vector<int> bottomUpHeap = data;
    buildMaxHeapBottomUp(bottomUpHeap);
    cout << "Bottom-Up MaxHeap: ";
    printHeap(bottomUpHeap);

    deleteRoot(bottomUpHeap);
    cout << "After Root Deletion (Bottom-Up): ";
    printHeap(bottomUpHeap);

    return 0;




}


