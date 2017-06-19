#include <iostream>
#include <time.h>
#include <fstream>
#include <vector>
#include <stdlib.h>
using namespace std;


void merge(vector<string> &map, int lower, int middle, int higher) {
    int arr1 = middle - lower + 1;
    int arr2 = higher - middle;
    string* firstHalf = new string[arr1];
    string* secondHalf = new string[arr2];

    int i, j, k;

    for (i = 0; i < arr1; i++) {
        firstHalf[i] = map[i];
    }
    for (i = 0; i < arr2; i++) {
        secondHalf[i] = map[middle + 1 + i];
    }

    i = 0;
    j = 0;
    k = 0;
    while (j < arr1 && k < arr2) {
        if (firstHalf[j][0] < secondHalf[k][0]) {
            map[i] = firstHalf[j];
            j++;
        }
        else {
            map[i] = secondHalf[k];
            k++;
        }
        i++;
    }

    while (j < arr1) {
        map[i] = firstHalf[j];
        j++;
        i++;
    }
    while (k < arr2) {
        map[i] = secondHalf[k];
        k++;
        i++;
    }

    delete [] firstHalf;
    delete [] secondHalf;
};


void mergeSort(vector<string> &map, int lower, int higher) {
    if (higher > lower) {
        int middle = (lower + higher) / 2;
        mergeSort(map, lower, middle);
        mergeSort(map, middle + 1, higher);
        merge(map, lower, middle, higher);
    }
};






int main() {
    vector<string> nameList;
    ifstream file("problem22.txt");
    if ( file.is_open() ) {
        int count = 0;
        char ch;
        while (file >> ch) {
            if (ch == 44) {
                count++;
            }
            else if (ch != 34) {
                nameList[count] += ch;
            }
        }
        mergeSort(nameList, 0, (int)nameList.size() - 1);
    }
    else {
        cout << "File not found" << endl;
    }
    for (int i = 0; i < 40; i++) {
        cout << nameList[i] << endl;
    }
    return 0;
};
