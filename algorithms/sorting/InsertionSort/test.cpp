#include <iostream>
#include <vector>
#include "InsertionSort.hpp"
using namespace std;

int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "Invalid command line arguments" << endl;
        return 1;
    }
    vector<int> test;
    int current_num = 0;
    int i = 0;
    while (argv[1][i] != '\0') {
        if (argv[1][i] == ',') {
            test.push_back(current_num);
            current_num = 0;
        }
        else {
            current_num = current_num * 10 + argv[1][i] - '0';
        }
        i++;
    }
    test.push_back(current_num);

    InsertionSort sorter;
    sorter.sort(test);
    for (int i = 1; i < test.size(); i++) {
        if (test[i] > test[i -1]) {
            cout << "INVALID, TEST FAILED" << endl;
            return 1;
        }
    }
    cout << "TEST PASSED" << endl;
}
