//
//  problem7.cpp
//  
//
//  Created by Thomas Salemy on 6/14/17.
//
//

#include <iostream>
#include <time.h>
using namespace std;


int main() {
    clock_t time = clock();
    bool map[200000] = {false};
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
    return 0;
};
