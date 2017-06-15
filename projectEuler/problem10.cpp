//
//  problem10.cpp
//  
//
//  Created by Thomas Salemy on 6/13/17.
//
//

#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;


//Take advantage of a sieve. Although this costs a lot of memory, it optimizes performace. Another decision every computer scientist has to make at some point.

int main() {
    
    clock_t time = clock();
    int MAX = 2000000;
    int factorBound = sqrt(MAX) + 1;
    long sum = 0;
    bool sieve[2000000] = { 0 };
    
    
    for (int i = 2; i < factorBound; i++) {
        if (!sieve[i]) {
            sum += i;
            for (int j = i * 2; j < MAX; j += i) {
                sieve[j] = true;
            }
        }
    }
    for (int i = factorBound; i < MAX; i++) {
        if (!sieve[i]) {
           sum += i;
        }
    }
    cout << "Answer: " << sum << endl << "Time: " << (clock() - time ) / (double) CLOCKS_PER_SEC << endl;
    return 0;
};
