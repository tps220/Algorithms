#include "HeapSort.hpp"
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

#define SIZE 100000

int main(int argc, char** argv) {
    //create random input
    vector<int> arr;
    srand(2400);
    for (int i = 0; i < SIZE; i++) {
        arr.push_back(rand() % (SIZE * 4));
    }
    //apply heap sort
    HeapSort sorter;
    sorter.heapSort(arr);
    //check validity
    for (int i = 0; i < SIZE - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            cout << "FAILED" << endl;
            return 1;
        }
    }
    cout << "PASSED" << endl;
    return 0;
}

