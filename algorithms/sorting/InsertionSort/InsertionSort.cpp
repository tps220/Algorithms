#include <iostream>
#include <vector>
#include "InsertionSort.hpp"
using namespace std;

void InsertionSort::sort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j > 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void InsertionSort::sort(vector<int> &arr, const int s, const int e) {
    for (int i = s + 1; i <= e; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j > s && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
