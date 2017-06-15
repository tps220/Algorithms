//
//  problem9.cpp
//  
//
//  Created by Thomas Salemy on 6/13/17.
//
//

#include <iostream>
using namespace std;

//Needs to be optimized
bool isPythagorean(int a, int b, int c) {
    return a * a + b * b == c * c;
};

int main() {
    for (int i = 3; i < 1000; i++) {
        for (int j = 3; j < 1000; j++) {
            for (int k = 3; k < 1000; k++) {
                if (isPythagorean(i, j, k) ) {
                    if ( i + j + k == 1000) {
                        cout << i * j * k << endl;
                        return 1;
                    }
                }
            }
        }
    }
    return 1;
};
