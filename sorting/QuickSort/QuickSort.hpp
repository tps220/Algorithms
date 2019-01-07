#include <iostream>
#include <vector>
using namespace std;

class QuickSort {
public:
    void quickSort(vector<int>& arr) {
        if (arr.size() < 2) {
            return;
        }
        quickSortHelper(arr, 0, arr.size() - 1);
    }
private:
    void quickSortHelper(vector<int> &arr, int l, int r) {
        //divide and conquer until we reach a subarray of size 1
        if (l < r) {
            int pivot = partition(arr, l, r);
            quickSortHelper(arr, l, pivot - 1);
            quickSortHelper(arr, pivot + 1, r);
        }
    }
    int partition(vector<int>& arr, const int l, const int r) {
        //choose a pivot element
        int pivot = arr[r];
        int i = l - 1;
        for (int j = l; j <= r - 1; j++) {
            if (arr[j] >= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[r]);
        return i + 1;
    }
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
};
