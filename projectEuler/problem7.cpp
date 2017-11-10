//Thomas Salemy
//Project Euler Solutions
//Problem 7: 10001st Prime
//Question: What is the 10001st prime 

#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;

//Implement a prime sieve that checks count dynamically
//to find solution quickly
int main() {
    clock_t time = clock();
    bool *map = new bool[200000]();

    int count = 0;
    for (int i = 3; i < 200000; i += 2) {
        if (!map[i]) {
            for (int j = i * 2; j < 200000; j+= i) {
                map[j] = true;
            }
            count++;
        }
        if (count == 10000) {
            cout << "Answer: " << i << endl;
            break;
        }
    }

    cout << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;
    delete [] map;
    return 0;
};
