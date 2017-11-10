//Thomas Salemy
//Project Euler Solutions
//Problem 8: Largest Product in a series
//Question: In the given file, find the thirteen adjacent 
//digits in the 1000-digit number that have the greatest product


#include <iostream>
#include <fstream>
#include "time.h"
using namespace std;

//The only solution I can think of for this one is to calculate the product of each 13 digit sequence,
//and if there's a zero immediately exit the loop
int main() {

    clock_t time = clock();
    ifstream file("problem8.txt");
    int *numberMap = new int[1000]();
    if (!file.is_open()) {
        cerr << "File not found" << endl;
        return -1;
    }
    
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
    
    cout << "Answer: " << max << endl;
    cout << (clock() - time) / (double) CLOCKS_PER_SEC << endl;
    
    delete [] numberMap;
    return 0;
}
