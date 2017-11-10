//Thomas Salemy
//Project Euler Solutions
//Problem 13: Large Sum
//Question: Work out the first ten digits of the sum of the 
//following one-hundred 50-digit numbers

#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;


int main() {
    clock_t time = clock();
    
    int numberMap[100][50];
    ifstream file("problem13.txt");
    if (!file.is_open()) {
        cerr << "File could not be opened" << endl;
    }
    
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
    file.close();    
    //Implement long addition, but with coding
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

    //Print out first ten numbers of the sum
    cout << "Answer: ";
    for (int i = 0; i < 9; i++) {
        cout << sum[i];
    }
    cout << endl << "Time: " << (clock() - time) / (double) CLOCKS_PER_SEC << endl;
    
    return 0;
}
