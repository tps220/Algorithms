#include "HeapSort.hpp"

//Driving Methods
void HeapSort::heapSort(vector<int> &arr) {
    if (arr.size() < 2) {
        return;
    }
    buildMaxHeap(arr);
    int len = arr.size();
    for (int i = len - 1; i >= 1; i--) {
        swap(arr[0], arr[i]);
        len--;
        maxHeapify(arr, 0, len);
    }
}

void HeapSort::buildMaxHeap(vector<int> &arr) {
    const int len = arr.size();
    for (int i = len / 2; i >= 0; i--) {
        maxHeapify(arr, i, len);
    }
}

void HeapSort::maxHeapify(vector<int> &arr, const int idx, const int len) {
    if (hasLeft(idx, len) == false) {
        return;
    }
    int larger = idx;
    int left = getLeft(idx);
    int right = getRight(idx);
    if (arr[left] > arr[larger]) {
        larger = left;
    }
    if (hasRight(idx, len) && arr[right] > arr[larger]) {
        larger = right;
    }
    if (larger != idx) {
        swap(arr[idx], arr[larger]);
        maxHeapify(arr, larger, len);
    }
}


//Helper Methods
int HeapSort::getLeft(const int idx) {
    return 2 * idx + 1;
}

int HeapSort::getRight(const int idx) {
    return 2 * idx + 2;
}

bool HeapSort::hasLeft(const int idx, const int len) {
    return getLeft(idx) < len;
}

bool HeapSort::hasRight(const int idx, const int len) {
    return getRight(idx) < len;
}

void HeapSort::swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
