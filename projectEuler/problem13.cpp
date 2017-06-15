//
//  problem13.cpp
//  
//
//  Created by Thomas Salemy on 6/14/17.
//
//

#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;


int main() {
    clock_t time = clock();
    
    int numberMap[100][50];
    ifstream file("problem13.txt");
    if (file.is_open() ) {
        int column = 0;
        int row = 0;
        char ch;
        while (file >> ch) {
            if (column == 50) {
                column = 0;
                row++;
            }
            numberMap[row][column] = (int) (ch - 48);
            column++;
        }
    }
    
    int sum[20] = {};
    for (int i = 0; i < 100; i++) {
        for (int j = 10; j >= 0; j--) {
            sum[j + 1] += numberMap[i][j];
            if (sum[j + 1] >= 10) {
                sum[j] += 1;
                sum[j + 1] -= 10;
            }
            
        }
    }
    cout << "Answer: ";
    for (int i = 0; i < 9; i++) {
        cout << sum[i];
    }
    cout << endl << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;
    return 0;
}
