//
//  problem8.cpp
//  
//
//  Created by Thomas Salemy on 6/13/17.
//
//

#include <iostream>
#include <fstream>
#include "time.h"
using namespace std;

//The only solution I can think of for this one is to calculate the product of each 13 digit sequence,
//and if there's a zero immediately exit the loop for that sequence to maximize time while maintaining
//100% confidence the solution is correct

int main() {

    clock_t time = clock();
    ifstream file("problem8.txt");
    int numberMap[1000];
    if ( file.is_open() ) {
        char ch;
        int index = 0;
        
        while (file >> ch) {
            int i = ch - 48;
            numberMap[index] = i;
            index++;
        }
        file.close();
        
        long max = 0;
        for (int i = 0; i < 987; i++) {
            long product = 1;
            for (int counter = i; counter < i + 13; counter++) {
                if (numberMap[counter] == 0) {
                    break;
                }
                product *= numberMap[counter];
            }
            if (product > max) {
                max = product;
            }
        }
        cout << max << endl;
    }
    else {
        cout << "file not found" << endl;
    }
    cout << (clock() - time) / (double) CLOCKS_PER_SEC << endl;
    return 0;
}
