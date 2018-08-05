#include <iostream>
#include <vector>
using namespace std;

class HeapSort {
public:
    void heapSort(vector<int>&);
private:
    void buildMaxHeap(vector<int>&);
    void maxHeapify(vector<int>&, const int, const int);
    int getLeft(const int);
    int getRight(const int);
    bool hasLeft(const int, const int);
    bool hasRight(const int, const int);
    void swap(int&, int&);
};

