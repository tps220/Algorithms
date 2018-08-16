#include "QuickSort.hpp"
#include <vector>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define SIZE 100

int main(int argc, char** argv) {
    vector<int> arr;
    srand(1000);
    for (int i = 0; i < SIZE; i++) {
        arr.push_back(rand() % (SIZE * 4));
    }
    QuickSort sorter;
    sorter.quickSort(arr);
    for (int i = 0; i < SIZE - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            cout << "FAILED" << endl;
            return 1;
        }
    }
    cout << "PASSED" << endl;
    return 0;
}
