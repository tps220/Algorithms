//
//  problem5.cpp
//
//
//  Created by Thomas Salemy on 6/12/17.
//
//

#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

int power(int a, int b) {
    if (b == 0) {
        return 1;
    }
    else {
        return a * power(a, b - 1);
    }
};


int main() {
    clock_t start = clock();
    vector<int> factorMap;
    //initializes 20 values to zero (this is for all the factors, which are represented by the index
    //of the vector
    factorMap.assign(20, 0);
    
    for (int i = 2; i <= 20; i++) {
        int number = i;
        for (int j = 2; j <= i; j++) {
            int count = 0;
            while (number % j == 0) {
                number /= j;
                count++;
            }
            if (count > factorMap[j]) {
                factorMap[j] = count;
            }
        }
    }
    int finalNumber = 1;
    for (int i = 2; i < factorMap.size(); i++) {
        finalNumber = finalNumber * power(i, factorMap[i]);
    }
    clock_t stop = clock();
    cout << "Number: " << finalNumber << " took " << (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC << endl;
    return 1;
};
