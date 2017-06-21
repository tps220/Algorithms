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
        firstHalf[i] = map[i + lower];
    }
    for (i = 0; i < arr2; i++) {
        secondHalf[i] = map[middle + 1 + i];
    }

    i = 0;
    j = 0;
    k = 0;
    while (j < arr1 && k < arr2) {
        if (firstHalf[j] <= secondHalf[k]) {
            map[i + lower] = firstHalf[j];
            j++;
        }
        else {
            map[i + lower] = secondHalf[k];
            k++;
        }
        i++;
    }

    while (j < arr1) {
        map[i + lower] = firstHalf[j];
        j++;
        i++;
    }
    while (k < arr2) {
        map[i + lower] = secondHalf[k];
        k++;
        i++;
    }
    delete [] firstHalf;
    delete [] secondHalf;
};


void mergeSort(vector<string> &map, int lower, int higher) {
    if (higher > lower) {
        int middle = lower + (higher - lower) / 2;
        mergeSort(map, lower, middle);
        mergeSort(map, middle + 1, higher);
        merge(map, lower, middle, higher);
    }
};






int main() {

    clock_t time = clock();


    vector<string> nameList;
    nameList.push_back("");

    ifstream file("/Users/tsalemy/Desktop/Debug/en.lproj/problem22.txt");
    if ( file.is_open() ) {
        int count = 0;
        char ch;
        while (file >> ch) {
            if (ch == 44) {
                count++;
                nameList.push_back("");
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
    long long SUM = 0;
    for (int i = 0; i < nameList.size(); i++) {
        int temp = 0;
        for (int k = 0; k < nameList[i].size(); k++) {
            temp += nameList[i][k] - 64;
        }
        SUM += temp * (i + 1);
    }

    cout << "Answer: " << SUM << endl;
    cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;
    return 0;
};
