#include <iostream>
#include <vector>
using namespace std;

class Inversions {
public:
    int getInversions(vector<int> arr) {
        int retval = mergeSort(arr, 0, arr.size() - 1);
        return retval;
    }
private:
    int mergeSort(vector<int>& arr, int l, int r) {
        if (l < r) {
            int mid = (l + r) / 2, inversions = 0;
            inversions += mergeSort(arr, l, mid);
            inversions += mergeSort(arr, mid + 1, r);
            inversions += merge(arr, l, mid, r);
            return inversions;
        }
        return 0;
    }
    int merge(vector<int>& arr, int l, int m, int r) {
        vector<int> left, right;
        for (int counter = l; counter <= m; counter++) {
            left.push_back(arr[counter]);
        }

        for (int counter = m + 1; counter <= r; counter++) {
            right.push_back(arr[counter]);
        }

        for (int i : left) {
            cout << i << endl;
        }
        cout << endl << endl;
        for (int i : right) {
            cout << i << endl;
        }
        cout << endl << endl;

        int i = 0, j = 0, inversions = 0;
        for (int counter = l; counter <= r; counter++) {
            if (i == left.size()) {
                arr[counter] = right[j];
                j++;
            }
            else if (j == right.size()) {
                arr[counter] = left[i];
                i++;
            }
            else if (right[j] < left[i]) {
                arr[counter] = right[j];
                j++;
                inversions++;
            }
            else {
                arr[counter] = left[i];
                i++;
            }
            cout << arr[counter] << endl;
        }
        return inversions;
    }
};


int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "Invalid command line arguments" << endl;
        return 1;
    }

    vector<int> arr;
    int current_num = 0, i = 0;
    while (argv[1][i] != '\0') {
        if (argv[1][i] == ',') {
            arr.push_back(current_num);
            current_num = 0;
        }
        else {
            current_num = current_num * 10 + argv[1][i] - '0';
        }
        i++;
    }
    arr.push_back(current_num);
    
    Inversions inversion;

    cout << inversion.getInversions(arr) << endl;
    return 0;
}
