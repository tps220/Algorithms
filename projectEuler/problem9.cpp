//
//  problem9.cpp
//  
//
//  Created by Thomas Salemy on 6/13/17.
//
//Needs to be optimized, have not gotten to this yet and have not found better solution

#include <iostream>
#include "time.h"

using namespace std;

//Needs to be optimized
bool isPythagorean(int a, int b, int c) {
    return a * a + b * b == c * c;
};

int main() {
    clock_t time = clock();
    for (int i = 3; i < 1000; i++) {
        for (int j = 3; j < 1000; j++) {
            for (int k = 3; k < 1000; k++) {
                if (isPythagorean(i, j, k) ) {
                    if ( i + j + k == 1000) {
                        cout << i * j * k << endl;
                        cout << (clock() - time) / (double) CLOCKS_PER_SEC << endl;
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
};
